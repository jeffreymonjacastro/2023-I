    // Fetch colors del servervidor
    function fetchColors() {
        fetch('/colors')
          .then(response => response.json())
          .then(colors => {
            const colorTable = document.getElementById('color-table');
            const tbody = colorTable.getElementsByTagName('tbody')[0];
            tbody.innerHTML = ''; // Limpia las filas existentes en la tabla
  
            colors.forEach(color => {
              const row = document.createElement('tr');
              row.innerHTML = `
                <td>${color.R}</td>
                <td> #TODO </td>
                <td> #TODO </td>
                <td> #MOSTRAR COLOR </td>
                <td>
                  <button onclick="editColor(${color.id})">Edit</button>
                  <button> #TODO </button>
                </td>
              `;
              tbody.appendChild(row);
            });
          });
      }
  
      // Update color
      function editPlayer(colorID) {
          var R = document.getElementById("R").value;
          // TODO
          
          var data = { "R": R, "TODO" };
    
          fetch(`/colors/${colorID}`, {
          method: 'PUT',
          body: JSON.stringify(data),
          headers:{
              'Content-Type': 'application/json'
          }
          }).then(response => response.text())
          .then(text => {
              if (text === "SUCCESS") {
                  location.reload(); // Recarga la página
                  console.log(`Color with ID ${colorID} edited successfully`);          
              } 
          })
      }
  
      // Delete color
      function deletePlayer(colorId) {
        //TODO
      }

      // Create color
      function addColor(){
        //TODO
    }
  
      // Inicia cargando la página de colores existentes
      fetchColors();