var nombre = document.getElementById("nombre");
var stature = document.getElementById("talla");
var weight = document.getElementById("peso");
var button = document.getElementById("button");
var result = document.getElementById("result");

button.addEventListener('click', () => {
    let imc
    let talla = parseFloat(stature.value)
    let peso = parseFloat(weight.value)

    console.log("Hola");
    
    if (talla > 100) {
        imc = peso/(Math.pow(talla/100, 2))
        
    } else {
        imc = peso/(talla*talla)
    }

    result.style.display = "flex"
    result.textContent = `Hello ${nombre.value}, your IMC is ${imc.toFixed(2)}`
});
