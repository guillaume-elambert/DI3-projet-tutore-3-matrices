#ifndef CMATRICE_H
#define CMATRICE_H

#include <iostream>
#include "CException.h"

#define Ligne_InfEg_Zero 1
#define Colonne_InfEg_Zero 2
#define Index_Ligne_Depassant 3
#define Index_Colonne_Depassant 4
#define Affichage_Impossible 5
#define Dimension_Incompatible 6


template <class MATType>
class CMatrice
{
	//Attributs
private:
	unsigned int uMATNBLignes;
	unsigned int uMATNBColonnes;
	MATType ** MATMatrice;
	//Constructeurs

public:

	/*!
	 * Constructeur par défaut
	 * Créé un objet CMatrice de taille 1*1 et d'argument MATMAtrice = {{0}}.
	 * 
	 */
	CMatrice<MATType>();


	/*!
	 * Constructeur de recopie
	 * 
	 * \param MATParam<MATType> L'objet CMatrice<MATType> à copier
	 * \pre MATParam != NULL
	 */
	CMatrice<MATType>(CMatrice<MATType> & MATParam);


	/*!
	 * Constructeur de confort.
	 * Créé un objet de la classe CMatrice<MATType> dont toutes les cases auront pour valeur valeur
	 * 
	 * \param uNBLignes Nombre de lignes de la matrice à créer
	 * \param uNBColonnes Nombre de colonnes de la matrice à créer
	 * \param valeur Valeur par défaut de chaque case de la matrice
	 * \pre uNBLigne > 0 && uNBColonne > 0
	 */
	CMatrice<MATType>(unsigned int uNBLignes, unsigned int uNBColonnes, MATType valeur = NULL);

	
	/*!
	 * Constructeur de confort.
	 * 
	 * \param uNBLignes Nombre de lignes de la matrice à créer
	 * \param uNBColonnes Nombre de colonnes de la matrice à créer
	 * \param matrice Un tableau à deux dimensions de type MATType à recopier dans la matrice à créer
	 * \pre uNBLigne > 0 &&  uNBColonne > 0 && dimension de matrice <= uNBColonne && dimension de matrice[0] <= uNBLigne..
	 */
	CMatrice<MATType>(unsigned int uNBLignes, unsigned int uNBColonnes, MATType * matrice[]);


	/*!
	 * Destructeur par défaut.
	 * Entraîne la désallocation du tableau de la matrice.
	 * 
	 */
	~CMatrice<MATType>();

	
	/*!
	 * Méthode qui copie le contenu de la matrice passée en paramètre dans l'objet appelant
	 * 
	 * \param MATParam Objet CMatrice<MATType> qui va être copié dans l'objet appelant
	 * \pre MATParam != NULL
	 */
	void MATCopyContentFrom(const CMatrice<MATType>& MATParam);

		
	/*!
	 * Accesseur en lecture de uMATNBLigne
	 * 
	 * \return Le nombre de lignes de la matrice
	 */
	unsigned int MATLireNBLignes(void);

	
	/*!
	 * Accesseur en lecture de uMATNBColonne
	 * 
	 * \return Le nombre de colonnes de la matrice
	 */
	unsigned int MATLireNBColonnes(void);

	
	/*!
	 * Accesseur en lecture de MATMatrice[uNumeroLigne][uNumeroColonne]
	 * 
	 * \param uNumeroLigne Indice de la ligne souhaitée de MATMatrice
	 * \param uNumeroColonne Indice de la colonne souhaitée de MATMatrice
	 * \pre uNBLigne > 0 &&  uNBColonne > 0 && dimension de matrice <= uNBColonne && dimension de matrice[0] <= uNBLigne..
	 * \return La valeur de la matrice MATMatrice à l'indice [uNumeroLigne][uNumeroColonne]
	 */
	MATType MATLireCase(unsigned int uNumeroLigne, unsigned int uNumeroColonne);

	
	/*!
	 * Accesseur en écriture de MATMatrice
	 * 
	 * \param uNumeroLigne Indice de la ligne souhaitée de MATMatrice
	 * \param uNumeroColonne Indice de la colonne souhaitée de MATMatrice
	 * \param valeur La valeur à attribuer à la matrice MATMatrice à l'indice [uNumeroLigne][uNumeroColonne]
	 * \pre uNBLigne > 0 &&  uNBColonne > 0 && dimension de matrice <= uNBColonne && dimension de matrice[0] <= uNBLigne.
	 */
	void MATModifierCase(unsigned int uNumeroLigne, unsigned int uNumeroColonne, MATType valeur);


	/*!
	 * Renvoie la transposée d'un objet CMatrice<MATType>
	 *
	 * \return Un objet CMatrice<MATType> correspondant à la transposée de la matrice
	 */
	CMatrice<MATType>& MATransposeeMatrice();


	/*!
	 * Méthode qui la chaîne de caractère correspondant au contenu de la matrice
	 * 
	 * \return La chaîne de caractère correspondant au contenu de la matrice
	 */
	char * MATToString(void);

	
	/*!
	 * Surcharge de l'opérateur =
	 *
	 * \param MATMatriceParam Objet de classe CMatrice<MATType> à copier
	 * \pre MATParam != NULL
	 * \return On objet CMatrice<MATType>, copie de MATParam
	 */
	CMatrice<MATType>& operator=(const CMatrice<MATType>& MATParam);


