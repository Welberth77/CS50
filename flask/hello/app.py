from flask import Flask, render_template, request

app = Flask(__name__)

# Definindo rota para a aplicação
@app.route("/")
def index():
    # Carregar a página
    return render_template("index.html")

# Rota da segunda página
@app.route("/greet")
def greet():
    name = request.args.get("name", "word")
    return render_template("greet.html", name=name)
