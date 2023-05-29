from flask import Flask, render_template, request, redirect, jsonify
from flask_sqlalchemy import SQLAlchemy
from dataclasses import dataclass

app = Flask(__name__)

app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

db = SQLAlchemy(app)

@dataclass
class Student(db.Model):
    id: int
    nombre: str
    apellido: str
    nota: int

    id = db.Column(db.Integer, autoincrement=True, primary_key=True)
    nombre = db.Column(db.String(100), nullable=False)
    apellido = db.Column(db.String(100), nullable=False)
    nota = db.Column(db.Integer, nullable=False)

    def __repr__(self):
        return f'<Student {self.name}>'

with app.app_context():
    db.create_all()

# Rutass
@app.route('/')
def estudiantes():
    return render_template('estudiantes.html')

@app.route('/estudiantes', methods=['GET','POST'])
def mostrar_estudiantes():
    if request.method == 'GET':
        estudiantes = Student.query.all()
        return jsonify(estudiantes)

    elif request.method == 'POST':
        estudiante = request.get_json()
        nuevo_estudiante = Student(nombre = estudiante['nombre'], apellido = estudiante['apellido'], nota = estudiante['nota'])

        db.session.add(nuevo_estudiante)
        db.session.commit()
        return 'EXITO'

@app.route('/estudiante/<id>', methods=['GET','PUT', 'DELETE'])
def modificar_estudiante(id):
    if request.method == 'GET':
        estudiante = Student.query.get(id)
        return jsonify(estudiante)
        
    elif request.method == 'PUT':
        estudiante = request.get_json()
        estudiante_modificado = Student.query.get(id)
        estudiante_modificado.nombre = estudiante['nombre']
        estudiante_modificado.apellido = estudiante['apellido']
        estudiante_modificado.nota = estudiante['nota']

        db.session.commit()
        return 'EXITO'
    elif request.method == 'DELETE':
        estudiante = Student.query.get(id)
        db.session.delete(estudiante)
        db.session.commit()
        return 'EXITO'



app.run(debug=True, host='0.0.0.0', port=8000)