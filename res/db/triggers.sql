DROP TRIGGER IF EXISTS addBranchement;
DROP TRIGGER IF EXISTS typeCapteur;

DELIMITER //

-- Trigger qui vérifie si le nombre de ports du type de capteur qui doit être branché
-- ne dépasse pas le nombre de ports max du même type sur la carte arduino
CREATE TRIGGER addBranchement
	AFTER INSERT
	ON Branchement
	FOR EACH ROW
	BEGIN
		DECLARE limitePortAtteinte CONDITION FOR SQLSTATE '45000';

		DECLARE nbPortUsed 	INTEGER;
		DECLARE MaxPort 	INTEGER;
		DECLARE typeCapteur 	VARCHAR(1);

		-- Récupération du type de capteur depuis la requête faite
		SELECT typeC INTO typeCapteur
			FROM Capteur
			WHERE idC = NEW.idC;

		-- Récupération du nombre de branchements existants du même type
		-- que celui du capteur de la requête
		SELECT count(*) INTO nbPortUsed
			FROM Branchement NATURAL JOIN Capteur
			WHERE typeC = typeCapteur;

		-- Récupération du nombre de ports max de la carte arduino
		-- du même type que celui du capteur de la requête
		IF (typeCapteur= "A") THEN
			SELECT nbPAnalog INTO MaxPort
				FROM Arduino
				WHERE idA = NEW.idA;
		ELSE
			SELECT nbPNum INTO MaxPort
				FROM Arduino
				WHERE idA = NEW.idA;
		END IF;

		IF (nbPortUsed > MaxPort) THEN
			SIGNAL SQLSTATE '45000'
			SET MESSAGE_TEXT='Tous les ports de ce type sont utilisés',
				MYSQL_ERRNO = 6666;
		END IF;
	END//

-- Trigger qui vérifie si le type de capteur entré à l'insertion est valide
CREATE TRIGGER typeCapteur
	AFTER INSERT
	ON Capteur
	FOR EACH ROW
	BEGIN
		DECLARE typeInvalide CONDITION FOR SQLSTATE '45000';

		IF (NEW.typeC!="A" && NEW.typeC!="N") THEN
			SIGNAL SQLSTATE '45000'
			SET MESSAGE_TEXT="Le type de capteur est invalide. Il doit être de type 'A' pour analogique ou 'N' pour numérique .",
				MYSQL_ERRNO=6667;
		END IF;
	END //
DELIMITER ;
