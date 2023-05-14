from flask import (
    Flask, # Flask es la clase para crear diferentes instancias
    request, # request es la clase para obtener los datos del cliente
    make_response, # make_response es la clase para crear respuestas personalizadas
    redirect # redirect es la clase para redireccionar a otra ruta pasando parámetros, crear cookies, etc
    ) 

# Se crea una instancia de Flask llamada app, el (__name__ es el nombre del módulo actual)
app = Flask(__name__)

## Flask funciona con rutas o urls, para crear una ruta se utiliza el decorador route. Cada ruta necesita una función que se ejecutará cuando se acceda a la ruta en el navegador
### Flask relaciona la función index() con el navegador a través de ('/') que es la ruta raíz.
### Endpoint hace referencia a x ruta


@app.route('/index')
def index():
    # El objeto request contiene toda la información de la petición que se está haciendo
    user_ip_information = request.remote_addr # Se obtiene la ip del usuario

    # variable response: Se crea una respuesta personalizada que redirija a la ruta /show_info_address
    response = make_response(redirect('/show_info_address'))

    # Se crea una cookie con el nombre user_ip_information y el valor de la ip del usuario para que se guarde la ip en el navegador
    response.set_cookie('user_ip_information', user_ip_information)
    return response


@app.route('/show_info_address')
def show_info():
    # Se obtiene la ip del usuario desde la cookie a través del método get de request.cookies
    user_ip = request.cookies.get('user_ip_information') 

    return f"Hola que tal, tu ip es {user_ip}"


# Para correr la aplicación de flask:
## El host es la ip del servidor, en este caso es localhost para todos los usuarios.
## El puerto es el puerto del servidor, en este caso es el 3000

app.run(host='0.0.0.0', port=3000, debug=True)

