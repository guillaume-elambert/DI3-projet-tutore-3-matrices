#include "CException.h"


/*!
 * Constructeur par défaut
 *
 */
CException::CException()
{
	uEXCErreur = Erreur_Par_Defaut;
}

/*!
 * Constructeur de confort
 *
 * \param uErreur Code de l'erreur à attribuer à uEXCErreur
 */
CException::CException(unsigned int uErreur)
{
	uEXCErreur = uErreur;
}

/*!
 * Destructeur par défaut
 *
 */
CException::~CException()
{

}

/*!
 * Accesseur en lecture du code d'erreur
 *
 * \return Le code de l'erreur
 */
unsigned int CException::EXCLireErreur(void)
{
	return uEXCErreur;
}

/*!
 * Accesseur en écriture du code d'erreur
 *
 * \param uErreur Le code de l'erreur à attribuer à uEXCErreur
 */
void CException::EXCModifierErreur(unsigned int uErreur)
{
	uEXCErreur = uErreur;
}

/*!
 * Affiche dans la sortie standard un message d'erreur approprié.
 *
 */
void CException::EXCAfficherMessageErreur(void)
{
	cerr << "Exception : ";
	switch (uEXCErreur) {

		/*Erreur par defaut*/
	case Erreur_Par_Defaut:
		cerr << "Exception par defaut";
		break;


		/*CMatrice*/
	case 1: //Ligne_InfEg_Zero
		cerr << "Une matrice doit avoir au moins 1 ligne";
		break;
	case 2: //Colonne_InfEg_Zero
		cerr << "Une matrice doit avoir au moins 1 colonne";
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
	case 6: //Dimension_Incompatible
		cerr << "Les 2 matrices ont des dimensions incompatibles pour ce type d'opération";
		break;


		/*CMatriceChargement*/
	case 20: //RegexVide
		cerr << "Impossible d'obtenir l'expression régulière.";
		break;

	case 21: //ChaineNulle
		cerr << "Il est nécessaire de passer un chemin";
		break;

	case 22: //SyntaxeTypeInvalide
		cerr << "La ligne contenant le type de la matrice ne correspond pas à l'expression régulière attendue";
		break;

	case 23: //SyntaxeLignesInvalide
		cerr << "La ligne contenant le nombre de lignes de la matrice ne correspond pas à l'expression régulière attendue";
		break;

	case 24: //SyntaxeColonnesInvalide
		cerr << "La ligne contenant le nombre de colonnes de la matrice ne correspond pas à l'expression régulière attendue";
		break;

	case 25: //SyntaxeDelimiteursInvalide
		cerr << "Les délimiteurs de l'initialisation des valeurs de la matrice ne correspondent pas à l'expression régulière attendue";
		break;

	case 26: //TypeInvalide
		cerr << "Le type défini n'est pas valide";
		break;

	case 27: //DimensionLignesInvalide
		cerr << "Le nombre de lignes obtenu est différent de celui qui a été défini";
		break;

	case 28: //DimensionColonnesInvalide
		cerr << "Le nombre de colonnes obtenu est différent de celui qui a été défini";
		break;


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
