#ifndef CMATRICECHARGEMENT_H
#define CMATRICECHARGEMENT_H

#include "CMatrice.h"
#include "CException.h"
#include "CParser.h"

#define RegexVide 20
#define ChaineNulle 21

#define SyntaxeTypeInvalide 22
#define SyntaxeLignesInvalide 23
#define SyntaxeColonnesInvalide 24
#define SyntaxeDelimiteursInvalide 25

#define TypeInvalide 26
#define DimensionLignesInvalide 27
#define DimensionColonnesInvalide 28

class CMatriceChargement
{
public:

	/*************************************************
	*****NOM : MACConversionChaineMatrice
	**************************************************
	*****Charge une matrice depuis un fichier
	**************************************************
	*****Entrée : sChemin, le chemin du fichier.
	*****Nécessite : sChemin != null
	*****Sortie : Un objet CMatrice initialisé à partir d'un fichier.
	*****Entraine : /
	*************************************************/
	static CMatrice<double>& MACChargerMatriceFichier(const char* sChemin);

	/*************************************************
	*****NOM : MACConversionChaineMatrice
	**************************************************
	*****Charge une matrice depuis une chaine
	**************************************************
	*****Entrée : sChaine, la chaine à convertir
	*****Nécessite : sChaine != null
	*****Sortie : Un objet CMatrice initialisé à partir d'une chaine.
	*****Entraine : /
	*************************************************/
	static CMatrice<double>& MACConversionChaineMatrice(const char* sChaine);
};

#endif