import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Página principal


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # Obtendo id do usuário
    userId = session["user_id"]
    dadosUser = db.execute("SELECT username, cash FROM users WHERE id = ?", userId)
    username = dadosUser[0]["username"]
    cash = dadosUser[0]["cash"]

    # Verificando se usuário existe no banco de dados
    if not dadosUser:
        return apology("User not found", 400)

    # Buscar todas as ações do usuário, agrupadas por símbolo, somando a quantidade de ações (shares)
    stocks = db.execute("""
        SELECT symbol, SUM(shares) as total_shares
        FROM transactions
        WHERE user_id = ?
        GROUP BY symbol
        HAVING total_shares > 0
    """, userId)

    # Lista para armazenar o portfólio detalhado (ações, preços, totais)
    portfolio = []
    total_value = cash

    # Para cada ação comprada pelo usuário, buscar o preço atual e calcular o total
    for stock in stocks:
        symbol = stock["symbol"]
        shares = stock["total_shares"]

        # Usar função lookup para pegar dados atuais da ação
        quote = lookup(symbol)
        price = quote["price"]
        name = quote["name"]
        total = price * shares
        total_value += total

        # Adicionar essa ação ao portfólio para enviar ao template
        portfolio.append({
            "symbol": symbol,
            "name": name,
            "shares": shares,
            "price": price,
            "total": total
        })

    return render_template("index.html", username=username, cash=cash, portfolio=portfolio, total_value=total_value)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # Formulário com o nome do symbol
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        quantity = request.form.get("shares")

        # Validando simbolo
        if not symbol:
            return apology("must provide Symbol", 403)

        # Validando quantidade
        elif not quantity:
            return apology("must provide quantity", 403)

        # Verifica se shares é um número inteiro positivo
        if not quantity.isdigit() or int(quantity) <= 0:
            return apology("shares must be a positive integer", 400)

        # Verificando se o symbol existe
        stock = lookup(symbol)
        if not stock:
            return apology("invalid symbol", 400)

         # Calcular total da compra
        shares = int(quantity)
        total = stock["price"] * shares

        # Verificar se usuário tem dinheiro para comprar
        userId = session["user_id"]
        cashUser = db.execute("SELECT cash FROM users WHERE id = ?", userId)
        if cashUser[0]["cash"] < total:
            return apology("insufficient money")

        # Adicionar ação ao banco de dados de ações do usuario
        db.execute("""INSERT INTO transactions (user_id, symbol, name, shares, price)
                   VALUES (?, ?, ?, ?, ?)""", userId, stock["symbol"], stock["name"], shares, stock["price"])

        # Atualizar dinheiro do usuario
        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", total, userId)

        # Preciso criar um banco de dados de ações ligado ao user
        return redirect("/")

    else:
        return render_template("buy.html")

    # Criar tabela para acompanhar quantas ações que cada usuario possui
    # id | nome da ação | quantidade | foreingid do user


# Ver o histórico de todas as transações
@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # Tabela com todas as transações anteriores
    # Quais ações foram compradas ou vendidas
    # Quantas de cada ação foi compra ou vendida
    # Quando a transação ocorreu

    # Obtendo id do usuário
    userId = session["user_id"]

    # Acessando as ações compradas
    transactions = db.execute(
        "SELECT symbol, name, shares, price, transacted_at FROM transactions WHERE user_id = ? ORDER BY transacted_at DESC", userId)

    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")

# Cotações de ações


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        # Verificação do symbol
        if not symbol:
            return apology("must provide symbol")

        # Se symbol não existir
        if lookup(symbol) == None:
            return apology("Symbol not existing")
        else:
            quote_data = lookup(symbol)
            name = quote_data["name"]
            price = quote_data["price"]

        # Retornar nome, preço e simbolo da ação em uma página html
        return render_template("quote.html", name=name, symbol=symbol, price=price, show_table=True)

    # GET
    else:
        return render_template("quote.html", show_table=False)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        # Validar os dados
        # Obterndo dados
        username = request.form.get("username")
        password = request.form.get("password")
        confPassword = request.form.get("confirmation")

        # Verificar entrda de nome
        if not username:
            return apology("must provide username", 400)

        # Verificar entrada de senha
        elif not password:
            return apology("must provide password", 400)

        # Verificar entrada de confirmação de senha
        elif not confPassword:
            return apology("must provide password confirmation", 400)

        # Verificar se senha e confirmação de senha são iguais
        elif password != confPassword:
            return apology("password and password confirmation is different", 400)

        # Verificar se nome de usuario ja existe no banco de dados
        if len(db.execute("SELECT username FROM users WHERE username = ?", username)) != 0:
            return apology("This username already exists")

        # Gerando hash para a senha e o armazenamento ser seguro
        hashPassword = generate_password_hash(password)

        # Adicionando ao banco de dados
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hashPassword)

        # Retornando para a página de login
        return redirect("/login")

    # Metodo get, apenas mostrar a página
    else:
        return render_template("register.html")


# Venda de ações
@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if request.method == "POST":
        # Recebendo nome e quantidade da ação
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")

        # Validando inputs
        if not symbol:
            return apology("must provide symbol", 403)

        elif not shares:
            return apology("must provide shares", 403)

        elif int(shares) <= 0:
            return apology("shares have plus", 403)

        # Pegando id do usuário
        userId = session["user_id"]

        # Quantidade total do symbol
        result = db.execute(
            "SELECT SUM(shares) AS total_shares FROM transactions WHERE user_id = ? AND symbol = ?", userId, symbol)

        # Pegar o total de ações retornadas (pode ser None se nunca comprou)
        total_shares = result[0]["total_shares"]

        # Se o usuário não possui ações dessa empresa
        if total_shares is None or total_shares <= 0:
            return apology("Você não possui ações dessa empresa", 400)

        # Verificar se ele quer vender mais do que possui
        if int(shares) > total_shares:
            return apology("Quantidade de ações insuficiente para venda", 400)

        # Pegando o preço atual da ação
        stock = lookup(symbol)
        name = stock["name"]
        price = stock["price"]

        # Calculando o total da venda
        total = price * int(shares)

        # Removendo ações do banco de dados do user
        db.execute("INSERT INTO transactions (user_id, symbol, name, shares, price) VALUES (?, ?, ?, ?, ?)",
                   userId, symbol, name, -int(shares), price)

        # Adicionando dinheiro a conta após a venda
        # Atualizar o saldo do usuário somando o valor da venda
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", total, userId)

        return redirect("/")

    else:
        user_id = session["user_id"]
        symbols = db.execute(
            "SELECT DISTINCT symbol FROM transactions WHERE user_id = ? AND shares > 0", user_id)
        return render_template("sell.html", symbols=symbols)

# Ver toda a lista de ações


@app.route("/stocks")
@login_required
def stocks():
    """Lista todas as ações disponíveis para negociação"""
    # Lista fixa de empresas
    symbols = ["AAPL", "MSFT", "GOOGL", "AMZN", "NFLX", "TSLA"]

    stocks_data = []
    for symbol in symbols:
        stock = lookup(symbol)
        if stock:  # Se conseguiu buscar
            stocks_data.append(stock)

    return render_template("stocks.html", stocks=stocks_data)

# Projetar algo novo para o site
# Aumentar cash
# Alterar senha
# Você decide isso
