#ifndef CMATRICE_H
#define CMATRICE_H

#include <iostream>
#include "CException.h"

#define Ligne_Nulle 1
#define Colonne_Nulle 2
#define Index_Ligne_Depassant 3
#define Index_Colonne_Depassant 4
#define Affichage_Impossible 5

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
	CMatrice<MATType>();

	/*************************************************
	*****NOM : CMatrice<type>
	**************************************************
	*****Constructeur de recopie.
	**************************************************
	*****Entrée : CMatrice<type> MATParam (par référence).
	*****Nécessite : /
	*****Sortie : /
	*****Entraîne : Création d'un objet CMatrice copie de la matrice MATParam.
	*************************************************/
	CMatrice<MATType>(CMatrice<MATType> & MATParam);

	/*************************************************
	*****NOM : CMatrice<type>
	**************************************************
	*****Constructeur de confort.
	**************************************************
	*****Entrée : entier naturel uNBLigne, entier naturel uNBColonne, <type> valeur.
	*****Nécessite : uNBLigne != 0 &&  uNBColonne != 0
	*****Sortie : /
	*****Entraîne : Création d'un objet CMatrice de taille uNBColonne*uNBLigne et d'argument MATMAtrice entièrement remplie par valeur.
	*************************************************/
	CMatrice<MATType>(unsigned int uNBLignes, unsigned int uNBColonnes, MATType valeur = NULL);

	/*************************************************
	*****NOM : CMatrice<type>
	**************************************************
	*****Constructeur de confort.
	**************************************************
	*****Entrée : entier naturel uNBLigne, entier naturel uNBColonne, <type>matrice[ ][ ]
	*****Nécessite : uNBLigne != 0 &&  uNBColonne != 0 && dimension de matrice <= uNBColonne && dimension de matrice[0] <= uNBLigne.
	*****Sortie : /
	*****Entraîne : Création d'un objet CMatrice initialisée selon le tableau double matrice[ ][ ].
	*************************************************/
	CMatrice<MATType>(unsigned int uNBLignes, unsigned int uNBColonnes, MATType * matrice[]);

	//Destructeurs

	/*************************************************
	*****NOM : ~CMatrice<type>
	**************************************************
	*****Destructeur par défaut.
	**************************************************
	*****Entrée : /
	*****Nécessite : /
	*****Sortie : /
	*****Entraîne : L'objet est prêt à être détruit.
	*************************************************/
	~CMatrice<MATType>();

	/*************************************************
	*****NOM : MATCopyContentFrom
	**************************************************
	*****Méthode
	**************************************************
	*****Entrée : CMatrice<type> MATParam (par référence).
	*****Nécessite : /
	*****Sortie : /
	*****Entraîne : Création d'un objet CMatrice de taille uNBColonne*uNBLigne et d'argument MATMAtrice entièrement remplie par valeur.
	*************************************************/
	void MATCopyContentFrom(const CMatrice<MATType>& MATParam);

	//Accesseurs

	/*************************************************
	*****NOM : MATLireNBLigne
	**************************************************
	*****Accesseur en lecture de uMATNBLigne
	**************************************************
	*****Entrée : /
	*****Nécessite : /
	*****Sortie : uMATNBLigne
	*****Entraîne : /
	*************************************************/
	unsigned int MATLireNBLignes(void);

	/*************************************************
	*****NOM : MATLireNBColonne
	**************************************************
	*****Accesseur en lecture de uMATNBColonne
	**************************************************
	*****Entrée : /
	*****Nécessite : /
	*****Sortie : uMATNBColonne
	*****Entraîne : /
	*************************************************/
	unsigned int MATLireNBColonnes(void);

	/*************************************************
	*****NOM : MATLirerCase
	**************************************************
	*****Accesseur en lecture de MATMatrice
	**************************************************
	*****Entrée : entier naturel uNBLigne, entier naturel uNBColonne
	*****Nécessite : uNBLigne != 0 &&  uNBColonne != 0 && dimension de matrice <= uNBColonne && dimension de matrice[0] <= uNBLigne.
	*****Sortie : MATMatrice[uMATNBLigne][uMATNBColonne]
	*****Entraîne : /
	*************************************************/
	MATType MATLireCase(unsigned int uNumeroLigne, unsigned int uNumeroColonne);

	/*************************************************
	*****NOM : MATModifierCase
	**************************************************
	*****Accesseur en écriture de MATMatrice
	**************************************************
	*****Entrée : entier naturel uNBLigne, entier naturel uNBColonne, <type> valeur.
	*****Nécessite : uNBLigne != 0 &&  uNBColonne != 0 && dimension de matrice <= uNBColonne && dimension de matrice[0] <= uNBLigne.
	*****Sortie : /
	*****Entraîne : MATMatrice[uMATNBLigne][uMATNBColonne] = valeur.
	*************************************************/
	void MATModifierCase(unsigned int uNumeroLigne, unsigned int uNumeroColonne, MATType valeur);

	//Méthodes

	/*************************************************
	*****NOM : MATToString
	**************************************************
	*****Renvoie la chaîne de caractère correspondant au contenu de la matrice
	**************************************************
	*****Entrée : /
	*****Nécessite : /
	*****Sortie : /
	*****Entraîne : /
	*************************************************/
	char * MATToString(void);

	/*************************************************
	*****NOM : =
	**************************************************
	*****Surcharge de l'opérateur =
	**************************************************
	*****Entrée : MATMatrice
	*****Nécessite : /
	*****Sortie : /
	*****Entraîne : /
	*************************************************/
	void operator=(MATType & MATMatrice);

	//Operations matricielles
	CMatrice<MATType>& operator=(const CMatrice<MATType>& MATMatrice);
	CMatrice<MATType> operator+(const CMatrice<MATType>& MATMatrice);
	CMatrice<MATType> operator-(const CMatrice<MATType>& MATMatrice);
	CMatrice<MATType> operator*(const CMatrice<MATType>& MATMatrice);

	CMatrice<MATType>& operator*=(const CMatrice<MATType>& MATMatrice);
	CMatrice<MATType>& operator+=(const CMatrice<MATType>& MATMatrice);


	CMatrice<MATType> operator*(const MATType MATMScalaire);
	CMatrice<MATType> operator/(const MATType MATMScalaire);

	MATType* operator[](int iIndice);
};

#include "CMatrice.cpp"

#endif