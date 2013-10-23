from flask import *
import json

app = Flask(__name__)
app.debug = True

@app.route("/")
def index():
	return render_template("index.html")

@app.route("/design")
def design():
	return render_template("design.html")

@app.route("/timeline")
def timeline():
	json_timeline_data = open("data/timeline.json")
	timeline_data = json.load(json_timeline_data)
	json_timeline_data.close()
	return render_template("timeline.html", timeline=timeline_data)

@app.route("/team")
def team():
	json_team_data = open("data/team.json")
	team_data = json.load(json_team_data)
	json_team_data.close()
	return render_template("team.html", team=team_data)

if __name__ == "__main__":
	app.run()