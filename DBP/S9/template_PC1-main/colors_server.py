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
    id: int
    R: int
    G: int
    B: int

    id = db.Column(db.Integer, autoincrement=True, primary_key=True)
    R = db.Column(db.Integer, nullable=False)
    G = db.Column(db.Integer, nullable=False)
    B = db.Column(db.Integer, nullable=False)
    
    def __repr__(self):
        return f'<Color {self.id}>'

with app.app_context():
    db.create_all()

@app.route('/')
def list():
    return render_template('colors_list.html')

@app.route('/colors_list.js')
def list_js():
    return render_template('colors_list.js')

@app.route('/colors', methods=['GET', 'POST'])
def route_colors():
    if request.method == 'GET':
        colors = Colors.query.order_by(Colors.id).all()
        return jsonify(colors) 
        
    elif request.method == 'POST':
        color = request.get_json()
        new_color = Colors(R = color['R'], G = color['G'], B = color['B'])
        db.session.add(new_color)
        db.session.commit()
        return jsonify(new_color)

@app.route('/colors/<colors_id>', methods=['GET', 'PUT', 'DELETE'])
def route_colors_id(colors_id):
    if request.method == 'GET':
        color = Colors.query.get(colors_id)
        return jsonify(color)
    
    elif request.method == 'PUT':
        new_color = request.get_json()
        old_color = Colors.query.get(colors_id)

        old_color.R = new_color['R']
        old_color.G = new_color['G']
        old_color.B = new_color['B']

        db.session.commit()

        return jsonify(old_color)
        
    
    elif request.method == 'DELETE':
        color = Colors.query.get(colors_id)
        db.session.delete(color)
        db.session.commit()
        return colors_id

app.run(debug=True, host='0.0.0.0', port=4000)