#ifndef CMATRICE_CPP
#define CMATRICE_CPP

#include "CMatrice.h"
#include "CException.h"
#include <sstream>

/*!
 * Constructeur par défaut
 * Créé un objet CMatrice de taille 1*1 et d'argument MATMAtrice = {{0}}.
 *
 */
template <class MATType>
CMatrice<MATType>::CMatrice()
{
	uMATNBLignes = 1;
	uMATNBColonnes = 1;
	MATMatrice = (MATType **)malloc(sizeof(MATType *) * 1);
	MATMatrice[0] = (MATType *)malloc(sizeof(MATType) * 1);
	MATMatrice[0][0] = NULL;
}


/*!
 * Constructeur de recopie
 *
 * \param MATParam<MATType> L'objet CMatrice<MATType> à copier
 * \pre MATParam != NULL
 */
template <class MATType>
CMatrice<MATType>::CMatrice(CMatrice<MATType> & MATParam)
{
	MATCopyContentFrom(MATParam);
}


/*!
 * Constructeur de confort.
 * Créé un objet de la classe CMatrice<MATType> dont toutes les cases auront pour valeur valeur
 *
 * \param uNBLignes Nombre de lignes de la matrice à créer
 * \param uNBColonnes Nombre de colonnes de la matrice à créer
 * \param valeur Valeur par défaut de chaque case de la matrice
 * \pre uNBLigne > 0 && uNBColonne > 0
 */
