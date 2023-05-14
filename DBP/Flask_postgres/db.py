from sqlalchemy import create_engine # Se encarga de hacer todas las traducciones a SQL, como los insert, select y delete
from sqlalchemy.ext.declarative import declarative_base # Se encarga de crear las clases que representan las tablas de la base de datos
from sqlalchemy.orm import sessionmaker # Se encarga de crear las sesiones para poder hacer las consultas a la base de datos

# Se crea una instancia de la clase declarative_base
Base = declarative_base()

# Se crea la conexión a la base de datos
engine = create_engine("postgresql://postgres:123@localhost:5432/flaskapp") 

# Se crea una sesión para ingresar al motor de la base de datos
Session = sessionmaker(bind=engine)
