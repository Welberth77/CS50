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
    # vizualizar o que comprou
    # Quantas ações de caada ele tem, o preço atual, valor total
    # Saldo atual do usuario
    # Valor total de todas as ações
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # Formulário com o nome do symbol
        # Quantas ações ele quer comprar
        # Verificar se o user tem dinheiro para comprar
        # Atualizar dinheiro

    # Criar tabela para acompanhar quantas ações casa usuario possui
    # id | nome da ação | quantidade | foreingid do user
    return apology("TODO")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # Ver o histórico de todas as transações
    # Tabela com todas as trnsaçõe anteriores
    # Quais ações foram compradas ou vendidas
    # Quantas de cada ação foi compra ou vendida
    # Quando a transação ocorreu
    return apology("TODO")


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
        # Verificação do symbol
        if not request.form.get("symbol"):
            return apology("must provide symbol")

        # Se symbol não existir

        # Retornar nome, preço e simbolo da ação em uma página html

    # GET
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        # Validar os dados
        # Obterndo dados
        username = request.form.get("username")
        password = request.form.get("password")
        confPassword = request.form.get("conf-password")

        # Verificar entrda de nome
        if not username:
            return apology("must provide username", 403)

        # Verificar entrada de senha
        elif not password:
            return apology("must provide password", 403)

        # Verificar entrada de confirmação de senha
        elif not confPassword:
            return apology("must provide password confirmation", 403)

        # Verificar se senha e confirmação de senha são iguais
        elif password != confPassword:
            return apology("password and password confirmation is different", 403)

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


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # Venda de ações
    # Vizualizar ações que tem e escollher qual vender e a quantidade
        # Saber se o usuário realmente tem aquele número de ações
        # Ter certeza que não pode vender um número negativo de ações

    return apology("TODO")

# Projetar algo novo para o site
# Aumentar cash
# Alterar senha
# Você decide isso
