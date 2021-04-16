#ifndef CMATRICEOPERATION_CPP
#define CMATRICEOPERATION_CPP

#include "CMatriceOperation.h"
#include "CMatrice.h"

/*************************************************
	*****NOM : MOPMultiplierMatriceEtConstante
	**************************************************
	*****Multiplie une MATMatrice par un scalaire.
	**************************************************
	*****Entrée : Une CMatrice MATMatrice, une dConstante de type double.
	*****Nécessite : L'opérateur * a été surchargé pour les objets de type MATType et renvoie un MATType. De plus, chaque multiplication entre dConstante et un élément de MATMatrice doit étre valide.
	*****Sortie : Une MATMatrice M.
	*****Entraine : Pour tout élément de la MATMatrice multMat de M,  multMat[x][y] = dConstante * MATMatrice[x][y]
	*************************************************/
template <class MATType>
CMatrice<MATType>& CMatriceOperation<MATType>::MOPMultiplierMatriceEtConstante(CMatrice<MATType>& MATMatrice, const double dConstante)
{
	CMatrice<MATType>* MATNouvelleMatrice = new CMatrice<MATType>(MATMatrice);
	for (unsigned int uLigneCourante = 0; uLigneCourante < MATMatrice.MATLireNBLignes(); uLigneCourante++)
		for (unsigned int uColonneCourante = 0; uColonneCourante < MATMatrice.MATLireNBColonnes(); uColonneCourante++)
			MATNouvelleMatrice->MATModifierCase(uLigneCourante, uColonneCourante, MATMatrice.MATLireCase(uLigneCourante, uColonneCourante) * dConstante);
	return *MATNouvelleMatrice;
}

/*************************************************
	*****NOM : MOPMultiplierMatriceEtConstante
	**************************************************
	*****Multiplie une MATMatrice par un scalaire.
	**************************************************
	*****Entrée : Une CMatrice MATMatrice, une dConstante de type double.
	*****Nécessite : L'opérateur * a été surchargé pour les objets de type MATType et renvoie un MATType. De plus, chaque multiplication entre dConstante et un élément de MATMatrice doit étre valide.
	*****Sortie : Une MATMatrice M.
	*****Entraine : Pour tout élément de la MATMatrice multMat de M,  multMat[x][y] = MATMatrice[x][y] * dConstante
	*************************************************/
template <class MATType>
CMatrice<MATType> & CMatriceOperation<MATType>::MOPMultiplierMatriceEtConstante(const double dConstante, CMatrice<MATType> & MATMatrice)
{
	CMatrice<MATType>* MATNouvelleMatrice = new CMatrice<MATType>(MATMatrice);
	for (unsigned int uLigneCourante = 0; uLigneCourante < MATMatrice.MATLireNBLignes(); uLigneCourante++)
		for (unsigned int uColonneCourante = 0; uColonneCourante < MATMatrice.MATLireNBColonnes(); uColonneCourante++)
			MATNouvelleMatrice->MATModifierCase(uLigneCourante, uColonneCourante, dConstante * MATMatrice.MATLireCase(uLigneCourante, uColonneCourante));

	return *MATNouvelleMatrice;
}

/*************************************************
	*****NOM : MOPDiviserMatriceParConstante
	**************************************************
	*****Divise une MATMatrice par un scalaire.
	**************************************************
	*****Entrée : Une CMatrice MATMatrice, une dConstante de type double.
	*****Nécessite : L'opérateur / a été surchargé pour les objets de type MATType et renvoie un MATType. De plus, chaque division entre un élément de MATMatrice et dConstante doit étre valide.
	*****Sortie : Une MATMatrice M.
	*****Entraine : Pour tout élément de la MATMatrice divMat de M,  divMat[x][y] = MATMatrice[x][y] / dConstante
	*************************************************/
template <class MATType>
CMatrice<MATType> & CMatriceOperation<MATType>::MOPDiviserMatriceParConstante(CMatrice<MATType> & MATMatrice, const double dConstante)
{
	CMatrice<MATType>* MATNouvelleMatrice = new CMatrice<MATType>(MATMatrice);
	for (unsigned int uLigneCourante = 0; uLigneCourante < MATMatrice.MATLireNBLignes(); uLigneCourante++)
		for (unsigned int uColonneCourante = 0; uColonneCourante < MATMatrice.MATLireNBColonnes(); uColonneCourante++)
			MATNouvelleMatrice->MATModifierCase(uLigneCourante, uColonneCourante, MATMatrice.MATLireCase(uLigneCourante, uColonneCourante) / dConstante);

	return *MATNouvelleMatrice;
}

/*************************************************
	*****NOM : MOPAdditionnerMatrice
	**************************************************
	*****Additionne deux MATMatrices
	**************************************************
	*****Entrée : Deux CMatrice MATMatriceA et MATMatriceB
	*****Nécessite : L'opérateur + a été surchargé pour les objets de type MATType et renvoie un MATType. De plus, chaque addition entre deux éléments des MATMatrices doit étre valide.
	*****Sortie : Une MATMatrice M.
	*****Entraine : M = MATMatriceA + MATMatriceB
	*************************************************/
