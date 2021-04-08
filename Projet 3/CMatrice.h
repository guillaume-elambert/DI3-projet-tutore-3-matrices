#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED

//#include <string>  
//#include <iostream> 
#include <sstream> 

template <class T>
class CMatrice
{
#pragma region Attributs
private:
	int iMATNbColonnes;
	int iMATNbLignes;
	T** TContenu;
#pragma endregion


#pragma region Méthodes
public:
	CMatrice<T>(void);
	CMatrice<T>(CMatrice<T> *MATArg);
	CMatrice<T>(int iNbLignes, int iNbColonnes);
	CMatrice<T>(int iNbLignes, int iNbColonnes, T** TContenuArg);
	~CMatrice<T>(void);

	void MATInitContenu();
	void MATModifierElmt(int iLigne, int iColonne, T TNouvelElement);
	CMatrice<T> MATTransposee();

	CMatrice<T> operator+(CMatrice<T> MATArg);
	CMatrice<T> operator-(CMatrice<T> MATArg);
	CMatrice<T> operator*(CMatrice<T> MATArg);
	CMatrice<T> operator*(T TArg);
	CMatrice<T> operator/(T TArg);
	T& operator[](int iIndice);


	CMatrice<T> MATGetContenu();
	int MATGetNbLignes();
	int MATGetNbColonnes();

	char *MATToString();
#pragma endregion
};



/*!
 * Constructeur
 *
 */
template <class T>
CMatrice<T>::CMatrice(void)
{
	this->iMATNbColonnes = 0;
	this->iMATNbLignes = 0;
	this->TContenu = nullptr;
}

/*!
 * Constructeur de copie
 *
 * \param MATArg l'objet que l'on souhaite copier
 */
template <class T>
CMatrice<T>::CMatrice(CMatrice<T>* MATArg)
{
	if (MATArg->TContenu != nullptr) {
		this->TContenu = MATArg->TContenu;
	}
	else {
		this->iMATNbColonnes = 0;
		this->iMATNbLignes = 0;
		this->TContenu = nullptr;
	}
}

/*!
 * Constructeur à partir d'un nombre de lignes et d'un nombre de colonnes
 *
 * \param iNbLignes Nombre de lignes que contient la matrice
 * \param iNbColonnes Nombre de colonnes que contient la matrice
 */
template <class T>
CMatrice<T>::CMatrice(const int iNbLignes, const int iNbColonnes)
{
	if (iNbLignes <= 0 || iNbColonnes <= 0) {
		throw "CMatrice : Tentative d'allocation d'un tableau avec des dimension inférieures ou égales à 0.";
	}
		this->iMATNbColonnes = iNbColonnes;
		this->iMATNbLignes = iNbLignes;
		this->MATInitContenu();
}


/*!
 * Constructeur à partir d'un nombre de lignes, d'un nombre de colonnes et du contenu
 *
 * \param iNbLignes Nombre de lignes que contient la matrice
 * \param iNbColonnes Nombre de colonnes que contient la matrice
 * \param TContenu Contenu de la matrice
 */
template <class T>
CMatrice<T>::CMatrice(const int iNbLignes, const int iNbColonnes, T **TContenuArg)
{

	if (iNbLignes <= 0 || iNbColonnes <= 0) {
		throw "CMatrice : Tentative d'allocation d'un tableau avec des dimension inférieures ou égales à 0.";
	}

	this->iMATNbColonnes = iNbColonnes;
	this->iMATNbLignes = iNbLignes;
		
	this->MATInitContenu();
	for (int i = 0; i < iNbLignes && TContenuArg != nullptr; ++i) {
		for (int j = 0; j < iNbColonnes; ++j) {
			this->TContenu[i][j] = TContenuArg[i][j];
		}
	}
	//this->TContenu = TContenu;
	
}


/*!
 * Destructeur
 *
 */
template <class T>
CMatrice<T>::~CMatrice(void)
{
	if (this->TContenu != nullptr) {
		for (int i = 0; i < this->iMATNbLignes; ++i) {
			delete[] this->TContenu[i];
		}
		delete[] this->TContenu;
	}
}


