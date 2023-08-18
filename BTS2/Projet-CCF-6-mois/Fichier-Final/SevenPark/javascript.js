

// -------------------------------------------------- Gestion theme clair / foncé --------------------------------------------------

// function to set a given theme/color-scheme
function setTheme(themeName) {
    localStorage.setItem('theme', themeName);
    document.documentElement.className = themeName;
}

// function to toggle between light and dark theme
function toggleTheme() {
    if (localStorage.getItem('theme') === 'theme-dark') {
        setTheme('theme-light');
    } else {
        setTheme('theme-dark');
    }
}

// Immediately invoked function to set the theme on initial load
(function () {
    setTheme('theme-light');
})();

// ---------------------------------------------------- Gestion des données ------------------------------------------------

// Fonction pour récupérer les données à partir du serveur et les mettre à jour sur la page
function updateData() {
  if (window.location.pathname === "/SevenPark/dashboard.php") {
    // Effectuez une requête AJAX pour récupérer les données du serveur
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function() {
      if (this.readyState === XMLHttpRequest.DONE && this.status === 200) {
        // Analyser les données JSON renvoyées par le serveur
        var data = JSON.parse(this.responseText);
        // Mettre à jour les valeurs sur la page
        document.getElementById("nb-total").innerHTML = parseInt(data.nb_libre) + parseInt(data.nb_prise);
        document.getElementById("nb-libre").innerHTML = data.nb_libre;
        document.getElementById("nb-prise").innerHTML = data.nb_prise;
        // Mettre à jour le graphique place libre / prise
        var chart = Chart.getChart("piechart");
        chart.data.datasets[0].data[0] = data.nb_libre;
        chart.data.datasets[0].data[1] = data.nb_prise;
        chart.update();
        // Mettre à jour le graphique température / humidité / pression
        var chart2 = Chart.getChart("barchart");
        chart2.data.datasets[0].data[0] = data.avg_temperature;
        chart2.data.datasets[0].data[1] = data.avg_humidite;
        chart2.update();
      }
    };
    xhr.open("GET", "get_data_dashboard.php", true);
    xhr.send();
  }
}

setInterval(updateData, 1000);

// -------------------------------------------------- Gestion des passerelles --------------------------------------------------

// Fonction qui interroge la bdd pour récupérer le nombre de passerelles et les affiche sur la page
function mettreAJourPasserelles() {
  if (window.location.pathname === "/SevenPark/passerelles.php") {
    // Appeler l'API pour récupérer le nombre de passerelles et les données des passerelles
    fetch('recuperer_passerelles.php')
      .then(response => response.json())
      .then(resultPasserelle => {
        // Récupérer le nombre de passerelles et les données des passerelles
        const nbPasserelles = resultPasserelle.nb_passerelles;
        const passerelles = resultPasserelle.passerelles;
        
        // Ajouter une carte pour chaque passerelle
        const container = document.querySelector('.passerelles-container');
        container.innerHTML = ''; // Effacer les anciennes cartes de passerelles
        for (let i = 0; i < nbPasserelles; i++) {
          const passerelle = passerelles[i];
          const passerelleCard = document.createElement('div');
          passerelleCard.classList.add('passerelle-card');
          passerelleCard.innerHTML = `
          <div class="passerelle-titre" style="font-weight:bold;font-size:22px;font-family:Arial">Passerelle ${passerelle.emplacement} | ${passerelle.Zone}</div>`;

          // Ajouter un gestionnaire d'événements pour le clic sur la carte de la passerelle
          passerelleCard.addEventListener('click', () => {
            afficherOverlayPasserelles("Passerelle " + passerelle.emplacement, passerelle.id);
          });
          
          container.appendChild(passerelleCard);
        }
      })
      .catch(error => {
        console.error('Erreur lors de la récupération des passerelles :', error);
      });
  }
}

setInterval(mettreAJourPasserelles, 1000);

