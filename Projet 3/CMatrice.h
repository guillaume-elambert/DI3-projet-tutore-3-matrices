#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED

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
	CMatrice<T>(int iNbLignes, int iNbColonnes, T** TContenu);
	~CMatrice<T>(void);

	void MATInitContenu();
	void MATModifierElmt(int iLigne, int iColonne, T TNouvelElement);
	CMatrice<T> MATTransposee();

	CMatrice<T> operator+(CMatrice<T> MATArg);
	CMatrice<T> operator-(CMatrice<T> MATArg);
	CMatrice<T> operator*(CMatrice<T> MATArg);
	CMatrice<T> operator*(T TArg);
	CMatrice<T> operator/(T TArg);


	CMatrice<T> MATGetContenu();
	int MATGetNbLignes();
	int MATGetNbColonnes();

	char *MATAfficher();
#pragma endregion
};


#endif // !MATRICE_H_INCLUDED