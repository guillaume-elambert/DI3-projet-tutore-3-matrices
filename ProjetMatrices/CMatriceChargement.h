#ifndef CMATRICECHARGEMENT_H
#define CMATRICECHARGEMENT_H

#include "CMatrice.h"
#include "CException.h"
#include "CParser.h"

#define ChaineNulle 20

#define SyntaxeTypeInvalide 21
#define SyntaxeLignesInvalide 22
#define SyntaxeColonnesInvalide 23
#define SyntaxeDelimiteursInvalide 24

#define TypeInvalide 25
#define DimensionLignesInvalide 26
#define DimensionColonnesInvalide 27

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