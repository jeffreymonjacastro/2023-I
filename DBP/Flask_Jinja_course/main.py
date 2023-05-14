from flask import (
    Flask, # Flask es la clase para crear diferentes instancias
    request, # request es la clase para obtener los datos del cliente
    make_response, # make_response es la clase para crear respuestas personalizadas
    redirect, # redirect es la clase para redireccionar a otra ruta pasando parámetros, crear cookies, etc
    render_template, # render_template es la clase para renderizar archivos html
    session, # session es la clase para crear sesiones
    ) 
from flask_bootstrap import Bootstrap # Bootstrap es la clase para utilizar bootstrap en flask
from flask_wtf import FlaskForm # FlaskForm es la clase para crear formularios
from wtforms.fields import StringField, PasswordField, SubmitField # StringField, PasswordField y SubmitField son las clases para crear los campos de los formularios
from wtforms.validators import DataRequired # DataRequired es la clase para validar los campos de los formularios

# Se crea una instancia de Flask llamada app, el (__name__ es el nombre del módulo actual)
app = Flask(__name__)

# Se crea una instancia de Bootstrap llamada bootstrap
bootstrap = Bootstrap(app)

# Se crea una clave para la aplicación y proteger las cookies
app.config['SECRET_KEY'] = 'CLAVE SEGURA'


## Flask funciona con rutas o urls, para crear una ruta se utiliza el decorador route. Cada ruta necesita una función que se ejecutará cuando se acceda a la ruta en el navegador
### Flask relaciona la función index() con el navegador a través de ('/') que es la ruta raíz.
### Endpoint hace referencia a x ruta

items = ["first", "second", "third", "four"]

# Se crea una clase para el formulario de login
class LoginForm(FlaskForm):
    username = StringField('Nombre de usuario', validators=[DataRequired()])
    password = PasswordField('contraseña', validators=[DataRequired()])
    submit = SubmitField('Enviar datos')



# Se crea una ruta para cuando se produzca un error 404 (Not Found), el parámetro varía según el error
@app.errorhandler(404)
def not_found(error):
    return render_template('404.html', error=error)


@app.route('/index')
def index():
    # El objeto request contiene toda la información de la petición que se está haciendo
    user_ip_information = request.remote_addr # Se obtiene la ip del usuario

    # variable response: Se crea una respuesta personalizada que redirija a la ruta /show_info_address
    response = make_response(redirect('/show_info_address'))

    # Se crea una cookie con el nombre user_ip_information y el valor de la ip del usuario para que se guarde la ip en el navegador
    # response.set_cookie('user_ip_information', user_ip_information)

    # Objeto sesion para guardar la respuesta
    session["user_ip_information"] = user_ip_information
    return response


# Se coloca el método get y post para que la ruta pueda recibir y enviar datos
@app.route('/show_info_address', methods=['GET', 'POST'])
def show_info():
    # Se obtiene la ip del usuario desde la cookie a través del método get de request.cookies 
    # user_ip = request.cookies.get('user_ip_information') 

    # Se obtiene la ip del usuario desde la sesión a través del método get de session
    user_ip = session.get("user_ip_information")

    username = session.get("username")

    login_form = LoginForm()

    # Se crea un diccionario donde almacene todas las variables que se quieran pasar al html
    context = {
        'user_ip': user_ip,
        'items': items,
        'login_form': login_form,
        'username': username
    }

    if login_form.validate_on_submit():
        username = login_form.username.data
        session["username"] = username
        return make_response(redirect('/index'))
        

    # Se renderiza el archivo html index.html y se le pasa la variable **context, que permite desempaquetar el diccionario context
    # render_template busca SIEMPRE el archivo html en la carpeta templates
    return render_template('ip_info.html', **context)


# Para correr la aplicación de flask:
## El host es la ip del servidor, en este caso es localhost para todos los usuarios.
## El puerto es el puerto del servidor, en este caso es el 3000

app.run(host='0.0.0.0', port=3000, debug=True)

