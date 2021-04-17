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

	/*!
	 * Constructeur par défaut
	 *
	 */
	CParser();

public:

	/*!
	 * Constructeur de confort
	 * Création d'un objet CParser ayant lu le fichier se trouvant en sChemin.
	 *
	 * \param sChemin Chemin vers le fichier souhaité
	 * \pre sChemin != NULL && le fichier existe
	 */
	CParser(const char * sPath);


	/*!
	 * Destructeur par défaut
	 *
	*/
	~CParser();

	
	/*!
	 * Accesseur en lecture de sBuffer
	 *
	 * \return La chaîne sBuffer correspondant au contenu du fichier
	 */
	char * PARLire();

	
	/*!
	 * Méthode que lit le contenu d'un fichier
	 *
	 * \param sChemin Le chemin vers le fichier souhaité
	 * \pre sChemin != NULL && le fichier existe
	 */
	void PARLireFichier(const char * sPath);


	/*!
	 * Méthode qui désalloue sBuffer
	 *
	*/
	void PARVider();
};

#endif