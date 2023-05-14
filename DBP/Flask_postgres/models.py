# Los modelos son las tablas que vamos a colocar en la base de datos

from sqlalchemy import Column, Integer, String # Se importan los tipos de datos que se van a utilizar en la base de datos
from db import Base, engine
from sqlalchemy.schema import ForeignKey # Se importa para crear las llaves foráneas
from sqlalchemy.orm import relationship # Se importa para crear las relaciones entre tablas


class Usuario(Base):
    __tablename__ = "usuario" # Se coloca el nombre de la tabla
    
    # Se crean las columnas de la tabla 
    id = Column(Integer, autoincrement=True, primary_key=True)
    username = Column(String(70), unique=True)
    password = Column(String(70))
    ventas = relationship("Ventas", backref="usuario") # Se crea la relación entre las tablas usuario y ventas

class Ventas(Base):
    __tablename__ = "ventas"

    id = Column(Integer, autoincrement=True, primary_key=True)
    username_id = Column(Integer, ForeignKey("usuario.id")) # Se crea la llave foránea
    venta = Column(Integer)


# Aquí se crea la tabla en la base de datos
Base.metadata.create_all(engine)