#ifndef CFICHIER_H_INCLUDED
#define CFICHIER_H_INCLUDED
#include "CMatrice.h"


class CFichier
{
public :
	void *FICcreerCMatrice(char *sType, const int iNbLignes, const int iNbColonnes);

	void FICfilesToCMatrices(int iNombreFichiers, char **pCheminsFichiers, void **tableMatrices);
};

#endif // !CFICHIER_H_INCLUDED