	/*!
	 * Surcharge de l'opérateur []
	 * Retourne la ligne de MATMatrice d'indice iIndice
	 * 
	 * \param iIndice L'indice de la ligne de MATMatrice souhaitée
	 * \pre iIndice >= 0
	 * \return La ligne de MATMatrice d'indice iIndice
	 */
	MATType* operator[](int iIndice);



	/*---------------------------------------------------------*/
	/*---------------- Operations matricielles ----------------*/
	/*---------------------------------------------------------*/

	/*!
	 * Surcharge de l'opérateur *
	 *
	 * \param MATMatrice Matrice à multiplier
	 * \pre MATParam != NULL
	 * \return Un objet CMatrice<MATType> correspondant au résultat de la multiplication des 2 matrices
	 */
	CMatrice<MATType> operator*(const CMatrice<MATType>& MATParam);


	/*!
	 * Surcharge de l'opérateur +
	 *
	 * \param MATMatrice Matrice à additioner
	 * \pre MATParam != NULL
	 * \return Le résultat de l'addition des 2 matrices
	 */
	CMatrice<MATType> operator+(const CMatrice<MATType>& MATParam);


	/*!
	 * Surcharge de l'opérateur -
	 *
	 * \param MATMatrice Matrice à soustraire
	 * \pre MATParam != NULL
	 * \return Un objet CMatrice<MATType> correspondant au résultat de la soustraction des 2 matrices
	 */
	CMatrice<MATType> operator-(const CMatrice<MATType>& MATParam);



	/*---------------------------------------------------------*/
	/*------------ Operations matricielles cumulées -----------*/
	/*---------------------------------------------------------*/


	/*!
	 * Surcharge de l'opérateur cumulé *=
	 *
	 * \param MATMatrice Matrice à multiplier
	 * \pre MATParam != NULL
	 * \return Un objet CMatrice<MATType> correspondant au résultat de la multiplication des 2 matrices
	 */
	CMatrice<MATType>& operator*=(const CMatrice<MATType>& MATParam);


	/*!
	 * Surcharge de l'opérateur cumulé +=
	 *
	 * \param MATMatrice Matrice à additionner
	 * \pre MATParam != NULL
	 * \return Un objet CMatrice<MATType> correspondant au résultat de l'addition des 2 matrices
	 */
	CMatrice<MATType>& operator+=(const CMatrice<MATType>& MATParam);


	/*!
	 * Surcharge de l'opérateur cumulé -
	 *
	 * \param MATMatrice Matrice à soustraire
	 * \pre MATParam != NULL
	 * \return Résutlat de la soustraction des 2 matrices
	 */
	CMatrice<MATType>& operator-=(const CMatrice<MATType>& MATParam);



	/*---------------------------------------------------------*/
	/*---------------- Operations avec scalaire ---------------*/
	/*---------------------------------------------------------*/


	/*!
	 * Surcharge de l'opérateur *
	 *
	 * \param MATScalaire Variable à multiplier
	 * \return Un objet CMatrice<MATType> correspondant au résultat de la multiplication de la matrice par le scalaire
	 */
	CMatrice<MATType> operator*(const MATType MATScalaire);


	/*!
	 * Surcharge de l'opérateur /
	 *
	 * \param MATScalaire Diviseur
	 * \pre MATScalaire != 0
	 * \return Un objet CMatrice<MATType> correspondant au résultat de la division de la matrice par le scalaire
	 */
	CMatrice<MATType> operator/(const MATType MATScalaire);


	/*!
	 * Surcharge de l'opérateur +
	 *
	 * \param MATScalaire Sacalaire à additions à la matrice
	 * \return Un objet CMatrice<MATType> correspondant au résultat de l'addition de la matrice par le scalaire
	 */
	CMatrice<MATType> operator+(const MATType MATScalaire);


	/*!
	 * Surcharge de l'opérateur -
	 *
	 * \param MATScalaire Sacalaire à additions à la matrice
	 * \return Un objet CMatrice<MATType> correspondant au résultat de l'addition de la matrice par le scalaire
	 */
	CMatrice<MATType> operator-(const MATType MATScalaire);



	/*---------------------------------------------------------*/
	/*----------- Operations cumulées avec scalaire -----------*/
	/*---------------------------------------------------------*/


	/*!
	 * Surcharge de l'opérateur cumulé *
	 *
	 * \param MATScalaire Sacalaire à multiplier à la matrice
	 * \return Un objet CMatrice<MATType> correspondant au résultat de la multiplication de la matrice par le scalaire
	 */
	CMatrice<MATType>& operator*=(const MATType MATScalaire);


	/*!
	 * Surcharge de l'opérateur cumulé /
	 *
	 * \param MATScalaire Sacalaire à diviser à la matrice
	 * \return Un objet CMatrice<MATType> correspondant au résultat de la division de la matrice par le scalaire
	 */
	CMatrice<MATType>& operator/=(const MATType MATScalaire);


	/*!
	 * Surcharge de l'opérateur cumulé +
	 *
	 * \param MATScalaire Sacalaire à additionner à la matrice
	 * \return Un objet CMatrice<MATType> correspondant au résultat de l'addition de la matrice par le scalaire
	 */
	CMatrice<MATType>& operator+=(const MATType MATScalaire);


	/*!
	 * Surcharge de l'opérateur cumulé -
	 *
	 * \param MATScalaire Sacalaire à soustraire à la matrice
	 * \return Un objet CMatrice<MATType> correspondant au résultat de la soustraction de la matrice par le scalaire
	 */
	CMatrice<MATType>& operator-=(const MATType MATScalaire);
};

#include "CMatrice.cpp"

#endif