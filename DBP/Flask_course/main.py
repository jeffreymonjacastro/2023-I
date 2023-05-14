# Flask es la clase para crear diferentes instancias
from flask import Flask 

# Se crea una instancia de Flask llamada app, el (__name__ es el nombre del módulo actual)
app = Flask(__name__)

## Flask funciona con rutas o urls, para crear una ruta se utiliza el decorador route. Cada ruta necesita una función que se ejecutará cuando se acceda a la ruta en el navegador
### Flask relaciona la función index() con el navegador a través de ('/') que es la ruta raíz.
### Endpoint hace referencia a x ruta


@app.route('/home')
def index():
    return "Hello world"

# Para correr la aplicación de flask:
## El host es la ip del servidor, en este caso es localhost para todos los usuarios.
## El puerto es el puerto del servidor, en este caso es el 3000

app.run(host='0.0.0.0', port=3000)

# Para correr flask en todas las ips: flask --app