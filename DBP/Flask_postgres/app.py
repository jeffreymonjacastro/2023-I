from flask import (
    Flask, 
    jsonify, # Para convertir un diccionario en un json
    )

from db import Session, engine # Módulo db.py
from models import Usuario # Módulo models.py

# Instancia de Flask
app = Flask(__name__)

session = Session()

# Decorador (@) | ruta 'hola' | solo método GET
@app.route('/hola', methods=['GET'])
def hola():
    return jsonify({'message': 'Endpoint desde hola'})

# Ruta para ingresar usuario |
@app.route('/create_user', methods=['POST'])
def create_user():
    # El with crea un alias de la función engine.connect()
    with engine.connect() as con:
        # Se crea un nuevo objeto usuario
        nuevo_usuario = Usuario(username="usuario1", password="123")
        # Se agrega el nuevo usuario a la sesión
        session.add(nuevo_usuario)

        try:
            # Se confirma la sesión (Para guardarse)
            session.commit()
        except:
            return jsonify({"respuesta": "Usuario ya existe en la db"})
            
    return jsonify({"respuesta": "Usuario creado correctamente"})

if __name__ == '__main__':
    app.run(debug=True, port=8000)