function afficherOverlayPasserelles(titre, idpasserelle) {
  const overlay = document.querySelector('.overlay');
  const overlayContent = overlay.querySelector('.overlay-content');

  function resetOverlayPasserelles() {
    // Supprimer tous les enfants de l'overlay
    while (overlayContent.firstChild) {
      overlayContent.removeChild(overlayContent.firstChild);
    }
  }

  // Réinitialiser l'overlay avant de l'afficher
  resetOverlayPasserelles();

  // Ajouter le titre
  const titleElement = document.createElement('h2');
  titleElement.textContent = titre;
  overlayContent.appendChild(titleElement);

  // Ajouter le message de chargement
  const loadingMessage = document.createElement('div');
  loadingMessage.classList.add('loading');
  loadingMessage.textContent = 'Chargement en cours...';
  overlayContent.appendChild(loadingMessage);

  // Afficher l'overlay
  overlay.style.display = 'block';

  // Attendre entre 1 et 2 secondes avant d'afficher les données
  const tempsAttente = Math.floor(Math.random() * 2) + 1;

  setTimeout(() => {
    // Supprimer le message de chargement
    overlayContent.removeChild(loadingMessage);

    // Récupérer les données depuis la base de données
    fetch('recuperer_passerelles.php')
      .then(response => response.json())
      .then(data => {
        // Trouver la passerelle correspondante
        const passerelle = data.passerelles.find(p => p.id === idpasserelle);

        // Afficher les données récupérées depuis la base de données
        const descriptionElement = document.createElement('p');
        descriptionElement.innerHTML = `<span style="font-size: 1.2rem;">ID de la passerelle : ${passerelle.id}</span><br/>
                                        <span style="font-size: 1.2rem;">Adresse IP : ${passerelle.ip}</span><br/>
                                        <span style="font-size: 1.2rem;">Nombre de capteurs : ${passerelle.NBCapteur}</span><br/>
                                        <span style="font-size: 1.2rem;">Zone : ${passerelle.Zone}</span>`;
        overlayContent.appendChild(descriptionElement);



        // Ajouter le bouton "Fermer"
        const closeButton = document.createElement('button');
        closeButton.classList.add('close-button');
        closeButton.textContent = 'Fermer';
        overlayContent.appendChild(closeButton);
        closeButton.style.marginTop = '2rem';
        closeButton.style.display = 'block';
        closeButton.style.marginLeft = 'auto';
        closeButton.style.marginRight = 'auto';
        closeButton.addEventListener('click', () => {
          // Cacher l'overlay lorsqu'on clique sur le bouton "Fermer"
          overlay.style.display = 'none';
        });
      })
      .catch(error => {
        console.error('Erreur lors de la récupération des données depuis la base de données:', error);
        // Afficher un message d'erreur à l'utilisateur
        const errorMessage = document.createElement('div');
        errorMessage.textContent = 'Une erreur est survenue lors du chargement des données.';
        overlayContent.appendChild(errorMessage);

        // Ajouter le bouton "Fermer"
        const closeButton = document.createElement('button');
        closeButton.classList.add('close-button');
        closeButton.textContent = 'Fermer';
        overlayContent.appendChild(closeButton);
        closeButton.style.marginTop = '1rem';
        closeButton.style.display = 'block';
        closeButton.style.marginLeft = 'auto';
        closeButton.style.marginRight = 'auto';
        closeButton.addEventListener('click', () => {
          // Cacher l'overlay lorsqu'on clique sur le bouton "Fermer"
          overlay.style.display = 'none';
          });
        });
    }, tempsAttente * 1000);
}

// -------------------------------------------------- Gestion des capteurs Environnemental --------------------------------------------------

