#include "CParser.h"

/*!
 * Constructeur par défaut
 *
 * \pre NE PAS UTILISER CE CONSTRUCTEUR
 */
CParser::CParser()
{
	throw(CException(Utilisation_Constructeur_Interdite));
}


/*!
 * Constructeur de confort
 * Création d'un objet CParser ayant lu le fichier se trouvant en sChemin.
 * 
 * \param sChemin Chemin vers le fichier souhaité
 * \pre sChemin != NULL && le fichier existe
 */
CParser::CParser(const char * sChemin)
{
	if (sChemin == nullptr)
	{
		throw(CException(Ouverture_Fichier_Impossible));
	}
	sBuffer = (char *)malloc(sizeof(char) * 4);
	uTailleBuffer = 0;
	uMaxTailleBuffer = 4;
	ifstream FILfichier(sChemin, ios::in);
	if (FILfichier.fail())
	{
		FILfichier.close();
		throw(CException(Ouverture_Fichier_Impossible));
	}

	this->PARLireFichier(sChemin);
	/*while (FILfichier.get(*sBuffer))
	{
		uTailleBuffer++;
		sBuffer++;

		if (uTailleBuffer == uMaxTailleBuffer)
		{
			sBuffer -= uTailleBuffer;
			sBuffer = (char *)realloc((void *)(sBuffer), uMaxTailleBuffer * 2);
			uMaxTailleBuffer *= 2;
			sBuffer += uTailleBuffer;
		}
	}
	*sBuffer = '\0';

	sBuffer -= uTailleBuffer;

	FILfichier.close();*/
}


/*!
 * Destructeur par défaut
 * 
 */
CParser::~CParser()
{
	free(sBuffer);
}


/*!
 * Accesseur en lecture de sBuffer
 * 
 * \return La chaîne sBuffer correspondant au contenu du fichier
 */
char * CParser::PARLire()
{
	return sBuffer;
}



/*!
 * Méthode que lit le contenu d'un fichier
 * 
 * \param sChemin Le chemin vers le fichier souhaité
 * \pre sChemin != NULL && le fichier existe
 */
void CParser::PARLireFichier(const char * sChemin)
{
	this->PARVider();
	ifstream FILfichier(sChemin, ios::in);
	if (FILfichier.fail())
	{
		FILfichier.close();
		throw(CException(Ouverture_Fichier_Impossible));
	}
	while (FILfichier.get(*sBuffer))
	{
		uTailleBuffer++;
		sBuffer++;
		if (uTailleBuffer == uMaxTailleBuffer)
		{
			sBuffer -= uTailleBuffer;
			sBuffer = (char *)realloc((void *)(sBuffer), uMaxTailleBuffer * 2);
			uMaxTailleBuffer *= 2;
			sBuffer += uTailleBuffer;
		}
	}
	//sBuffer++;
	*sBuffer = '\0';
	//uTailleBuffer++;
	sBuffer -= uTailleBuffer;
	FILfichier.close();
}

/*!
 * Méthode qui désalloue sBuffer
 * 
 */
void CParser::PARVider()
{
	free(sBuffer);
	sBuffer = (char *)malloc(sizeof(char)),
	uTailleBuffer = 0;
	uMaxTailleBuffer = 1;
}
