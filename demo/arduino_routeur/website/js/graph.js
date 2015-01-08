

// valeur test des tableaux
var sonde1 = ['Sonde1', 30, 200, 100, 400, 150, 250];
var sonde2 = ['Sonde2', 50, 20, 10, 40, 15, 25];
var sonde3 = ['Sonde3', 1.3, 1.5, 2.0, 3.2, 2.8, 1.1];
var x = ['x', '2010-01-01', '2011-01-01', '2012-01-01', '2013-01-01', '2014-01-01', '2015-01-01'];

// remplire le tableaux de valeur
lister("table", sonde1);
lister("table", sonde2);
lister("table", sonde3);


// graph 1
var chart = c3.generate({
	// indique ou l'on affiche, via l'id
    bindto: '#chart',
    data: {
    	// courbe à afficher 
    	columns : [sonde1,sonde2, sonde3] }
    });


// graph 2
var chart2 = c3.generate({
      bindto: '#chart2',
      
      // definir une taille du graph
      size:{height: 240, width:480},

      data: {
        // on dit que l'axe x est representé par le tableau
        // avec comme 1ere arg 'x'
        x: 'x',
        columns: [x,sonde1,sonde3],

        // changer les nom des courbes
        names:{
          Sonde1: 'Violet',
          Sonde3: 'Rouge'
        },

        // changer la couleur des courbes
        colors:{
          Sonde1: '#A462A6',
          Sonde3: '#D6160C',
        },

        // assigner des axes y a chaque sonde
        axes: {
            Sonde1: 'y',
            Sonde3: 'y2'
        }
      },
      axis: {
        
        // parametre l'axe x 
        x:{
          type:'timeseries',
          tick: {format: '%Y'}
        },
        y: {label: 'Km'},
        y2: {show: true, label: 'Temp'}
      }
    });


// graph 3
var tab = ['data',15];
    var chart3 = c3.generate({
      bindto: '#chart3',
      size:{height: 240, width:480},
      data: {
        columns: [tab],
        names:{data:'Temp (°C)'},
        colors:{data:'#008000'}
      },
      // afficher une grille en arrière plan
      grid: {
        x:{show: true},
        y:{show: true}
      },
      
      // deplacer la legend
      legend:{position:'right'},

      // faire disparetre les points
      point:{show:false},

    });