template <class MATType>
CMatrice<MATType> & CMatriceOperation<MATType>::MOPAdditionnerMatrice(CMatrice<MATType> & MATMatriceA, CMatrice<MATType> & MATMatriceB)
{
	if (MATMatriceA.MATLireNBLignes() != MATMatriceB.MATLireNBLignes() || MATMatriceA.MATLireNBColonnes() != MATMatriceB.MATLireNBColonnes())
		throw(CException(Dimension_Incompatible));

	CMatrice<MATType> * MATNouvelleMatrice = new CMatrice<MATType>(MATMatriceA.MATLireNBLignes(), MATMatriceA.MATLireNBColonnes());

	for (unsigned int uLigneCourante = 0; uLigneCourante < MATMatriceA.MATLireNBLignes(); uLigneCourante++)
		for (unsigned int uColonneCourante = 0; uColonneCourante < MATMatriceA.MATLireNBColonnes(); uColonneCourante++)
			MATNouvelleMatrice->MATModifierCase(uLigneCourante, uColonneCourante,
				MATMatriceA.MATLireCase(uLigneCourante, uColonneCourante) + MATMatriceB.MATLireCase(uLigneCourante, uColonneCourante));
	return *MATNouvelleMatrice;
}

/*************************************************
	*****NOM : MOPSoustraireMatrice
	**************************************************
	*****Soustrait deux MATMatrices
	**************************************************
	*****Entrée : Deux CMatrice MATMatriceA et MATMatriceB
	*****Nécessite : L'opérateur - a été surchargé pour les objets de type MATType et renvoie un MATType. De plus, chaque soustraction entre deux éléments des MATMatrices doit étre valide.
	*****Sortie : Une MATMatrice M.
	*****Entraine : M = MATMatriceA - MATMatriceB
	*************************************************/
template <class MATType>
CMatrice<MATType> & CMatriceOperation<MATType>::MOPSoustraireMatrice(CMatrice<MATType> & MATMatriceA, CMatrice<MATType> & MATMatriceB)
{
	if (MATMatriceA.MATLireNBLignes() != MATMatriceB.MATLireNBLignes() || MATMatriceA.MATLireNBColonnes() != MATMatriceB.MATLireNBColonnes())
		throw(CException(Dimension_Incompatible));

	CMatrice<MATType> * MATNouvelleMatrice = new CMatrice<MATType>(MATMatriceA.MATLireNBLignes(), MATMatriceA.MATLireNBColonnes());
	for (unsigned int uLigneCourante = 0; uLigneCourante < MATMatriceA.MATLireNBLignes(); uLigneCourante++)
		for (unsigned int uColonneCourante = 0; uColonneCourante < MATMatriceA.MATLireNBColonnes(); uColonneCourante++)
			MATNouvelleMatrice->MATModifierCase(uLigneCourante, uColonneCourante,
				MATMatriceA.MATLireCase(uLigneCourante, uColonneCourante) - MATMatriceB.MATLireCase(uLigneCourante, uColonneCourante));
	printf("%s\n", MATNouvelleMatrice->MATToString());
	return *MATNouvelleMatrice;
}

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
template <class MATType>
CMatrice<MATType> & CMatriceOperation<MATType>::MOPTransposeeMatrice(CMatrice<MATType> & MATMatrice)
{
	CMatrice<MATType>* MATNouvelleMatrice = new CMatrice<MATType>(MATMatrice.MATLireNBColonnes(), MATMatrice.MATLireNBLignes());
	for (unsigned int uLigneCourante = 0; uLigneCourante < MATNouvelleMatrice->MATLireNBLignes(); uLigneCourante++)
		for (unsigned int uColonneCourante = 0; uColonneCourante < MATNouvelleMatrice->MATLireNBColonnes(); uColonneCourante++)
			MATNouvelleMatrice->MATModifierCase(uLigneCourante, uColonneCourante, MATMatrice.MATLireCase(uColonneCourante, uLigneCourante));
	return *MATNouvelleMatrice;
}

/*************************************************
	*****NOM : MOPMultiplierMatrice
	**************************************************
	*****Multiplie deux MATMatrices
	**************************************************
	*****Entrée : Deux CMatrice MATMatriceA et MATMatriceB
	*****Nécessite : Les opérateurs * et + ont été surchargés pour les objets de type MATType et renvoient un MATType. De plus, chaque opératione entre deux éléments des MATMatrices doivent étre valides.
	*****Sortie : Une MATMatrice M.
	*****Entraine : M = MATMatriceA*MATMatriceB
	*************************************************/
template <class MATType>
CMatrice<MATType> & CMatriceOperation<MATType>::MOPMultiplierMatrice(CMatrice<MATType> & MATMatriceA, CMatrice<MATType> & MATMatriceB)
{
	if (MATMatriceA.MATLireNBLignes() != MATMatriceB.MATLireNBColonnes())
		throw(CException(Dimension_Incompatible));

	CMatrice<MATType> * MATNouvelleMatrice = new CMatrice<MATType>(MATMatriceB.MATLireNBLignes(), MATMatriceA.MATLireNBColonnes());
	for (unsigned int uLigneCourante = 0; uLigneCourante < MATNouvelleMatrice->MATLireNBLignes(); uLigneCourante++)
		for (unsigned int uColonneCourante = 0; uColonneCourante < MATNouvelleMatrice->MATLireNBColonnes(); uColonneCourante++)
			for (unsigned int boucleIter = 0; boucleIter < MATMatriceA.MATLireNBLignes(); boucleIter++)
				MATNouvelleMatrice->MATModifierCase(uLigneCourante, uColonneCourante, MATNouvelleMatrice->MATLireCase(uLigneCourante, uColonneCourante) + (MATMatriceA.MATLireCase(boucleIter, uColonneCourante) * MATMatriceB.MATLireCase(uLigneCourante, boucleIter)));

	return *MATNouvelleMatrice;
}
#endif
