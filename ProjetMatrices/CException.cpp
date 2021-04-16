#include "CException.h"


/*************************************************
*****NOM : CException
**************************************************
*****Constructeur par défaut
**************************************************
*****Entrée : /
*****Nécessite : /
*****Sortie : /
*****Entraine : /
*************************************************/
CException::CException()
{
	uEXCErreur = Erreur_Par_Defaut;
}

/*************************************************
*****NOM : CException
**************************************************
*****Constructeur de confort
**************************************************
*****Entrée : unsiged int uErreur le code d'erreur.
*****Nécessite : /
*****Sortie : /
*****Entraine : /
*************************************************/
CException::CException(unsigned int uErreur)
{
	uEXCErreur = uErreur;
}

/*************************************************
*****NOM : ~CException
**************************************************
*****Destructeur par défaut
**************************************************
*****Entrée : /
*****Nécessite : /
*****Sortie : /
*****Entraine : /
*************************************************/
CException::~CException()
{

}

/*************************************************
*****NOM : EXCLireErreur
**************************************************
*****Accesseur en lecture du code d'erreur
**************************************************
*****Entrée : /
*****Nécessite : /
*****Sortie : uErreur
*****Entraine : /
*************************************************/
unsigned int CException::EXCLireErreur(void)
{
	return uEXCErreur;
}

/*************************************************
*****NOM : EXCModifierErreur
**************************************************
*****Accesseur en écriture du code d'erreur
**************************************************
*****Entrée : unsigned int uErreur le nouveau code d'erreur.
*****Nécessite : /
*****Sortie : /
*****Entraine : /
*************************************************/
void CException::EXCModifierErreur(unsigned int uErreur)
{
	uEXCErreur = uErreur;
}

/*************************************************
*****NOM : EXCAfficherMessageErreur
**************************************************
*****Affiche dans la sortie standard un message d'erreur approprié.
**************************************************
*****Entrée : /
*****Nécessite : /
*****Sortie : /
*****Entraine : /
*************************************************/
void CException::EXCAfficherMessageErreur(void)
{
	cerr << "Exception : ";
	switch (uEXCErreur) {
		/*Erreur par defaut*/
	case Erreur_Par_Defaut:
		cerr << "Exception par defaut";
		break;

		/*CMatrice*/
	case 1: //Ligne_Nulle
		cerr << "Une matrice ne peut avoir 0 lignes";
		break;
	case 2: //Colonne_Nulle
		cerr << "Une matrice ne peut avoir 0 colonness";
		break;
	case 3: //Index_Ligne_Depassant
		cerr << "Index de ligne dépasse la longueur du tableau";
		break;
	case 4: //Index_Colonne_Depassant
		cerr << "Index de colonne dépasse la longueur du tableau";
		break;
	case 5: //Affichage_Impossible
		cerr << "CMatriceAfficher utilisant \"cout\", impossible d'afficher des valeur nulle";
		break;

		/*CMatriceOperation*/
	case 10: //Dimension_Incompatible
		cerr << "Les 2 matrices ont des dimensions incompatibles pour ce type d'opération";
		break;

		/*CMatriceChargement*/
	case 20: //SyntaxeNonValide
		cerr << "La synthaxe du fichier ne correspond pas é celle d'une matrice";
		break;

	case 21: //TypeInvalide
		cerr << "Le type de la matrice est censé étre double";
		break;

		/*CStringUtil*/
	case 30: //ChaineNulle
		cerr << "La chaine de caractére est nulle mais ne devrait pas l'étre";

	case 31: //ChaineVide
		cerr << "La chaine de caractére est vide mais ne drait pas l'étre";
		break;

	case 32: // DebutChaineNonValide
		cerr << "La chaine devrait commencer par un nombre";

		/*CParser*/
	case 41: //Utilisation_Constructeur_Interdite:
		cerr << "Le constructeur CParser() ne doit pas étre utilisé";
		break;
	case 42: //Ouverture_Fichier_Impossible:
		cerr << "Le chemin du fichier spécifié est invalide";
		break;
	default:
		cerr << "Erreur numero " << uEXCErreur;
	}
	cerr << endl;

}
