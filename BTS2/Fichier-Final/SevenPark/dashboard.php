<?php
    session_start();
    include("connection.php");
    include("functions.php");

    // Vérifier si l'utilisateur est connecté
    if(!isset($_SESSION['user_id']))
    {
      header("Location: login.php");
      die;
    }

    // Mettre à jour les données du graphique
    $nb_libre = 0;
    $nb_prise = 0;
    $avg_temperature = 0;
    $avg_humidite = 0;
    $avg_pression = 0;
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dashboard</title>
    <script src="javascript.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <link rel="stylesheet" href="style-dashboard.css">
</head>
<body onload="updateData()">
    <div class="top-bar-container">
        <div class="top-bar-left">
            <div class="top-bar-logo-container"></div>
        </div>
        <div class="top-bar-right">
          <button id="logout" onclick="logout()"></button>
        </div>
    </div>

    <div class="navbar">
        <div class="navbar__menu">
            <ul>
                <li><a href="dashboard.php">Dashboard</a></li>
                <li><a href="passerelles.php">Passerelles</a></li>
                <li><a href="capteur.php">Capteur</a></li>
                <li><a href="capteurEnv.php">Capteur Environnemental</a></li>
                <li><a href="afficheur.php">Afficheur</a></li>
            </ul>
        </div>
    </div>

    <div class="switch-container">
        <input type="checkbox" class="theme-light" onchange="toggleTheme()" id="switch" />
        <label for="switch"></label>
    </div>

    <div class="overview-container">
        <p>Dashboard</p>
    </div>

    <section class="card-container">
        <article class="card1">
          <div class="card1__logo" aria-hidden="true"></div>
          <header class="card1__header">
            <h2 class="card1__title">Nombre de places total</h2>
          </header>
          <div class="card1__content">
            <p class="card1__value" id="nb-total"><?php echo $nb_libre + $nb_prise; ?></p>
          </div>
        </article>
      
        <article class="card2">
          <div class="card2__logo" aria-hidden="true"></div>
          <header class="card2__header">
            <h2 class="card2__title">Nombre de places libre</h2>
          </header>
          <div class="card2__content">
            <p class="card2__value" id="nb-libre"><?php echo $nb_libre; ?></p>
          </div>
        </article>
      
        <article class="card3">
          <div class="card3__logo" aria-hidden="true"></div>
          <header class="card3__header">
            <h2 class="card3__title">Nombre de places prise</h2>
          </header>
          <div class="card3__content">
            <p class="card3__value" id="nb-prise"><?php echo $nb_prise; ?></p>
          </div>
        </article>
      </section>      

    <div class="graph-container">
        <div class="graph1">
            <canvas id="piechart"></canvas>
        </div>
        <div class="graph2">
            <canvas id="barchart"></canvas>
        </div>
    </div>

    <script>
      const nb_libre = <?php echo $nb_libre; ?>;
      const nb_prise = <?php echo $nb_prise; ?>;

      const ctx1 = document.getElementById('piechart');

      const myChart1 = new Chart(ctx1, {
          type: 'pie',
          data: {
              labels: ['Places libres', 'Places prises'],
              datasets: [
                  {
                      data: [nb_libre, nb_prise],
                      backgroundColor: ['#24C486', '#F7003D']
                  }
              ]
          },
          options: {
              title: {
                  display: true,
                  text: 'Nombre de places libres et prises'
              }
          },
          plugins: {
              legend: {
                  labels: {
                      color: 'black'
                  }
              }
          }
      });

      const ctx2 = document.getElementById('barchart');

      const myChart2 = new Chart(ctx2, {
        type: 'bar',
        data: {
          labels: ['Température', 'Humidité'],
          datasets: [{
            label: 'Moyenne des capteurs environnementaux',
            data: [<?php echo $avg_temperature; ?>, <?php echo $avg_humidite; ?>],
            backgroundColor: ['#37ED7E', '#119A8E'],
            yAxisID: 'y-axis-1'
          }]
        },
        options: {
          title: {
            display: true,
            text: 'Moyenne des capteurs environnementaux'
          },
          scales: {
            yAxes: [{
              id: 'y-axis-1',
              position: 'left',
              ticks: {
                beginAtZero: true
              }
            }, {
              id: 'y-axis-2',
              position: 'right',
              ticks: {
                beginAtZero: true
              }
            }]
          }
        }
      });

      // Mettre à jour les données du graphique
      function updateChart(nb_libre, nb_prise) {
          myChart1.data.datasets[0].data = [nb_libre, nb_prise];
          myChart2.data.datasets[0].data = [temperature, humidite, pression];
          myChart1.update();
          myChart2.update();
      }
	  </script>

</body>
</html>