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

	/*!
	 * Charge une matrice depuis un fichier
	 *
	 * \param sChemin Le chemin vers le fichier
	 * \pre sChemin != null
	 * \return Un objet CMatrice initialisé à partir d'un fichier.
	 */
	static CMatrice<double>& MACChargerMatriceFichier(const char* sChemin);

	/*!
	 * Charge une matrice depuis une chaine
	 *
	 * \param sChaine La chaine à convertir en matrice
	 * \pre sChaine != null
	 * \return Un objet CMatrice initialisé à partir de la chaîne de caractères.
	 */
	static CMatrice<double>& MACConversionChaineMatrice(const char* sChaine);
};

#endif