# Los modelos son las tablas que vamos a colocar en la base de datos

from sqlalchemy import Column, Integer, String # Se importan los tipos de datos que se van a utilizar en la base de datos
from sqlalchemy.schema import ForeignKey # Se importa para crear las llaves foráneas
from sqlalchemy.orm import relationship # Se importa para crear las relaciones entre tablas
from app import db


class Usuario(db.Model):
    __tablename__ = "usuario" # Se coloca el nombre de la tabla
    
    # Se crean las columnas de la tabla 
    id = db.Column(db.Integer, autoincrement=True, primary_key=True)
    username = db.Column(db.String(70), unique=True)
    password = db.Column(db.String(70))
    ventas = relationship("Ventas", backref="usuario") # Se crea la relación entre las tablas usuario y ventas

class Ventas(db.Model):
    __tablename__ = "ventas"

    id = db.Column(db.Integer, autoincrement=True, primary_key=True)
    username_id = db.Column(db.Integer, ForeignKey("usuario.id")) # Se crea la llave foránea
    venta = db.Column(db.Integer)


# Aquí se crea la tabla en la base de datos
Base.metadata.create_all(engine)