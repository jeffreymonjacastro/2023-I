var nombre = document.getElementById("nombre");
var stature = document.getElementById("talla");
var weight = document.getElementById("peso");
var button = document.getElementById("button");
var result = document.getElementById("result");
var alerta = document.getElementById("alert");

button.addEventListener('click', () => {
    let imc
    let talla = parseFloat(stature.value)
    let peso = parseFloat(weight.value)
    let text
    
    if (nombre.value == "") {
        alerta.style.display = "flex"
        alerta.textContent = "Write your name"
    } else {
        alerta.style.display = "none"
        alerta.textContent = ""
    }

    if (stature.value == "") {
        alerta.style.display = "flex"
        alerta.textContent += " Put your stature"
    } else {
        alerta.style.display = "none"
        alerta.textContent = ""
    }

    if (weight.value == "") {
        alerta.style.display = "flex"
        alerta.textContent += " Put your weight"
    } else {
        alerta.style.display = "none"
        alerta.textContent = ""
    }
    

    if (talla > 100) {
        imc = peso/(Math.pow(talla/100, 2))
        
    } else {
        imc = peso/(talla*talla)
    }

    if (imc < 18.5) {
        text = "Low"
    } else if (imc >= 18.5 && imc < 24.9) {
        text = "Normal"
    }

    result.style.display = "flex"
    result.textContent = `Hello ${nombre.value}, your IMC is ${imc.toFixed(2)}. You have a ${text} IMC`

});