/*!
 * Fonction qui alloue le contenu de la matrice en fonction du nombre de lignes et de colonnes
 *
 * /!\ A n'utiliser que si objet créé par un contructeur ne définissant pas le nombre de lignes/colonnes sinon fuite mémoire
 *
 */
template <class T>
void CMatrice<T>::MATInitContenu()
{
	
	//On vérifie que le contenu de la matrice est vide 
	if (this->TContenu == nullptr) {
		
		this->TContenu = new T*[this->iMATNbLignes];
		
		for (int i = 0; i < this->iMATNbLignes; ++i) {
			this->TContenu[i] = new T[this->iMATNbColonnes];
		}
	}
	else {
		throw "MATInitContenu : Allocation du tableau TContenu alors qu'il n'est pas vide";
	}
}


/*!
 * Fonction qui modifie l'élément à la ligne iLigne (compris entre 0 et iMATNbLignes)
 * et à la colonne iColonne (compris entre 0 et iMATNbColonnes)
 *
 * \param iLigne
 * \param iColonne
 * \param TNouvelElement
 */
template <class T>
void CMatrice<T>::MATModifierElmt(int iLigne, int iColonne, T TNouvelElement)
{
	//On vérife que la ligne/colonne demandée n'est pas inférieure à 0 ni supérieure à la taille de la matrice
	if (iLigne >= 0
		&& this->iMATNbLignes > iLigne
		&&	iColonne >= 0		&& this->iMATNbColonnes > iColonne
		) {
		//if (this->TContenu == nullptr) this->MATInitContenu();
		this->TContenu[iLigne][iColonne] = TNouvelElement;
	}
	else {
		throw "MATModifierElmt : La ligne et/ou la colonne souhaitée doit être comprise entre 0 et iMATNbLignes";
	}
}


/*!
 * Fonction qui créé la matrice transposée de l'objet visé
 *
 * \return La matrice transposée
 */
template <class T>
CMatrice<T> CMatrice<T>::MATTransposee()
{
	CMatrice<T> MATTransposee(this->iMATNbColonnes, this->iMATNbLignes);

	for (int i = 0; i < this->iMATNbLignes; ++i) {
		for (int j = 0; j < this->iMATNbColonnes; ++j) {
			MATTransposee->TContenu[j][i] = this->TContenu[i][j];
		}
	}

	return MATTransposee;
}


/*!
 * Méthode qui permet de gérer l'addition d'une matrice par une autre
 *
 * \param MATArg Matrice à additioner
 * \return Le résultat de l'addition
 */
template <class T>
CMatrice<T> CMatrice<T>::operator+(CMatrice<T> MATArg)
{
	CMatrice<T> newMatrice;

	//On entre que si les dimensions sont les mêmes
	if (this->iMATNbColonnes == MATArg->iMATNbColonnes
		&&	this->iMATNbLignes == MATArg->iMATNbLignes
		) {

		newMatrice(this->iMATNbLignes, this->iMATNbColonnes);

		for (int i = 0; i < this->iMATNbLignes; ++i) {
			for (int j = 0; i < this->iMATNbColonnes; ++j) {
				newMatrice->TContenu[i][j] = this->TContenu[i][j] + MATArg->TContenu[i][j];
			}
		}
	}
	else {
		throw "operator+ : Les deux matrices doivent avoir le même nombre de lignes et le même nombre de colonnes.";
	}

	return newMatrice;
}


/*!
 * Méthode qui permet de gérer la soustraction d'une matrice par une autre
 *
 * \param MATArg Matrice à soustraire
 * \return Résultat de la soustraction
 */
template <class T>
CMatrice<T> CMatrice<T>::operator-(CMatrice<T> MATArg)
{
	CMatrice<T> newMatrice;

	//On entre que si les dimensions sont les mêmes
	if (this->iMATNbColonnes == MATArg->iMATNbColonnes
		&&	this->iMATNbLignes == MATArg->iMATNbLignes
		) {

		newMatrice(this->iMATNbLignes, this->iMATNbColonnes);

		for (int i = 0; i < this->iMATNbLignes; ++i) {
			for (int j = 0; i < this->iMATNbColonnes; ++j) {
				newMatrice->TContenu[i][j] = this->TContenu[i][j] - MATArg->TContenu[i][j];
			}
		}
	}
	else {
		throw "operator- : Les deux matrices doivent avoir le même nombre de lignes et le même nombre de colonnes.";
	}

	return newMatrice;
}