function mettreAJourCapteurEnvironnemental() {
  if (window.location.pathname === "/SevenPark/capteurEnv.php") {
    // Appeler l'API pour récupérer le nombre de passerelles et les données des passerelles
    fetch('recuperer_capteur_env.php')
      .then(response => response.json())
      .then(resultCapteurEnv => {
        // Récupérer le nombre de passerelles et les données des passerelles
        const nbCapteurEnv = resultCapteurEnv.nb_capteurEnv;
        const capteurEnv = resultCapteurEnv.capteurEnv;
        
        // Ajouter une carte pour chaque passerelle
        const container = document.querySelector('.capteur-env-container');
        container.innerHTML = ''; // Effacer les anciennes cartes de passerelles
        for (let i = 0; i < nbCapteurEnv; i++) {
          const capteur_env = capteurEnv[i];
          const capteurEnvCard = document.createElement('div');
          capteurEnvCard.classList.add('capteur-env-card');
          capteurEnvCard.innerHTML = `
          <div class="capteurEnv-titre" style="font-weight:bold;font-size:22px;font-family:Arial">Capteur Env ID ${capteur_env.idCapteur}</div>`;
          
          // Ajouter un gestionnaire d'événements pour le clic sur la carte de la passerelle
          capteurEnvCard.addEventListener('click', () => {
            afficherOverlayCapteursEnvironnemental("Capteur Env " + (i + 1), capteur_env.idCapteur);
          });
          
          container.appendChild(capteurEnvCard);
        }
      })
      .catch(error => {
        console.error('Erreur lors de la récupération des capteur env :', error);
      });
  }
}

setInterval(mettreAJourCapteurEnvironnemental, 1000);

function afficherOverlayCapteursEnvironnemental(titre, idCapteur) {
  const overlay = document.querySelector('.overlay');
  const overlayContent = overlay.querySelector('.overlay-content');

  function resetOverlayCapteursEnvironnemental() {
    // Supprimer tous les enfants de l'overlay
    while (overlayContent.firstChild) {
      overlayContent.removeChild(overlayContent.firstChild);
    }
  }

  // Réinitialiser l'overlay avant de l'afficher
  resetOverlayCapteursEnvironnemental();

  // Ajouter le titre
  const titleElement = document.createElement('h2');
  titleElement.textContent = titre;
  overlayContent.appendChild(titleElement);

  // Ajouter le message de chargement
  const loadingMessage = document.createElement('div');
  loadingMessage.classList.add('loading');
  loadingMessage.textContent = 'Chargement en cours...';
  overlayContent.appendChild(loadingMessage);

  // Afficher l'overlay
  overlay.style.display = 'block';

  // Attendre entre 1 et 2 secondes avant d'afficher les données
  const tempsAttente = Math.floor(Math.random() * 2) + 1;

  setTimeout(() => {
    // Supprimer le message de chargement
    overlayContent.removeChild(loadingMessage);

    // Récupérer les données depuis la base de données
    fetch(`recuperer_capteur_env.php`)
      .then(response => response.json())
      .then(data => {
        // Trouver le capteur correspondant
        const capteurEnv = data.capteurEnv.find(capteurEnv => capteurEnv.idCapteur === idCapteur);

        // Afficher les données récupérées depuis la base de données
        const descriptionElement = document.createElement('p');
        descriptionElement.innerHTML = `<span style="font-size: 1.1rem;">ID du capteur : ${capteurEnv.idCapteur}</span><br/>
                                        <span style="font-size: 1.1rem;">Température du capteur : ${capteurEnv.temperature}</span><br/>
                                        <span style="font-size: 1.1rem;">Humidité du capteur : ${capteurEnv.humidite}</span><br/>
                                        <span style="font-size: 1.1rem;">Pression du capteur : ${capteurEnv.pression}</span><br/>
                                        <span style="font-size: 1.1rem;">IDPasserelle du capteur : ${capteurEnv.idPasserelle}</span>`;
        overlayContent.appendChild(descriptionElement);

        // Ajouter le bouton "Fermer"
        const closeButton = document.createElement('button');
        closeButton.classList.add('close-button');
        closeButton.textContent = 'Fermer';
        overlayContent.appendChild(closeButton);
        closeButton.style.marginTop = '2rem';
        closeButton.style.display = 'block';
        closeButton.style.marginLeft = 'auto';
        closeButton.style.marginRight = 'auto';
        closeButton.addEventListener('click', () => {
          // Cacher l'overlay lorsqu'on clique sur le bouton "Fermer"
          overlay.style.display = 'none';
        });
      })
      .catch(error => {
        console.error('Erreur lors de la récupération des données depuis la base de données:', error);
        // Afficher un message d'erreur à l'utilisateur
        const errorMessage = document.createElement('div');
        errorMessage.textContent = 'Une erreur est survenue lors du chargement des données.';
        overlayContent.appendChild(errorMessage);

        // Ajouter le bouton "Fermer"
        const closeButton = document.createElement('button');
        closeButton.classList.add('close-button');
        closeButton.textContent = 'Fermer';
        overlayContent.appendChild(closeButton);
        closeButton.style.marginTop = '2rem';
        closeButton.style.display = 'block';
        closeButton.style.marginLeft = 'auto';
        closeButton.style.marginRight = 'auto';
        closeButton.addEventListener('click', () => {
          // Cacher l'overlay lorsqu'on clique sur le bouton "Fermer"
          overlay.style.display = 'none';
        });
      })
      .finally(() => {
        // Supprimer le message de chargement même si une erreur est survenue
        overlayContent.removeChild(loadingMessage);
      });
  }, tempsAttente * 1000);
}

