from dataclasses import dataclass
from flask import Flask, jsonify, request, render_template, redirect, flash
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)

app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

app.secret_key = 'my_secret_key'

db = SQLAlchemy(app)

@dataclass
class Colors(db.Model):
    id: #TODO
    R: #TODO
    G: #TODO
    B: #TODO

    id = db.Column(db.Integer, primary_key=True)
    #TODO
    
    def __repr__(self):
        return f'<Color {self.id}>'

with app.app_context():
    db.create_all()

@app.route('/')
def list():
    return render_template('colors_list.html')

@app.route('/color_list.js')
def list_js():
    return render_template('colors_list.js')

@app.route('/colors', methods=['GET', 'POST'])
def route_colors():
    if request.method == 'GET':
        #TODO
    
    elif request.method == 'POST':
        #TODO

@app.route('/colors/<colors_id>', methods=['GET', 'PUT', 'DELETE'])
def route_colors_id(colors_id):
    if request.method == 'GET':
        #TODO
    
    elif request.method == 'PUT':
        #TODO
    
    elif request.method == 'DELETE':
        #TODO

