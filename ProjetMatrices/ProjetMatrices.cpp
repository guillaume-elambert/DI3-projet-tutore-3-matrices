// Matrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include "CMatrice.h"
#include "CMatriceOperation.h"
#include "CMatriceChargement.h"
#include "CException.h"
//#include "CStringUtil.h"
#include "conio.h"

//using namespace CMatriceOperation;



using namespace std;

int main(int argc, char * argv[])
{

	//Creation d'une matrice avec le constructeur par défaut
	try {
		cout << "Creation d'une matrice avec le constructeur par defaut :" << endl;
		CMatrice<double> MATDefaut;
		printf("%s\n", MATDefaut.MATToString());

		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	//Tableau de test
	double** ppdTableau;
	ppdTableau = (double**)malloc(sizeof(double*) * 2);
	for (int i = 0; i < 2; i++) {
		ppdTableau[i] = (double*)malloc(sizeof(double) * 2);
		for (int j = 0; j < 2; j++) {
			ppdTableau[i][j] = i + j * 10;
		}
	}

	try {
		cout << "Creation d'une matrice avec le constructeur de confort prenant un tableau a 2 dimensions 2 2  alloue dynamiquement:" << endl;
		CMatrice<double> MATTableau(2, 2, ppdTableau);
		printf("%s\n", MATTableau.MATToString());

		cout << endl;

		cout << "Creation d'une matrice avec le constructeur de recopie :" << endl;
		CMatrice<double> MATRecopie(MATTableau);
		printf("%s\n", MATRecopie.MATToString());

		cout << endl;

		cout << "Creation d'une matrice avec egal :" << endl;
		CMatrice<double> MATEgal = MATTableau;
		printf("%s\n", MATEgal.MATToString());

		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	try {
		cout << "Creation d'une matrice avec le constructeur de confort prenant une valeur :" << endl;
		CMatrice<char> MATTableau(5, 8, 's');
		printf("%s\n", MATTableau.MATToString());

		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	cout << "Creation de 3 matrices de test pour les opérations :" << endl;
	double** ppdTableau1;
	ppdTableau1 = (double**)malloc(sizeof(double*) * 3);
	for (unsigned int iIndexLigne = 0; iIndexLigne < 3; iIndexLigne++) {
		ppdTableau1[iIndexLigne] = (double*)malloc(sizeof(double) * 4);
		for (unsigned int iIndexColonne = 0; iIndexColonne < 4; iIndexColonne++) {
			ppdTableau1[iIndexLigne][iIndexColonne] = iIndexLigne + iIndexColonne + 3;
		}
	}

	double** ppdTableau2;
	ppdTableau2 = (double**)malloc(sizeof(double*) * 4);
	for (unsigned int iIndexLigne = 0; iIndexLigne < 4; iIndexLigne++) {
		ppdTableau2[iIndexLigne] = (double*)malloc(sizeof(double) * 3);
		for (unsigned int iIndexColonne = 0; iIndexColonne < 3; iIndexColonne++) {
			ppdTableau2[iIndexLigne][iIndexColonne] = iIndexLigne + iIndexColonne * 10;
		}
	}


	double** ppdTableau3;
	ppdTableau3 = (double**)malloc(sizeof(double*) * 3);
	for (unsigned int iIndexLigne = 0; iIndexLigne < 3; iIndexLigne++) {
		ppdTableau3[iIndexLigne] = (double*)malloc(sizeof(double) * 4);
		for (unsigned int iIndexColonne = 0; iIndexColonne < 4; iIndexColonne++) {
			ppdTableau3[iIndexLigne][iIndexColonne] = iIndexLigne * 3 + iIndexColonne;
		}
	}
	cout << "Matrice1 :" << endl;
	CMatrice<double> MATTableau1(3, 4, ppdTableau1);
	printf("%s\n", MATTableau1.MATToString());
	cout << endl;

	cout << "Matrice2 :" << endl;
	CMatrice<double> MATTableau2(4, 3, ppdTableau2);
	printf("%s\n", MATTableau2.MATToString());
	cout << endl;

	cout << "Matrice3 :" << endl;
	CMatrice<double> MATTableau3(3, 4, ppdTableau3);
	printf("%s\n", MATTableau3.MATToString());
	cout << endl;
	cout << endl;

	cout << "début de l'alogorithme demandé" << endl;

	/*if (argc > 1) {
		double dValeur = 0;
		CMatrice<double> *pMATTableauMatrice = new CMatrice<double>[argc];
		CMatrice<double> MATtmp;

		CParser PARparser(argv[1]);

		int iBoucle = 1;
		for (iBoucle = 1; iBoucle < argc; iBoucle++) {
			PARparser.PARLireFichier(argv[iBoucle]);
			pMATTableauMatrice[iBoucle - 1] = CMatriceChargement::MACConversionChaineMatrice(PARparser.PARLire());
			printf("Matrice du fichier : \"%s\"\n%s\n", argv[iBoucle], pMATTableauMatrice[iBoucle - 1].MATToString());
		}
		while (dValeur == 0) {
			cout << "Entrer une valeur :" << endl;
			cin >> dValeur;
			cout << endl;
		}
		for (iBoucle = 0; iBoucle < argc; iBoucle++) {
			printf("%s\n", CMatriceOperation<double>::MOPMultiplierMatriceEtConstante(pMATTableauMatrice[iBoucle], dValeur).MATToString());
			cout << endl;
		}
		for (iBoucle = 0; iBoucle < argc; iBoucle++) {
			printf("%s\n", CMatriceOperation<double>::MOPDiviserMatriceParConstante(pMATTableauMatrice[iBoucle], dValeur).MATToString());
			cout << endl;
		}
		CMatrice<double> MATtemporaire(pMATTableauMatrice[0]);
		for (iBoucle = 0; iBoucle < argc; iBoucle++) {
			MATtemporaire = CMatriceOperation<double>::MOPAdditionnerMatrice(pMATTableauMatrice[iBoucle], MATtemporaire);
		}
		printf("%s\n", MATtemporaire.MATToString());
		cout << endl;
		for (iBoucle = 0; iBoucle < argc; iBoucle++) {
			if (iBoucle % 2 == 0)
				MATtemporaire = CMatriceOperation<double>::MOPAdditionnerMatrice(pMATTableauMatrice[iBoucle], MATtemporaire);
			else
				MATtemporaire = CMatriceOperation<double>::MOPSoustraireMatrice(MATtemporaire, pMATTableauMatrice[iBoucle]);
		}
		printf("%s\n", MATtemporaire.MATToString());
		cout << endl;
		for (iBoucle = 0; iBoucle < argc; iBoucle++) {
			MATtemporaire = CMatriceOperation<double>::MOPMultiplierMatrice(MATtemporaire, pMATTableauMatrice[iBoucle]);
		}
		printf("%s\n", MATtemporaire.MATToString());
		cout << endl;

		/*for (iBoucle = 0; iBoucle < argc; ++iBoucle) {
			delete pMATTableauMatrice[iBoucle];
		}
		delete[] pMATTableauMatrice;
	}
	else if (argc == 0)
		cout << "Pas d'arguments.";
	else
		cout << "Dépassement de la taille maximale de fichier lisible.";*/

	try {
		cout << "Matrice1 * 5 :" << endl;
		printf("%s\n", CMatriceOperation<double>::MOPMultiplierMatriceEtConstante(MATTableau1, 5).MATToString());
		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	try {
		cout << "5 * Matrice1 :" << endl;
		printf("%s\n", CMatriceOperation<double>::MOPMultiplierMatriceEtConstante(5, MATTableau1).MATToString());
		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	try {
		cout << "5 * Matrice1 :" << endl;
		printf("%s\n", CMatriceOperation<double>::MOPMultiplierMatriceEtConstante(5, MATTableau1).MATToString());
		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	try {
		cout << "Matrice1 / 2 :" << endl;
		printf("%s\n", CMatriceOperation<double>::MOPDiviserMatriceParConstante(MATTableau1, 2).MATToString());
		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	try {
		cout << "Matrice1 * Matrice2 :" << endl;

		printf("%s\n", (MATTableau1 * MATTableau2).MATToString());
		MATTableau1 *= MATTableau2;
		printf("%s\n", (MATTableau1).MATToString());
		//printf("%s\n", (MATTableau2 * MATTableau1).MATToString());
		printf("Verif : \n%s\n", CMatriceOperation<double>::MOPMultiplierMatrice(MATTableau1, MATTableau2).MATToString());
		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	try {
		cout << "Matrice1 * Matrice3 :" << endl;
		printf("%s\n", CMatriceOperation<double>::MOPMultiplierMatrice(MATTableau1, MATTableau3).MATToString());
		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	try {
		cout << "Matrice1 + Matrice3 :" << endl;
		MATTableau1 = CMatrice<double>(3, 4, ppdTableau1);
		printf("%s\n", (MATTableau1 + MATTableau3).MATToString());
		MATTableau1 += MATTableau3;
		printf("+=\n%s\n", MATTableau1.MATToString());
		printf("%s\n", CMatriceOperation<double>::MOPAdditionnerMatrice(MATTableau1, MATTableau3).MATToString());
		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	try {
		cout << "Matrice1 + Matrice2 :" << endl;
		printf("%s\n", CMatriceOperation<double>::MOPAdditionnerMatrice(MATTableau1, MATTableau2).MATToString());
		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	try {
		cout << "Transposee Matrice2 :" << endl;
		printf("%s\n", CMatriceOperation<double>::MOPTransposeeMatrice(MATTableau2).MATToString());
		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}
	cout << "Appuyez sur une touche pour fermer" << endl;
	_getch();
}