// ------------------------------------------------------ Gestion Capteurs -------------------------------------------------------

function toggleDropdown1() {
  var dropdown1 = document.getElementById("dropdown1");
  var dropdown2 = document.getElementById("dropdown2");

  // Récupérer la valeur sélectionnée dans le dropdown 1
  var selectedPasserelle = dropdown1.value;

  if (selectedPasserelle !== "Sélectionnez une Passerelle") {
    dropdown2.style.display = "inline-block";
    dropdown2.style.marginLeft = "10px"; // Ajoute une marge à gauche pour séparer les dropdowns

    // Effectuer une requête AJAX pour récupérer les capteurs de la passerelle sélectionnée
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState === 4 && this.status === 200) {
        var capteurs = JSON.parse(this.responseText);

        // Mettre à jour le dropdown 2 avec les capteurs
        dropdown2.innerHTML = '<option disabled selected>Sélectionnez un Capteur</option>';
        for (var i = 0; i < capteurs.length; i++) {
          dropdown2.innerHTML += '<option value="' + capteurs[i].id + '">' + capteurs[i].id + '</option>';
        }
      }
    };
    xhttp.open("GET", "recuperer_capteurs.php?passerelle=" + selectedPasserelle, true);
    xhttp.send();
  } else {
    dropdown2.style.display = "none";
    dropdown2.style.marginLeft = "0"; // Réinitialise la marge à gauche lorsque le deuxième dropdown est masqué
    dropdown2.innerHTML = '<option disabled selected>Sélectionnez un Capteur</option>';
  }
}

