#ifndef CMATRICEOPERATION_H
#define CMATRICEOPERATION_H


#include "CMatrice.h"

#define Dimension_Incompatible 10


template <class MATType>
class CMatriceOperation
{
public:
	/*************************************************
	*****NOM : MOPMultiplierMatriceEtConstante
	**************************************************
	*****Multiplie une MATMatrice par un scalaire.
	**************************************************
	*****Entrée : Une CMatrice MATMatrice, une dConstante de type double.
	*****Nécessite : L'opérateur * a été surchargé pour les objets de type MATType et renvoie un MATType. De plus, chaque multiplication entre dConstante et un élément de MATMatrice doit être valide.
	*****Sortie : Une MATMatrice M.
	*****Entraine : Pour tout élément de la MATMatrice multMat de M,  multMat[x][y] = dConstante * MATMatrice[x][y]
	*************************************************/
	static CMatrice<MATType> &MOPMultiplierMatriceEtConstante(CMatrice<MATType>& const MATMatrice, const double dConstante);

	/*************************************************
	*****NOM : MOPMultiplierMatriceEtConstante
	**************************************************
	*****Multiplie une MATMatrice par un scalaire.
	**************************************************
	*****Entrée : Une CMatrice MATMatrice, une dConstante de type double.
	*****Nécessite : L'opérateur * a été surchargé pour les objets de type MATType et renvoie un MATType. De plus, chaque multiplication entre dConstante et un élément de MATMatrice doit être valide.
	*****Sortie : Une MATMatrice M.
	*****Entraine : Pour tout élément de la MATMatrice multMat de M,  multMat[x][y] = MATMatrice[x][y] * dConstante
	*************************************************/
	static CMatrice<MATType> &MOPMultiplierMatriceEtConstante(const double dConstante, CMatrice<MATType>& const MATMatrice);

	/*************************************************
	*****NOM : MOPDiviserMatriceParConstante
	**************************************************
	*****Divise une MATMatrice par un scalaire.
	**************************************************
	*****Entrée : Une CMatrice MATMatrice, une dConstante de type double.
	*****Nécessite : L'opérateur / a été surchargé pour les objets de type MATType et renvoie un MATType. De plus, chaque division entre un élément de MATMatrice et dConstante doit être valide.
	*****Sortie : Une MATMatrice M.
	*****Entraine : Pour tout élément de la MATMatrice divMat de M,  divMat[x][y] = MATMatrice[x][y] / dConstante
	*************************************************/
	static CMatrice<MATType> &MOPDiviserMatriceParConstante(CMatrice<MATType>& const MATMatrice, const double dConstante);

	/*************************************************
	*****NOM : MOPAdditionnerMatrice
	**************************************************
	*****Additionne deux MATMatrices
	**************************************************
	*****Entrée : Deux CMatrice MATMatriceA et MATMatriceB
	*****Nécessite : L'opérateur + a été surchargé pour les objets de type MATType et renvoie un MATType. De plus, chaque addition entre deux éléments des MATMatrices doit être valide.
	*****Sortie : Une MATMatrice M.
	*****Entraine : M = MATMatriceA + MATMatriceB
	*************************************************/
	static CMatrice<MATType> &MOPAdditionnerMatrice(CMatrice<MATType>& const MATMatriceA, CMatrice<MATType>& const MATMatriceB);

	/*************************************************
	*****NOM : MOPSoustraireMatrice
	**************************************************
	*****Soustrait deux MATMatrices
	**************************************************
	*****Entrée : Deux CMatrice MATMatriceA et MATMatriceB
	*****Nécessite : L'opérateur - a été surchargé pour les objets de type MATType et renvoie un MATType. De plus, chaque soustraction entre deux éléments des MATMatrices doit être valide.
	*****Sortie : Une MATMatrice M.
	*****Entraine : M = MATMatriceA - MATMatriceB
	*************************************************/
	static CMatrice<MATType> &MOPSoustraireMatrice(CMatrice<MATType>& const MATMatriceA, CMatrice<MATType>& const MATMatriceB);

	/*************************************************
	*****NOM : MOPTransposeeMatrice
	**************************************************
	*****Renvoie la transposée de deux MATMatrices
	**************************************************
	*****Entrée : Une CMatrice MATMatrice
	*****Nécessite : /
	*****Sortie : Une MATMatrice M.
	*****Entraine : M est la transposée de MATMatrice.
	*************************************************/
	static CMatrice<MATType>& MOPTransposeeMatrice(CMatrice<MATType>& const MATMatrice);

	/*************************************************
	*****NOM : MOPMultiplierMatrice
	**************************************************
	*****Multiplie deux MATMatrices
	**************************************************
	*****Entrée : Deux CMatrice MATMatriceA et MATMatriceB
	*****Nécessite : Les opérateurs * et + ont été surchargés pour les objets de type MATType et renvoient un MATType. De plus, chaque opératione entre deux éléments des MATMatrices doivent être valides.
	*****Sortie : Une MATMatrice M.
	*****Entraine : M = MATMatriceA*MATMatriceB
	*************************************************/
	static CMatrice<MATType>& MOPMultiplierMatrice(CMatrice<MATType>& const MATMatriceA, CMatrice<MATType>& const MATMatriceB);
};

#include "CMatriceOperation.cpp"

#endif