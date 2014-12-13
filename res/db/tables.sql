DROP TABLE IF EXISTS Donnees;
DROP TABLE IF EXISTS Branchement;
DROP TABLE IF EXISTS Arduino;
DROP TABLE IF EXISTS Capteur;
DROP TABLE IF EXISTS Dispositif;

CREATE TABLE Dispositif(
	idD		INT		(5) PRIMARY KEY AUTO_INCREMENT,
	nomD		VARCHAR		(40),
	typeD		VARCHAR		(30),
	lieu		VARCHAR		(40),
	posXD		INT		(5),
	posYD		INT		(5),
	posZD		INT		(5)
);

-- Mention pour les capteurs :
-- Il faut entrer dans la colonne type
-- le caractère 'A' si le capteur est de type analogique
-- ou 'N' si le capteur est de type numérique (= digital) 
CREATE TABLE Capteur(
	idC		INT		(5) PRIMARY KEY AUTO_INCREMENT,
	idD		INT		(5) NOT NULL,
	typeC		VARCHAR		(1) NOT NULL,
	unite		VARCHAR		(5),
	nivProfond	INT		(5),
	posXC		INT		(5),
	posYC		INT		(5),	
	posZC		INT		(5),
	CONSTRAINT FKidDCapteur FOREIGN KEY (idD)
		REFERENCES Dispositif(idD)
);

CREATE TABLE Arduino(
	idA		INT		(5) PRIMARY KEY AUTO_INCREMENT,
	nom		VARCHAR		(30),
	nbPAnalog	INT		(2),
	nbPNum		INT		(2)
);

CREATE TABLE Branchement(
	idA		INT		(5) NOT NULL,
	port		INT		(2) UNIQUE NOT NULL,
	idC		INT		(5) UNIQUE NOT NULL,

	PRIMARY KEY (idA, idC),
	CONSTRAINT FKidABranchement FOREIGN KEY (idA)
		REFERENCES Arduino(idA),
	CONSTRAINT FKidCBranchement FOREIGN KEY (idC)
		REFERENCES Capteur(idC)
);

CREATE TABLE Donnees(
	idC 		INT		(5) NOT NULL,
	date 		DATETIME	,
	valeur		INT		(5),
	
	PRIMARY KEY (idC, date),
	CONSTRAINT FKidCDonnees FOREIGN KEY (idC)
		REFERENCES Capteur(idC)
);