template <class MATType>
CMatrice<MATType>::CMatrice(unsigned int uNBLignes, unsigned int uNBColonnes, MATType valeur)
{
	//Lever exception
	if (uNBLignes <= 0)
	{
		throw(CException(Ligne_InfEg_Zero));
	}

	if (uNBColonnes <= 0)
	{
		throw(CException(Colonne_InfEg_Zero));
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


/*!
 * Constructeur de confort.
 *
 * \param uNBLignes Nombre de lignes de la matrice à créer
 * \param uNBColonnes Nombre de colonnes de la matrice à créer
 * \param matrice Un tableau à deux dimensions de type MATType à recopier dans la matrice à créer
 * \pre uNBLigne > 0 &&  uNBColonne > 0 && dimension de matrice <= uNBColonne && dimension de matrice[0] <= uNBLigne..
 */
template <class MATType>
CMatrice<MATType>::CMatrice(unsigned int uNBLignes, unsigned int uNBColonnes, MATType * matrice[])
{
	//Lever exception
	if (uNBLignes <= 0) {
		throw(CException(Ligne_InfEg_Zero));
	}

	if (uNBColonnes <= 0) {
		throw(CException(Colonne_InfEg_Zero));
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


/*!
 * Destructeur par défaut.
 * Entraîne la désallocation du tableau de la matrice.
 *
 */
template <class MATType>
CMatrice<MATType>::~CMatrice()
{
	for (unsigned int uLigneCourante = 0; uLigneCourante < uMATNBLignes; uLigneCourante++)
	{
		free(MATMatrice[uLigneCourante]);
	}
	free(MATMatrice);
}


/*!
 * Méthode qui copie le contenu de la matrice passée en paramètre dans l'objet appelant
 *
 * \param MATParam Objet CMatrice<MATType> qui va être copié dans l'objet appelant
 * \pre MATParam != NULL
 */
template<class MATType>
void CMatrice<MATType>::MATCopyContentFrom(const CMatrice<MATType>& MATParam)
{
	uMATNBLignes = MATParam.uMATNBLignes;
	uMATNBColonnes = MATParam.uMATNBColonnes;

	this->MATMatrice = (MATType **)malloc(sizeof(MATType *) * uMATNBLignes);
	for (unsigned int uLigneCourante = 0; uLigneCourante < uMATNBLignes; uLigneCourante++)
	{
		this->MATMatrice[uLigneCourante] = (MATType *)malloc(sizeof(MATType) * uMATNBColonnes);
		for (unsigned int uColonneCourante = 0; uColonneCourante < uMATNBColonnes; uColonneCourante++)
		{
			this->MATMatrice[uLigneCourante][uColonneCourante] = MATParam.MATMatrice[uLigneCourante][uColonneCourante];
		}
	}
}


/*!
 * Accesseur en lecture de uMATNBLigne
 *
 * \return Le nombre de lignes de la matrice
 */
template <class MATType>
unsigned int CMatrice<MATType>::MATLireNBLignes() {
	return(uMATNBLignes);
}


/*!
 * Accesseur en lecture de uMATNBColonne
 *
 * \return Le nombre de colonnes de la matrice
 */
template <class MATType>
unsigned int CMatrice<MATType>::MATLireNBColonnes() {
	return(uMATNBColonnes);
}


/*!
 * Accesseur en lecture de MATMatrice[uNumeroLigne][uNumeroColonne]
 *
 * \param uNumeroLigne Indice de la ligne souhaitée de MATMatrice
 * \param uNumeroColonne Indice de la colonne souhaitée de MATMatrice
 * \pre uNBLigne > 0 &&  uNBColonne > 0 && dimension de matrice <= uNBColonne && dimension de matrice[0] <= uNBLigne..
 * \return La valeur de la matrice MATMatrice à l'indice [uNumeroLigne][uNumeroColonne]
 */
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

	return this->MATMatrice[uNumeroLigne][uNumeroColonne];
}


/*!
 * Accesseur en écriture de MATMatrice
 *
 * \param uNumeroLigne Indice de la ligne souhaitée de MATMatrice
 * \param uNumeroColonne Indice de la colonne souhaitée de MATMatrice
 * \param valeur La valeur à attribuer à la matrice MATMatrice à l'indice [uNumeroLigne][uNumeroColonne]
 * \pre uNBLigne > 0 &&  uNBColonne > 0 && dimension de matrice <= uNBColonne && dimension de matrice[0] <= uNBLigne.
 */
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


/*!
 * Renvoie la transposée d'un objet CMatrice<MATType>
 *
 * \return Un objet CMatrice<MATType> correspondant à la transposée de la matrice
 */
template<class MATType>
CMatrice<MATType>& CMatrice<MATType>::MATransposeeMatrice()
{
	CMatrice<MATType>* MATNouvelleMatrice = new CMatrice<MATType>(this->uMATNBColonnes, this->uMATNBLignes);

	for (unsigned int uLigneCourante = 0; uLigneCourante < MATNouvelleMatrice->uMATNBLignes; uLigneCourante++) {
		for (unsigned int uColonneCourante = 0; uColonneCourante < MATNouvelleMatrice->uMATNBColonnes; uColonneCourante++) {
			MATNouvelleMatrice->MATModifierCase(uLigneCourante, uColonneCourante, this->MATMatrice[uColonneCourante][uLigneCourante]);
		}
	}

	return *MATNouvelleMatrice;
}


/*!
 * Méthode qui la chaîne de caractère correspondant au contenu de la matrice
 *
 * \return La chaîne de caractère correspondant au contenu de la matrice
 */
template <class MATType>
char * CMatrice<MATType>::MATToString(void)
{

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


/*!
 * Surcharge de l'opérateur =
 *
 * \param MATMatriceParam Objet de classe CMatrice<MATType> à copier
 * \pre MATParam != NULL
 * \return On objet CMatrice<MATType>, copie de MATParam
 */
template <class MATType>
CMatrice<MATType>& CMatrice<MATType>::operator=(const CMatrice<MATType>& MATParam)
{
	if (&MATParam == this)
		return *this;

	for (unsigned int uLigneCourante = 0; uLigneCourante < uMATNBLignes; uLigneCourante++)
	{
		free(this->MATMatrice[uLigneCourante]);
	}
	free(this->MATMatrice);

	this->MATCopyContentFrom(MATParam);
	return *this;
}


/*!
 * Surcharge de l'opérateur []
 * Retourne la ligne de MATMatrice d'indice iIndice
 *
 * \param iIndice L'indice de la ligne de MATMatrice souhaitée
 * \pre iIndice >= 0
 * \return La ligne de MATMatrice d'indice iIndice
 */
template <class MATType>
inline MATType* CMatrice<MATType>::operator[](int iIndice)
{
	return this->MATMatrice[iIndice];
}



/*!
 * Surcharge de l'opérateur *
 *
 * \param MATMatrice Matrice à multiplier
 * \pre MATParam != NULL
 * \return Un objet CMatrice<MATType> correspondant au résultat de la multiplication des 2 matrices
 */
template <class MATType>
CMatrice<MATType> CMatrice<MATType>::operator*(const CMatrice<MATType>& MATParam)
{
	/* On peut seulement multiplier deux matrices si elles ont au moins un
	MEME attribut oppose (ligne et colonne) */
	if (this->uMATNBColonnes != MATParam.uMATNBLignes) {
		throw(CException(Dimension_Incompatible));
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
 * Surcharge de l'opérateur +
 *
 * \param MATMatrice Matrice à additioner
 * \pre MATParam != NULL
 * \return Le résultat de l'addition des 2 matrices
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
		throw(CException(Dimension_Incompatible));
	}

	return *newMatrice;
}


/*!
 * Surcharge de l'opérateur -
 *
 * \param MATMatrice Matrice à soustraire
 * \pre MATParam != NULL
 * \return Un objet CMatrice<MATType> correspondant au résultat de la soustraction des 2 matrices
 */
template <class MATType>
CMatrice<MATType> CMatrice<MATType>::operator-(const CMatrice<MATType>& MATParam)
{
	CMatrice<MATType>* newMatrice = new CMatrice<MATType>();

	//On entre que si les dimensions sont les mêmes
	if (this->uMATNBColonnes == MATParam.uMATNBColonnes
		&&	this->uMATNBLignes == MATParam.uMATNBLignes
		) {

		newMatrice = new CMatrice<MATType>(this->uMATNBLignes, this->uMATNBColonnes);

		for (int i = 0; i < this->uMATNBLignes; ++i) {
			for (int j = 0; j < this->uMATNBColonnes; ++j) {
				newMatrice->MATMatrice[i][j] = this->MATMatrice[i][j] - MATParam.MATMatrice[i][j];
			}
		}
	}
	else {
		throw(CException(Dimension_Incompatible));
	}

	return *newMatrice;
}


/*!
 * Surcharge de l'opérateur cumulé *=
 *
 * \param MATMatrice Matrice à multiplier
 * \pre MATParam != NULL
 * \return Un objet CMatrice<MATType> correspondant au résultat de la multiplication des 2 matrices
 */
template <class MATType>
CMatrice<MATType>& CMatrice<MATType>::operator*=(const CMatrice<MATType>& MATParam)
{
	(*this) = (*this) * MATParam;
	return *this;
}


/*!
 * Surcharge de l'opérateur cumulé +=
 *
 * \param MATMatrice Matrice à additionner
 * \pre MATParam != NULL
 * \return Un objet CMatrice<MATType> correspondant au résultat de l'addition des 2 matrices
 */
template <class MATType>
CMatrice<MATType>& CMatrice<MATType>::operator+=(const CMatrice<MATType>& MATParam)
{
	(*this) = (*this) + MATParam;
	return *this;
}


/*!
 * Surcharge de l'opérateur cumulé -
 *
 * \param MATMatrice Matrice à soustraire
 * \pre MATParam != NULL
 * \return Résutlat de la soustraction des 2 matrices
 */
template<class MATType>
CMatrice<MATType>& CMatrice<MATType>::operator-=(const CMatrice<MATType>& MATParam)
{

	(*this) = (*this) - MATParam;
	return *this;
}


/*!
 * Surcharge de l'opérateur *
 *
 * \param MATScalaire Variable à multiplier
 * \return Un objet CMatrice<MATType> correspondant au résultat de la multiplication de la matrice par le scalaire
 */
template <class MATType>
CMatrice<MATType> CMatrice<MATType>::operator*(const MATType MATScalaire)
{
	CMatrice<MATType> *newMatrice = new CMatrice<MATType>(this->uMATNBLignes, this->uMATNBColonnes);

	for (int i = 0; i < this->uMATNBLignes; ++i) {
		for (int j = 0; j < this->uMATNBColonnes; ++j) {
			newMatrice->MATMatrice[i][j] = this->MATMatrice[i][j] * MATScalaire;
		}
	}

	return *newMatrice;
}


/*!
 * Surcharge de l'opérateur /
 *
 * \param MATScalaire Diviseur
 * \pre MATScalaire != 0
 * \return Un objet CMatrice<MATType> correspondant au résultat de la division de la matrice par le scalaire
 */
template <class MATType>
CMatrice<MATType> CMatrice<MATType>::operator/(const MATType MATScalaire)
{
	CMatrice<MATType>* newMatrice = new CMatrice<MATType>();

	if (MATScalaire != (MATType)0) {

		newMatrice = new CMatrice<MATType>(this->uMATNBLignes, this->uMATNBColonnes);

		for (int i = 0; i < this->uMATNBLignes; ++i) {
			for (int j = 0; j < this->uMATNBColonnes; ++j) {
				newMatrice->MATMatrice[i][j] = this->MATMatrice[i][j] / MATScalaire;
			}
		}
	}

	return *newMatrice;
}


/*!
 * Surcharge de l'opérateur +
 *
 * \param MATScalaire Sacalaire à additions à la matrice
 * \return Un objet CMatrice<MATType> correspondant au résultat de l'addition de la matrice par le scalaire
 */
template<class MATType>
CMatrice<MATType> CMatrice<MATType>::operator+(const MATType MATScalaire)
{
	CMatrice<MATType>* newMatrice = new CMatrice<MATType>(this->uMATNBLignes, this->uMATNBColonnes);

	for (int i = 0; i < this->uMATNBLignes; ++i) {
		for (int j = 0; j < this->uMATNBColonnes; ++j) {
			newMatrice->MATMatrice[i][j] = this->MATMatrice[i][j] + MATScalaire;
		}
	}

	return *newMatrice;
}


/*!
 * Surcharge de l'opérateur -
 * 
 * \param MATScalaire Sacalaire à additions à la matrice
 * \return Un objet CMatrice<MATType> correspondant au résultat de l'addition de la matrice par le scalaire 
 */
template<class MATType>
CMatrice<MATType> CMatrice<MATType>::operator-(const MATType MATScalaire)
{
	CMatrice<MATType>* newMatrice = new CMatrice<MATType>(this->uMATNBLignes, this->uMATNBColonnes);

	for (int i = 0; i < this->uMATNBLignes; ++i) {
		for (int j = 0; j < this->uMATNBColonnes; ++j) {
			newMatrice->MATMatrice[i][j] = this->MATMatrice[i][j] - MATScalaire;
		}
	}

	return *newMatrice;
}


/*!
 * Surcharge de l'opérateur cumulé *
 *
 * \param MATScalaire Sacalaire à multiplier à la matrice
 * \return Un objet CMatrice<MATType> correspondant au résultat de la multiplication de la matrice par le scalaire
 */
template<class MATType>
CMatrice<MATType>& CMatrice<MATType>::operator*=(const MATType MATScalaire)
{
	(*this) = (*this) * MATScalaire;
	return *this;
}


/*!
 * Surcharge de l'opérateur cumulé /
 *
 * \param MATScalaire Sacalaire à diviser à la matrice
 * \return Un objet CMatrice<MATType> correspondant au résultat de la division de la matrice par le scalaire
 */
template<class MATType>
CMatrice<MATType>& CMatrice<MATType>::operator/=(const MATType MATScalaire)
{
	(*this) = (*this) / MATScalaire;
	return *this;
}


/*!
 * Surcharge de l'opérateur cumulé +
 *
 * \param MATScalaire Sacalaire à additionner à la matrice
 * \return Un objet CMatrice<MATType> correspondant au résultat de l'addition de la matrice par le scalaire
 */
template<class MATType>
CMatrice<MATType>& CMatrice<MATType>::operator+=(const MATType MATScalaire)
{
	(*this) = (*this) + MATScalaire;
	return *this;
}


/*!
 * Surcharge de l'opérateur cumulé -
 *
 * \param MATScalaire Sacalaire à soustraire à la matrice
 * \return Un objet CMatrice<MATType> correspondant au résultat de la soustraction de la matrice par le scalaire
 */
template<class MATType>
CMatrice<MATType>& CMatrice<MATType>::operator-=(const MATType MATScalaire)
{
	(*this) = (*this) - MATScalaire;
	return *this;
}

#endif