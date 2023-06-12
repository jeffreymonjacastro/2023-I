import React, {useState} from 'react'

export const PrimerComp = () => {

    // let nombre = "Jeffrey"
    let web = "https://www.google.com"

    // useState es un hook que permite manejar estados en componentes funcionales
    const [nombre, setNombre] = useState("Jeffrey")

    let cursos = [
        "Javascript",
        "ReactJS",
        "NodeJS",
        "Python",
        "CSS"
    ]

    const cambiarNombre = (nuevoNombre) => {
        setNombre(nuevoNombre)
    }

    return (
        <div>
            <h1>PrimerComp</h1>

            {/* Con las llaves se puede poner codigo JS */}
            <p>Nombre: <strong className = {nombre.length >= 5 ? 'verde' : 'rojo'}>{nombre}</strong></p> 
            <a href={web}>Ir a Google</a>

            <br />

            <input type="text" onChange={ e => cambiarNombre(e.target.value) } placeholder='Cambia el nombre'/>

            <button onClick={ e => cambiarNombre("Hola Mundo!") }>Click me</button>

            <button onClick = { e => {
                console.log("El valor guardado en tu estado es: ", nombre)
            }}> Mostrar estado </button>

            <ul>
                {
                    // Se puede usar map para iterar un array, cada elemento debe tener un key
                    cursos.map((curso,indice) => {
                        return (<li key={indice}>
                            {curso}
                        </li>)
                    })
                }
            </ul>
        </div>
    )
}
