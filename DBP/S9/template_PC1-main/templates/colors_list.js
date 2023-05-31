// Fetch colors del servervidor
function contraste(elem, r, g, b) {
    var brillo = (r * 299 + g * 587 + b * 114) / 1000
    return brillo < 128 ? elem.style.color = "white" : elem.style.color = "black"
}

function typecolor(elem, r, g, b) {
    if (r < 10 && g < 10 && b < 10) {
      elem.innerHTML = "Black"
    } else if (r > 240 && g > 240 && b > 240) {
        elem.innerHTML = "White"
    } else if (r + g + b < 100) {
        elem.innerHTML = "Dark"
    } else if (r + g + b > 700) {
        elem.innerHTML = "Light"
    } else if (r == g && g == b) {
        elem.innerHTML = "Gray"
    } else if (r == g && r > b) {
        elem.innerHTML = "Yellow"
    } else if (r == b && r > g) {
        elem.innerHTML = "Magenta"
    } else if (g == b && g > r) {
        elem.innerHTML = "Cyan"
    } else if (r > g && r > b) {
        elem.innerHTML = "Red"
    } else if (g > r && g > b) {
        elem.innerHTML = "Green"
    } else if (b > r && b > g) {
        elem.innerHTML = "Blue"
    }
}

function fetchColors() {
    fetch('/colors')
    .then(response => response.json())
    .then(colors => {
        const colorTable = document.getElementById('color-table')
        const tbody = colorTable.getElementsByTagName('tbody')[0]
        tbody.innerHTML = ''

        colors.forEach(color => {
            const row = document.createElement('tr')
            row.setAttribute('id', color.id)

            row.innerHTML = `
                <td>${color.R}</td>
                <td>${color.G}</td>
                <td>${color.B}</td>
                <td></td>
                <td>
                  <button onclick="editColor(${color.id})">Edit</button>
                  <button onclick="deleteColor(${color.id})"> Delete </button>
                </td>
            `

            row.style.backgroundColor = `rgb(${color.R}, ${color.G}, ${color.B})`
            contraste(row, color.R, color.G, color.B)
            typecolor(row.children[3], color.R, color.G, color.B)
            tbody.appendChild(row)
        })
    })
}

// Create color
function addColor(){
    var R = document.getElementById("R").value;
    var G = document.getElementById("G").value;
    var B = document.getElementById("B").value;

    var data = { "R": R, "G": G, "B": B };

    fetch('/colors', {
        method: 'POST',
        body: JSON.stringify(data),
        headers:{
          'Content-Type': 'application/json'
        }
    }).then(response => response.json())
    .then(color => {
        const colorTable = document.getElementById("color-table")
        const tbody = colorTable.getElementsByTagName("tbody")[0]
        const row = document.createElement("tr") 
        row.setAttribute("id", color.id) 

        row.innerHTML = `
            <td> ${color.R} </td>
            <td> ${color.G} </td>
            <td> ${color.B} </td>
            <td></td>
            <td>
                <button type="button" onclick="editColor(${color.id})"> Edit </button>
                <button type="button" onclick="deleteColor(${color.id})"> Delete </button>
            </td>
        ` 
        row.style.backgroundColor = `rgb(${color.R}, ${color.G}, ${color.B})`
        contraste(row, color.R, color.G, color.B)
        typecolor(row.children[3], color.R, color.G, color.B)
        tbody.appendChild(row)
    })
}

// Update color
function editColor(colorID) {
    var R = document.getElementById("R").value;
    var G = document.getElementById("G").value;
    var B = document.getElementById("B").value;
    
    var data = { "R": R, "G": G, "B": B };

    fetch(`/colors/${colorID}`, {
        method: 'PUT',
        body: JSON.stringify(data),
        headers:{
            'Content-Type': 'application/json'
        }
    }).then(response => response.json())
    .then(color => {
        const row = document.getElementById(color.id)

        const R = row.children[0]
        const G = row.children[1]
        const B = row.children[2]

        R.innerHTML = color.R
        G.innerHTML = color.G
        B.innerHTML = color.B  

        row.style.backgroundColor = `rgb(${color.R}, ${color.G}, ${color.B})`
        contraste(row, color.R, color.G, color.B)
        typecolor(row.children[3], color.R, color.G, color.B)
        console.log(`Color with ID ${colorID} edited successfully`)
    })
}

// Delete color
function deleteColor(colorId) {
    fetch(`/colors/${colorId}`, {
        method: 'DELETE'

    }).then(response => response.text())
    .then(id => {
        const row = document.getElementById(id)
        row.parentNode.removeChild(row)
    })
}


// Inicia cargando la página de colores existentes
fetchColors();