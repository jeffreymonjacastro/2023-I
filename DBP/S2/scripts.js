var nombre = document.getElementById("nombre");
var stature = document.getElementById("talla");
var weight = document.getElementById("peso");
var button = document.getElementById("button");
var result = document.getElementById("result");
var alerta = document.getElementById("alert");
var container = document.getElementById("container");


button.addEventListener('click', () => {
    let imc
    let talla = parseFloat(stature.value)
    let peso = parseFloat(weight.value)
    let text
    let alertas = []
    let bool = true
    
    if (nombre.value == "") {
        alertas.push("Write your name")
        bool = false
    }
    
    if(stature.value == "") {
        alertas.push("Put your stature")
        bool = false
    } 

    if (weight.value == "") {
        alertas.push("Put your weight")
        bool = false
    }

    if (talla > 2.2) {
        if (talla < 100 || talla > 220) {
            alertas.push("Stature is between 100 - 220 cm")
            bool = false
        }
    } else {
        if (talla < 1 || talla > 2.2) {
            alertas.push("Stature is between 1 - 2.2 m")
            bool = false
        }
    }

    if (peso < 30 || peso > 200) {
        alertas.push("Weight is between 30 - 200 kg")
        bool = false
    }

    if (bool) {
        alerta.style.display = "none"
        alertas = []

        if (talla > 2.2) {
            imc = peso/(Math.pow(talla/100, 2))
            
        } else {
            imc = peso/(talla*talla)
        }
    
        if (imc < 18.5) {
            text = "under weight, consider eating more to regulate your weight."
            container.style.background = "linear-gradient(90deg, rgba(0,255,229,1) 0%, rgba(48,191,253,1) 65%, rgba(69,86,252,1) 100%)"
        } else if (imc >= 18.5 && imc < 24.9) {
            text = "a Healthy weight, excellent! :D"
            container.style.background = "linear-gradient(90deg, rgba(71,255,0,1) 0%, rgba(44,255,78,1) 65%, rgba(19,172,0,1) 100%)"
        } else if (imc >= 24.9 && imc < 29.9) {
            text = "overweight, be careful, covid mostly affect obese people."
            container.style.background = "linear-gradient(90deg, rgba(248,255,148,1) 0%, rgba(241,255,44,1) 62%, rgba(242,255,0,1) 100%)"
        } else if (imc >= 29.9 && imc < 34.9) {
            text = "obesity, watch out, covid can affect you a lot."
            container.style.background = "linear-gradient(90deg, rgba(255,223,148,1) 0%, rgba(255,191,44,1) 60%, rgba(255,199,0,1) 100%)"
        } else if (imc >= 34.9 && imc < 39.9) {
            result.style.fontSize = "0.9em"
            text = "morbid obesity. Go to the doctor or covid could be dangerous"
            container.style.background = "linear-gradient(90deg, rgba(255,167,89,1) 0%, rgba(255,120,44,1) 41%, rgba(255,101,0,1) 100%)"
        } else if (imc >= 39.9) {
            result.style.fontSize = "0.9em"
            text = "extreme obesity. Must visit the doctor or covid will kill you💀"
            container.style.background = "linear-gradient(90deg, rgba(253,29,29,1) 0%, rgba(253,100,48,1) 48%, rgba(252,132,69,1) 100%)"
        }

        result.style.display = "flex"
        result.textContent = `Hello ${nombre.value}, your BMI is ${imc.toFixed(2)}. You have ${text}`

    } else {
        alerta.style.display = "flex"
        alerta.textContent = alertas.join(", ")
    }
    
});
