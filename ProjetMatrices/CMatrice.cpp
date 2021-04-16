#ifndef CMATRICE_CPP
#define CMATRICE_CPP

#include "CMatrice.h"
#include "CException.h"
#include <sstream>

/*************************************************
*****NOM : CMatrice<type>
**************************************************
*****Constructeur par défaut.
**************************************************
*****Entrée : /
*****Nécessite : Ne pas utiliser ce constructeur.
*****Sortie : /
*****Entraîne : Création d'un objet CMatrice de taille 1*1 et d'argument MATMAtrice = {{0}}.
*************************************************/
template <class MATType>
CMatrice<MATType>::CMatrice()
{
	uMATNBLignes = 1;
	uMATNBColonnes = 1;
	MATMatrice = (MATType **)malloc(sizeof(MATType *) * 1);
	MATMatrice[0] = (MATType *)malloc(sizeof(MATType) * 1);
	MATMatrice[0][0] = NULL;
}


template <class MATType>
CMatrice<MATType>::CMatrice(CMatrice<MATType> & MATParam)
{
	uMATNBLignes = MATParam.uMATNBLignes;
	uMATNBColonnes = MATParam.uMATNBColonnes;

	MATMatrice = (MATType **)malloc(sizeof(MATType *) * uMATNBLignes);
	for (unsigned int uLigneCourante = 0; uLigneCourante < uMATNBLignes; uLigneCourante++)
	{
		MATMatrice[uLigneCourante] = (MATType *)malloc(sizeof(MATType) * uMATNBColonnes);
		for (unsigned int uColonneCourante = 0; uColonneCourante < uMATNBColonnes; uColonneCourante++)
		{
			MATMatrice[uLigneCourante][uColonneCourante] = MATParam.MATMatrice[uLigneCourante][uColonneCourante];
		}
	}
}

template <class MATType>
CMatrice<MATType>::CMatrice(unsigned int uNBLignes, unsigned int uNBColonnes, MATType valeur)
{
	//Lever exception
	if (uNBLignes == 0)
	{
		throw(CException(Ligne_Nulle));
	}

	if (uNBColonnes == 0)
	{
		throw(CException(Colonne_Nulle));
	}
	uMATNBLignes = uNBLignes;
	uMATNBColonnes = uNBColonnes;

	MATMatrice = (MATType * *)malloc(sizeof(MATType*) * uMATNBLignes);
	for (unsigned int uLigneCourante = 0; uLigneCourante < uMATNBLignes; uLigneCourante++)
	{
		MATMatrice[uLigneCourante] = (MATType*)malloc(sizeof(MATType) * uMATNBColonnes);
		for (unsigned int uColonneCourante = 0; uColonneCourante < uMATNBColonnes; uColonneCourante++)
		{
			MATMatrice[uLigneCourante][uColonneCourante] = valeur;
		}
	}
}

template <class MATType>
CMatrice<MATType>::CMatrice(unsigned int uNBLignes, unsigned int uNBColonnes, MATType * matrice[])
{
	//Lever exception
	if (uNBLignes == 0) {
		throw(CException(Ligne_Nulle));
	}

	if (uNBColonnes == 0) {
		throw(CException(Colonne_Nulle));
	}

	/*On met à jour les dimensions*/
	uMATNBLignes = uNBLignes;
	uMATNBColonnes = uNBColonnes;

	/*On update l'allocation du nombre de colonne*/
	MATMatrice = (MATType * *)malloc(sizeof(MATType*) * uMATNBLignes);
	for (unsigned int uLigneCourante = 0; uLigneCourante < uMATNBLignes; uLigneCourante++)
	{
		MATMatrice[uLigneCourante] = (MATType*)malloc(sizeof(MATType) * uMATNBColonnes);
		for (unsigned int uColonneCourante = 0; uColonneCourante < uMATNBColonnes; uColonneCourante++)
		{
			MATMatrice[uLigneCourante][uColonneCourante] = matrice[uLigneCourante][uColonneCourante];
		}
	}
}

template <class MATType>
CMatrice<MATType>::~CMatrice()
{
	for (unsigned int uLigneCourante = 0; uLigneCourante < uMATNBLignes; uLigneCourante++)
	{
		free(MATMatrice[uLigneCourante]);
	}
	free(MATMatrice);
}

template <class MATType>
unsigned int CMatrice<MATType>::MATLireNBLignes() {
	return(uMATNBLignes);
}

template <class MATType>
unsigned int CMatrice<MATType>::MATLireNBColonnes() {
	return(uMATNBColonnes);
}

template <class MATType>
MATType CMatrice<MATType>::MATLireCase(unsigned int uNumeroLigne, unsigned int uNumeroColonne)
{
	//Lever une exception
	if (uNumeroLigne >= uMATNBLignes) {
		throw(CException(Index_Ligne_Depassant));
	}

	//Lever une exception
	if (uNumeroColonne >= uMATNBColonnes) {
		throw(CException(Index_Colonne_Depassant));
	}

	return MATMatrice[uNumeroLigne][uNumeroColonne];
}

template <class MATType>
void CMatrice<MATType>::MATModifierCase(unsigned int uNumeroLigne, unsigned int uNumeroColonne, MATType valeur)
{
	//Lever une exception
	if (uNumeroLigne >= uMATNBLignes) {
		throw(CException(Index_Ligne_Depassant));
	}

	//Lever une exception
	if (uNumeroColonne >= uMATNBColonnes) {
		throw(CException(Index_Colonne_Depassant));
	}

	MATMatrice[uNumeroLigne][uNumeroColonne] = valeur;
}

template <class MATType>
char * CMatrice<MATType>::MATToString(void)
{
	/*char *
	for (unsigned int uLigneCourante = 0; uLigneCourante < uMATNBLignes; uLigneCourante++) {
		for (unsigned int uColonneCourante = 0; uColonneCourante < uMATNBColonnes; uColonneCourante++) {
			if (MATLireCase(uLigneCourante, uColonneCourante) == NULL) //cout n'affiche pas les nullptr
				cout << "0" << " ";
			else
				cout << MATLireCase(uLigneCourante, uColonneCourante) << " ";
		}
		cout << endl;
	}*/

	std::stringstream buffer;

	for (int i = 0; i < this->uMATNBLignes; ++i) {
		for (int j = 0; j < this->uMATNBColonnes; ++j) {
			buffer << this->MATMatrice[i][j] << " ";
		}
		buffer << "\n";
	}

	//On convertit le contenu de la variable buffer en char *
	std::string str = buffer.str();
	const char *bufferStr = str.c_str();
	size_t bufferStrLen = strlen(bufferStr) + 1;
	char *toReturn = new char[bufferStrLen];
	strcpy_s(toReturn, bufferStrLen, bufferStr);

	return toReturn;
}

template <class MATType>
void CMatrice<MATType>::operator=(MATType & MATMatriceParam)
{
	for (unsigned int uLigneCourante = 0; uLigneCourante < uMATNBLignes; uLigneCourante++)
	{
		free(MATMatrice[uLigneCourante]);
	}
	free(MATMatrice);

	CMatrice(MATMatriceParam);
}

#endif