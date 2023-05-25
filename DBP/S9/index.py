from dataclasses import dataclass
from flask import Flask, jsonify, request, render_template, redirect
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)

app.config['SQLALCHEMY_DATABASE_URI'] = 'postgresql://postgres:123@localhost:5432/flaskapp'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

db = SQLAlchemy(app)

@dataclass
class Person(db.Model):
    id: int
    name: str
    email: str

    id = db.Column(db.Integer, autoincrement=True, primary_key=True)
    name = db.Column(db.String(100), nullable=False)
    email = db.Column(db.String(100), nullable=False)

    def __repr__(self):
        return f'<Person {self.name}>'


with app.app_context():
    db.create_all()


@app.route('/', methods=['GET', 'POST'])
def menu():
    if request.method == 'GET':
        persons = Person.query.all()
        return jsonify(persons)


    elif request.method == 'POST':
        person = request.get_json()
        person_test = Person(name = person['name'], email = person['email'])
        db.session.add(person_test)
        db.session.commit()
        return f"Person {person['name']} added successfully!"
        


@app.route('/<id>', methods=['GET', 'PUT', 'DELETE'])
def menu_id(id):
    if request.method == 'GET':
        person = Person.query.get(id)
        return jsonify(person) 

    elif request.method == 'PUT':
        new_person = request.get_json()
        existing_person = Person.query.get(id)
        existing_person.name = new_person['name']
        existing_person.email = new_person['email']
        db.session.commit()
        return f"SUCCESS"

    elif request.method == 'DELETE':
        person = Person.query.get_or_404(id)
        db.session.delete(person)
        db.session.commit()
        return "SUCCESS"



app.run(debug=True, host='0.0.0.0', port=5000)

