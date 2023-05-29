# PC1

## Descripción
Esta práctica consiste en una aplicación web para administrar una lista de colores. Permite agregar, editar y eliminar colores de una tabla, y también visualizar los colores existentes.

## Requisitos
- Python 3.7 o superior
- Flask
- Flask SQLAlchemy

## Instalación
1. Clona el repositorio del proyecto desde GitHub.

## Estructura del proyecto
El proyecto tiene la siguiente estructura de archivos:

```
- instance
- templates
  - colors_list.html
  - colors_list.js
- colors_server.py
```

La carpeta `instance` contine la bd inicializada. La carpeta `templates` contiene los archivos HTML y JavaScript necesarios para la interfaz web. El archivo `colors_server.py` contiene el código de la aplicación Flask.

## Iniciar la aplicación
1. En la terminal, asegúrate de estar ubicado en la carpeta del proyecto
2. Ejecuta el siguiente comando para iniciar el servidor de desarrollo:
   ```
   python -m flask --app colors_server.py run
   ```
3. Abre un navegador web y accede a la dirección `http://localhost:5000` para ver la aplicación.

## Tareas pendientes
A continuación se detallan las tareas que debes completar en el código proporcionado:

### En el archivo `colors_list.html`
1. No es necesario realizar algún cambio. Pero se puede observar la estructura del html y como asignar un color con el formato rgb.

### En el archivo `colors_list.js`
1. Completa la función `addColor()` para obtener los valores de los campos de entrada de los colores y enviarlos al servidor mediante una petición `POST`. Los valores de los campos de entrada pueden obtenerse utilizando `document.getElementById('ID_DEL_CAMPO').value`.
2. Completa la función `editPlayer(colorID)` para obtener el valor del campo de entrada `R`,`G` y `B` y enviarlo al servidor como parte de una petición `PUT` para actualizar el color con el ID correspondiente.
3. Completa la función `deletePlayer(colorID)` para enviar una petición `DELETE` al servidor para eliminar el color con el ID correspondiente.

### En el archivo `colors_server.py`
1. En la clase `Colors`, completa los atributos `R`, `G` y `B` de acuerdo a los campos esperados en la base de datos y en la clase.
2. En la función `route_colors()`, completa la lógica para manejar las peticiones `GET` y `POST` de la ruta `/colors`. Para la petición `GET`, debes obtener todos los colores de la base.
3. En la función `route_colors_id()`, completa la lógica para manejar las peticiones `GET`, `PUT` y `DELETE` de la ruta `/colors/<colors_id>`. Para la petición `GET`, debes obtener solo el color deseado.
