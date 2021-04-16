#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#include <iostream>

#define Erreur_Par_Defaut 0

using namespace std;

class CException
{
	//Attributs
private:
	unsigned int uEXCErreur;

	//Constructeurs
public:

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
	CException();

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
	CException(unsigned int uErreur);

	//Destructeurs

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
	~CException();

	//Accesseurs

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
	unsigned int EXCLireErreur(void);

	/*************************************************
	*****NOM : EXCModifierErreur
	**************************************************
	*****Accesseur en écriture du code d'erreur
	**************************************************
	*****Entrée : unsigned int uErreur le nouveau code d'erreur.
	*****Nécessite : /
	*****Sortie : IdErreur
	*****Entraine : /
	*************************************************/
	void EXCModifierErreur(unsigned int uErreur);

	/*************************************************
	*****NOM : EXCAfficherMessageErreur
	**************************************************
	*****Affiche dans la sortie standard un message d'erreur approprié.
	**************************************************
	*****Entrée : idErreur
	*****Nécessite : /
	*****Sortie : /
	*****Entraine : /
	*************************************************/
	void EXCAfficherMessageErreur(void);
};
#endif