function toggleDropdown2() {
  if (window.location.pathname === "/SevenPark/capteur.php") {
    var dropdown1 = document.getElementById("dropdown1");
    var dropdown2 = document.getElementById("dropdown2");
    var infoContainer = document.getElementById("info-container");

    // Récupérer la valeur sélectionnée dans le dropdown 1
    var selectedPasserelle = dropdown1.options[dropdown1.selectedIndex].text;

    var selectedPasserelleMAC = dropdown1.value;

    // Récupérer la valeur sélectionnée dans le dropdown 2
    var selectedCapteur = dropdown2.value;

    if (selectedPasserelle !== "Sélectionnez une Passerelle" && selectedCapteur !== "Sélectionnez un Capteur") {
      if (selectedPasserelle.indexOf("Int") !== -1) {
        // Effectuer une requête AJAX pour récupérer les données du capteur interne
        var xhttpInt = new XMLHttpRequest();
        xhttpInt.onreadystatechange = function() {
          if (this.readyState === 4 && this.status === 200) {
            var capteurData = JSON.parse(this.responseText);

            // Construire le contenu des informations du capteur interne
            var infoHTML = '<h3>Informations du Capteur</h3>';
            infoHTML += '<p>Etat de la place : ' + capteurData.EtatPlace + '</p>';
            infoHTML += '<p>Temps de stationnement : ' + capteurData.TempsStationnement + '</p>';
            infoHTML += '<p>ID de la passerelle : ' + capteurData.IDPasserelle + '</p>';

            // Mettre à jour le contenu de la zone d'informations
            infoContainer.innerHTML = infoHTML;
          }
        };
        xhttpInt.open("GET", "recuperer_donnees_capteur_int.php?passerelle=" + selectedPasserelleMAC + "&capteur=" + selectedCapteur, true);
        xhttpInt.send();
      } else if (selectedPasserelle.indexOf("Ext") !== -1) {
        // Effectuer une requête AJAX pour récupérer les données du capteur externe
        var xhttpExt = new XMLHttpRequest();
        xhttpExt.onreadystatechange = function() {
          if (this.readyState === 4 && this.status === 200) {
            var capteurData = JSON.parse(this.responseText);

            // Construire le contenu des informations du capteur externe
            var infoHTML = '<h3>Informations du Capteur</h3>';
            infoHTML += '<p>Etat de la place : ' + capteurData.EtatPlace + '</p>';
            if (capteurData.EtatBatterie == "Na") {
              infoHTML += '<p>Batterie : ' + capteurData.EtatBatterie + '</p>';
            } else {
              infoHTML += '<p>Batterie : ' + capteurData.EtatBatterie + ' %</p>';
            }
            infoHTML += '<p>Qualité du signal : ' + capteurData.QualiteSignal + '</p>';
            infoHTML += '<p>Valeurs du signal : ' + capteurData.SignalNum + ' dbm</p>';
            infoHTML += '<p>Temps de stationnement : ' + capteurData.TempsStationnement + '</p>';
            infoHTML += '<p>Etat du capteur : ' + capteurData.EtatCapteur + '</p>';
            infoHTML += '<p>ID de la passerelle : ' + capteurData.IDPasserelle + '</p>';

            // Mettre à jour le contenu de la zone d'informations
            infoContainer.innerHTML = infoHTML;
          }
        };
        xhttpExt.open("GET", "recuperer_donnees_capteur_ext.php?passerelle=" + selectedPasserelleMAC + "&capteur=" + selectedCapteur, true);
        xhttpExt.send();
      }

      infoContainer.style.display = "block"; // Affiche la div d'informations
    } else {
      // Réinitialiser le contenu de la zone d'informations
      infoContainer.innerHTML = "";
      infoContainer.style.display = "none"; // Masque la div d'informations si l'une des options est vide
    }
  }
}

setInterval(toggleDropdown2, 1000);

// ---------------------------------------------------- Gestion des Afficheurs ------------------------------------------------

function limitTextareaLength(maxLength) {
  // Récupérer l'élément <textarea>
  var textarea = document.getElementById("messageTextarea");
  
  // Obtenir la longueur actuelle du contenu dans le <textarea>
  var currentLength = textarea.value.length;

  // Vérifier si la longueur actuelle dépasse la longueur maximale spécifiée
  if (currentLength > maxLength) {
    // Tronquer le texte pour qu'il ne dépasse pas la limite
    textarea.value = textarea.value.substring(0, maxLength);
  }
}

function CheckBox(){
  var customCheckbox = document.getElementById('customCheckbox');
  var customDropdown = document.getElementById('customDropdown');
  var definitCheckbox = document.getElementById('definitCheckbox');
  var definitDropdown = document.getElementById('definitDropdown');

  if (customCheckbox.checked){
      customDropdown.style.display = 'block';
      definitCheckbox.disabled = true;
  }
  if (!customCheckbox.checked){
      customDropdown.style.display = 'none';
      definitCheckbox.disabled = false;
  }

  if (definitCheckbox.checked) {
      definitDropdown.style.display = 'block';
      customCheckbox.disabled = true;
  } 
  if (!definitCheckbox.checked) {
      definitDropdown.style.display = 'none';
      customCheckbox.disabled = false;
  }
}

