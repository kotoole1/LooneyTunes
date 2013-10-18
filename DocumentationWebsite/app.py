from flask import *
import json

app = Flask(__name__)
app.debug = True

@app.route("/")
def index():
	return render_template("index.html")

if __name__ == "__main__":
	app.run()