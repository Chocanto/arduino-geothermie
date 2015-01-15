

// methode pour afficher ou non les courbes 2 et 3,
// dans le graph 1
var cpt=0;
function afficher(){
	if(cpt%2==0){
    	chart.hide(['Sonde2', 'Sonde3']);
    	cpt++;
    }
    else{
    	chart.show(['Sonde2', 'Sonde3']);
    	cpt++;
    }

}


// methode pour remplir le tableau
function lister(id, list){
	var elem="";
	for (var i = 0; i < list.length; i++) {
		if(i==0){
			elem+="<td style='font-weight:bold'>"+list[i]+"</td>";
			i++;
		}
		elem+="<td>"+list[i]+"</td>";
	}
	document.getElementById(id).innerHTML+="<tr>"+elem+"</tr>";
}


// methode pour remplire le tableau d'un nouvel valeur
function getOk(tab){
	var add=document.getElementById('add').value;
	tab.push(add);
	chart3.load({columns: [tab]});
}