/*!
 * Méthode qui permet de gérer la multiplication d'une matrice par une autre
 *
 * \param MATArg Matrice à multiplier
 * \return Résultat de la multiplication
 */
template <class T>
CMatrice<T> CMatrice<T>::operator*(CMatrice<T> MATArg)
{

	/* On peut seulement multiplier deux matrices si elles ont au moins un
	MEME attribut oppose (ligne et colonne) */
	if (this->iMATNbColonnes != MATArg.iMATNbLignes) {
		throw "operator* : Multplication impossible de deux matrices: le nombre de lignes de la matrice 1 est different du nombre de colonnes de la matrice 2";
	}


	CMatrice<T> newMatrice(iMATNbColonnes, MATArg.iMATNbLignes);

	for (int i = 0; i < this->iMATNbLignes; i++) {
		for (int j = 0; j < MATArg.iMATNbColonnes; j++) {
			newMatrice.TContenu[i][j] = *new T();

			for (int k = 0; k < this->iMATNbColonnes; k++) {
				newMatrice.TContenu[i][j] += this->TContenu[i][k] * MATArg.TContenu[k][j];
				printf("%d",this->TContenu[i][k] * MATArg.TContenu[k][j]);
			}
		}
	}

	return newMatrice;
}


/*!
 * Méthode qui permet de gérer la multiplication d'une matrice par un entier ou un réel
 *
 * \param TArg Variable à multiplier
 * \return Résultat de la multiplication
 */
template <class T>
CMatrice<T> CMatrice<T>::operator*(T TArg)
{
	CMatrice<T> newMatrice(this->iMATNbLignes, this->iMATNbColonnes);

	for (int i = 0; i < this->iMATNbLignes; ++i) {
		for (int j = 0; i < this->iMATNbColonnes; ++j) {
			newMatrice->TContenu[i][j] = this->TContenu[i][j] * TArg;
		}
	}

	return newMatrice;
}


/*!
 * Méthode qui permet de gérer la division d'une matrice par un entier ou un réel
 *
 */
template <class T>
CMatrice<T> CMatrice<T>::operator/(T TArg)
{
	return CMatrice<T>();
}

template<class T>
inline T & CMatrice<T>::operator[](int iIndice)
{
	return this->TContenu[iIndice];
}


/*!
 * Méthode qui retourne le contenu d'une matrice
 *
 */
template <class T>
inline CMatrice<T> CMatrice<T>::MATGetContenu()
{
	return CMatrice<T>();
}


/*!
 * Méthode qui retourne le nombre de lignes d'une matrice
 *
 */
template <class T>
inline int CMatrice<T>::MATGetNbLignes()
{
	return this->iMATNbLignes;
}


/*!
 * Méthode qui retourne le nombre de colonnes d'une matrice
 *
 */
template <class T>
inline int CMatrice<T>::MATGetNbColonnes()
{
	return this->iMATNbColonnes;
}


/*!
 * Fonction qui retourne le contenu de la matrice
 * 
 * \return La chaîne de caractères correspondant au contenu de la matrice
 */
template <class T>
char * CMatrice<T>::MATToString()
{
	char *toReturn = new char[0];

	if (this->TContenu != nullptr) {
		std::stringstream buffer;

		for (int i = 0; i < this->iMATNbLignes; ++i) {
			for (int j = 0; j < this->iMATNbColonnes; ++j) {
				buffer << this->TContenu[i][j] << " ";
			}
			buffer << "\n";
		}

		//On convertit le contenu de la variable buffer en char * que l'on met dans toReturn
		std::string str = buffer.str();
		const char *bufferStr = str.c_str();
		strcpy_s(toReturn, strlen(bufferStr) + 1, bufferStr);
	}

	return toReturn;
}



#endif // !MATRICE_H_INCLUDED