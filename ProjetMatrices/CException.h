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

public:


	/*!
	 * Constructeur par défaut
	 * 
	 */
	CException();
	
	/*!
	 * Constructeur de confort
	 * 
	 * \param uErreur Code de l'erreur à attribuer à uEXCErreur
	 */
	CException(unsigned int uErreur);


	/*!
	 * Destructeur par défaut
	 * 
	 */
	~CException();

	
	/*!
	 * Accesseur en lecture du code d'erreur
	 * 
	 * \return Le code de l'erreur
	 */
	unsigned int EXCLireErreur(void);

	
	/*!
	 * Accesseur en écriture du code d'erreur
	 * 
	 * \param uErreur Le code de l'erreur à attribuer à uEXCErreur
	 */
	void EXCModifierErreur(unsigned int uErreur);

	
	/*!
	 * Affiche dans la sortie standard un message d'erreur approprié.
	 * 
	 */
	void EXCAfficherMessageErreur(void);
};

#endif