from flask import (
    Flask, 
    jsonify, # Para convertir un diccionario en un json
    request, # Para obtener los datos de la petición
    )

from db import Session, engine # Módulo db.py
from models import Usuario # Módulo models.py
import json # Para convertir un json en un diccionario
from sqlalchemy import text

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
    # Se obtienen los datos de la petición (cliente)
    data = json.loads(request.data)

    # Se valida que se haya enviado el username y el password
    if 'username' not in data:
        return jsonify({"respuesta": "No se ha enviado el username"})
    elif 'password' not in data:
        return jsonify({"respuesta": "No se ha enviado el password"})
    elif len(data['username']) == 0:
        return jsonify({"respuesta": "El username no puede estar vacío"})
    elif len(data['password']) == 0:
        return jsonify({"respuesta": "El password no puede estar vacío"})

    # El with crea un alias de la función engine.connect()
    with engine.connect() as con:
        # Se crea un nuevo objeto usuario
        nuevo_usuario = Usuario(username=data['username'], password=data['password'])
        # Se agrega el nuevo usuario a la sesión
        session.add(nuevo_usuario)
        # Probamos si el usuario ya existe en la db
        try:
            # Se confirma la sesión (Para guardarse)
            session.commit()
        except:
            return jsonify({"respuesta": "Usuario ya existe en la db"})
            
    return jsonify({"respuesta": "Usuario creado correctamente"})


@app.route('/obtener_venta', methods=['GET'])
def obtener_venta():
    data = json.loads(request.data)

    if 'username' not in data:
        return jsonify({"respuesta": "No se ha enviado el username"})
    
    with engine.connect() as con:
        # Se usa la función text para escribir la consulta en SQL
        obtener_usuario = text(f"select * from usuario where username = '{data['username']}'")
        # El método one() retorna una tupla con los datos de la consulta
        respuesta = con.execute(obtener_usuario).one()
        # Consulta para obtener la venta del id del usuario
        obtener_venta = text(f"select venta from ventas where username_id = {respuesta[0]}")
        # El método all() retorna una lista de tuplas con los datos de la consulta
        respuesta_ventas = con.execute(obtener_venta).all()
        respuesta_ventas = [i[0] for i in respuesta_ventas] # Lista por comprensión

        return jsonify({"ventas_usuario": {"username": data['username'], "ventas": respuesta_ventas}})
    

if __name__ == '__main__':
    app.run(debug=True, port=8000)