function envoyerMessagePerso() {
  // Récupérer la valeur du champ de texte personnalisé
  var customMessage = document.getElementById('messageTextarea').value;

// Envoyer le message personnalisé via une requête AJAX
var xhr = new XMLHttpRequest();
xhr.open("POST", "http://10.198.214.69:5000/", true);  // Modifier l'URL si nécessaire
xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
xhr.onreadystatechange = function () {
if (xhr.readyState === XMLHttpRequest.DONE && xhr.status === 200) {
// Traitement de la réponse
console.log(xhr.responseText);
}
};

// Concaténer les données à envoyer dans le corps de la requête
var data = "customMessage=" + encodeURIComponent(customMessage);

xhr.send(data);

}


function envoyerDonnees() {
  // Récupérer les valeurs sélectionnées
  var selectElement = document.getElementById("messages");
  var Id_Message_Register = selectElement.value;
  var Contenu = selectElement.options[selectElement.selectedIndex].text.split(" - ")[1];
  var Type = selectElement.options[selectElement.selectedIndex].text.split(" - ")[2];

  // Envoyer les données via une requête AJAX
  var xhr = new XMLHttpRequest();
  xhr.open("POST","http://10.198.214.69:5000/", true);  // Modifier l'URL si nécessaire
  xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
  xhr.onreadystatechange = function () {
      if (xhr.readyState === XMLHttpRequest.DONE && xhr.status === 200) {
          // Traitement de la réponse
          console.log(xhr.responseText);
      }
  };

  // Concaténer les données à envoyer dans le corps de la requête
  // Concaténer les données à envoyer dans le corps de la requête
  var data = "Id_Message_Register=" + Id_Message_Register + "&Contenu=" + encodeURIComponent(Contenu);
  xhr.send(data);
}

// Fonction pour mettre à jour le contenu du conteneur du tableau
function mettreAJourTableau() {
  // Envoyer une requête AJAX pour récupérer les données de la table historiquemess
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "get.php", true);  // Remplacez "get.php" par le nom de votre script PHP pour récupérer les données
  xhr.onreadystatechange = function() {
      if (xhr.readyState === XMLHttpRequest.DONE && xhr.status === 200) {
          // Traitement de la réponse
          var donnees = JSON.parse(xhr.responseText);

          // Construire le tableau HTML
          var table = document.createElement("table");
          table.innerHTML = "<tr><th>Id_HistoriqueMess</th><th>DATE</th><th>Id_Message_Register</th><th>Contenu</th><th>Contenu_Mess_Perso</th></tr>";

          for (var i = 0; i < donnees.length; i++) {
              var row = table.insertRow();
              row.insertCell().textContent = donnees[i].Id_HistoriqueMess;
              row.insertCell().textContent = donnees[i].Date;
              row.insertCell().textContent = donnees[i].Id_Message_Register;
              row.insertCell().textContent = donnees[i].Contenu;
              row.insertCell().textContent = donnees[i].Contenu_Mess_Perso;
          }

          // Obtenir l'élément conteneur existant dans votre page HTML
          var container = document.querySelector(".table-container");
          // Remplacer le contenu actuel par le nouveau tableau
          container.innerHTML = "";
          container.appendChild(table);
      }
  };

  xhr.send();
}

// Appeler la fonction pour mettre à jour le tableau lors du chargement de la page
window.onload = mettreAJourTableau;

// Mettre à jour le contenu du conteneur du tableau toutes les 5 secondes (5000 millisecondes)
setInterval(mettreAJourTableau, 5000);

// -------------------------------------------------- Gestion du bouton log out --------------------------------------------------

function logout() {
  window.location.href = "logout.php";
}