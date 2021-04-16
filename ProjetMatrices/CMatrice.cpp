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
	MATCopyContentFrom(MATParam);
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

template<class MATType>
void CMatrice<MATType>::MATCopyContentFrom(const CMatrice<MATType>& MATParam)
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
			buffer << this->MATMatrice[i][j] << "\t";
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

template <class MATType>
CMatrice<MATType>& CMatrice<MATType>::operator=(const CMatrice<MATType>& MATParam)
{
	if (&MATParam == this)
		return *this;

	this->MATCopyContentFrom(MATParam);
	return *this;
}

/*!
 * Méthode qui permet de gérer l'addition d'une matrice par une autre
 *
 * \param MATParam Matrice à additioner
 * \return Le résultat de l'addition
 */
template <class MATType>
CMatrice<MATType> CMatrice<MATType>::operator+(const CMatrice<MATType>& MATParam)
{
	CMatrice<MATType>* newMatrice = new CMatrice<MATType>();

	//On entre que si les dimensions sont les mêmes
	if (this->uMATNBColonnes == MATParam.uMATNBColonnes
		&&	this->uMATNBLignes == MATParam.uMATNBLignes
		) {

		newMatrice = new CMatrice<MATType>(this->uMATNBLignes, this->uMATNBColonnes);

		for (int i = 0; i < this->uMATNBLignes; ++i) {
			for (int j = 0; j < this->uMATNBColonnes; ++j) {
				newMatrice->MATMatrice[i][j] = this->MATMatrice[i][j] + MATParam.MATMatrice[i][j];
			}
		}
	}
	else {
		throw "operator+ : Les deux matrices doivent avoir le même nombre de lignes et le même nombre de colonnes.";
	}

	return *newMatrice;
}


/*!
 * Méthode qui permet de gérer la soustraction d'une matrice par une autre
 *
 * \param MATParam Matrice à soustraire
 * \return Résultat de la soustraction
 */
template <class MATType>
CMatrice<MATType> CMatrice<MATType>::operator-(const CMatrice<MATType>& MATParam)
{
	CMatrice<MATType>* newMatrice();

	//On entre que si les dimensions sont les mêmes
	if (this->uMATNBColonnes == MATParam.uMATNBColonnes
		&&	this->uMATNBLignes == MATParam.uMATNBLignes
		) {

		newMatrice = new CMatrice<MATType>(this->uMATNBLignes, this->uMATNBColonnes);

		for (int i = 0; i < this->uMATNBLignes; ++i) {
			for (int j = 0; j < this->uMATNBColonnes; ++j) {
				newMatrice->MATMatrice[i][j] = this->MATMatrice[i][j] - MATParam[i][j];
			}
		}
	}
	else {
		throw "operator- : Les deux matrices doivent avoir le même nombre de lignes et le même nombre de colonnes.";
	}

	return *newMatrice;
}


/*!
 * Méthode qui permet de gérer la multiplication d'une matrice par une autre
 *
 * \param MATParam Matrice à multiplier
 * \return Résultat de la multiplication
 */
template <class MATType>
CMatrice<MATType> CMatrice<MATType>::operator*(const CMatrice<MATType>& MATParam)
{

	/* On peut seulement multiplier deux matrices si elles ont au moins un
	MEME attribut oppose (ligne et colonne) */
	if (this->uMATNBColonnes != MATParam.uMATNBLignes) {
		throw "operator* : Multplication impossible de deux matrices: le nombre de lignes de la matrice 1 est different du nombre de colonnes de la matrice 2";
	}


	CMatrice<MATType>* newMatrice = new CMatrice<MATType>(this->uMATNBLignes, MATParam.uMATNBColonnes);
	MATType tmp;

	for (int i = 0; i < this->uMATNBLignes; i++) {
		for (int j = 0; j < MATParam.uMATNBColonnes; j++) {

			for (int k = 0; k < this->uMATNBColonnes; k++) {

				tmp = this->MATMatrice[i][k] * MATParam.MATMatrice[k][j];
				//On fait newMatrice[i][j] += tmp uniquement si newMatrice[i][j] a déjà pris une valeur
				newMatrice->MATMatrice[i][j] = (k == 0) ? tmp : newMatrice->MATMatrice[i][j] + tmp;

			}
		}
	}

	return *newMatrice;
}


/*!
 * Operateur permettant la multiplication cumulée entre 2 matrices
 *
 * \param MATParam Matrice à multiplier
 * \return Résultat de la multiplication
 */
template <class MATType>
CMatrice<MATType>& CMatrice<MATType>::operator*=(const CMatrice<MATType>& MATParam)
{
	(*this) = (*this) * MATParam;
	return *this;
}


/*!
 * Operateur permettant l'addition cumulée entre 2 matrices
 *
 * \param MATParam Matrice à additionner
 * \return Résultat de l'addition
 */
template <class MATType>
CMatrice<MATType>& CMatrice<MATType>::operator+=(const CMatrice<MATType>& MATParam)
{
	(*this) = (*this) + MATParam;
	return *this;
}


/*!
 * Méthode qui permet de gérer la multiplication d'une matrice par un entier ou un réel
 *
 * \param MATMatrice Variable à multiplier
 * \return Résultat de la multiplication
 */
template <class MATType>
CMatrice<MATType> CMatrice<MATType>::operator*(const MATType MATMScalaire)
{
	CMatrice<MATType> *newMatrice = new CMatrice<MATType>(this->uMATNBLignes, this->uMATNBColonnes);

	for (int i = 0; i < this->uMATNBLignes; ++i) {
		for (int j = 0; j < this->uMATNBColonnes; ++j) {
			newMatrice->MATMatrice[i][j] = this->MATMatrice[i][j] * MATMatrice;
		}
	}

	return *newMatrice;
}


/*!
 * Méthode qui permet de gérer la division d'une matrice par un entier ou un réel
 *
 */
template <class MATType>
CMatrice<MATType> CMatrice<MATType>::operator/(const MATType MATMScalaire)
{
	return CMatrice<MATType>();
}


/*!
 * Opérateur qui retourne la ligne de la matrice d'indice iIndice
 *
 * \param iIndice L'indice de la ligne souhaitée
 * \return Le ligne de la matrice
 */
template <class MATType>
inline MATType* CMatrice<MATType>::operator[](int iIndice)
{
	return this->MATMatrice[iIndice];
}

#endif