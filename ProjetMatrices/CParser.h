#ifndef CPARSER_H
#define CPARSER_H

#include <fstream>
#include <stdlib.h>

#include "CException.h"

#define Utilisation_Constructeur_Interdite 41
#define Ouverture_Fichier_Impossible 42

class CParser
{
private:

	char * sBuffer;
	unsigned int uTailleBuffer;
	unsigned int uMaxTailleBuffer;

	/*************************************************
	*****NOM : CParser
	**************************************************
	*****Constructeur par défaut.
	**************************************************
	*****Entrée : /
	*****Nécessite : Ne pas utiliser ce constructeur.
	*****Sortie : /
	*****Entraîne : Création d'un objet CParser n'ayant lu aucun fichier.
	*************************************************/
	CParser();

public:

	/*************************************************
	*****NOM : CParser
	**************************************************
	*****Constructeur de confort.
	**************************************************
	*****Entrée : le chemin du fichier sPath.
	*****Nécessite : Les caractères \ devant être échappé, il est nécessaire de les doubler.
	*****Sortie : /
	*****Entraîne : Création d'un objet CParser ayant lu le fichier se trouvant en sPath.
	*************************************************/
	CParser(const char * sPath);

	/*************************************************
	*****NOM : ~CParser
	**************************************************
	*****Destructeur par défaut.
	**************************************************
	*****Entrée : /
	*****Nécessite : /
	*****Sortie : /
	*****Entraîne : L'objet est prêt à être désalloué.
	*************************************************/
	~CParser();

	/*************************************************
	*****NOM : PARLire
	**************************************************
	*****Accesseur en lecture de sBuff.
	**************************************************
	*****Entrée : /
	*****Nécessite : /
	*****Sortie : sBuff
	*****Entraîne : /
	*************************************************/
	char * PARLire();

	/*************************************************
	*****NOM : PARLireFichier
	**************************************************
	*****Lis le contenue d'un fichier.
	**************************************************
	*****Entrée : le chemin du fichier sPath.
	*****Nécessite : Les caractères \ devant être échappé, il est nécessaire de les doubler.
	*****Sortie : /
	*****Entraîne : /
	*************************************************/
	void PARLireFichier(const char * sPath);

	/*************************************************
	*****NOM : PARVider
	**************************************************
	*****Vide le buffer.
	**************************************************
	*****Entrée : /
	*****Nécessite : /
	*****Sortie : /
	*****Entraîne : /
	*************************************************/
	void PARVider();
};

#endif