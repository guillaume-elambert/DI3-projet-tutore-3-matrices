// Matrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include <Windows.h>
#include "CMatrice.h"
#include "CMatriceChargement.h"
#include "CException.h"
#include "conio.h"



using namespace std;

int main(int argc, char * argv[])
{
	// Set console code page to UTF-8 so console known how to interpret string data
	SetConsoleOutputCP(CP_UTF8);

	// Enable buffering to prevent VS from chopping up UTF-8 byte sequences
	setvbuf(stdout, nullptr, _IOFBF, 1000);

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

	try {
		cout << "Matrice1 * 5 :" << endl << (MATTableau1 * 5).MATToString() << endl;
		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	try {
		cout << "Matrice1 / 2 :" << endl << (MATTableau1 / 2).MATToString() << endl;
		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	try {
		cout << "Matrice1 * Matrice2 :" << endl << (MATTableau1 * MATTableau2).MATToString() << endl;
		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	try {
		cout << "Matrice1 * Matrice3 :" << endl << (MATTableau1, MATTableau3).MATToString() << endl;
		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	try {
		MATTableau1 = CMatrice<double>(3, 4, ppdTableau1);

		cout << "Matrice1 + Matrice3 :" << endl << (MATTableau1 + MATTableau3).MATToString() << endl;
		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	try {
		cout << "Matrice1 + Matrice2 :" << endl << (MATTableau1, MATTableau2).MATToString() << endl;
		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	try {
		printf("Matrice 2 :\n%s\nTransposée matrice 2: \n%s\n", MATTableau2.MATToString(), MATTableau2.MATransposeeMatrice().MATToString());
		cout << endl;
	}
	catch (CException EXCLevee)
	{
		EXCLevee.EXCAfficherMessageErreur();
	}

	cout << endl << "Début de l'algorithme demandé" << endl << endl;

	//Entrée : au moins 1 nom de fichier est passé en paramètre
	if (argc > 1) {
		try {
			double dValeur = 0;
			int iNbMatrices = argc - 1;
			CMatrice<double> *pMATTableauMatrice = new CMatrice<double>[iNbMatrices];
			CMatrice<double> MATtmp;

			CParser PARparser(argv[1]);

			int iBoucle;

			//Boucle de création des matrices
			for (iBoucle = 0; iBoucle < iNbMatrices; iBoucle++) {
				PARparser.PARLireFichier(argv[iBoucle + 1]);
				pMATTableauMatrice[iBoucle] = CMatriceChargement::MACConversionChaineMatrice(PARparser.PARLire());
				printf("Matrice %d (fichier \"%s\") :\n%s\n", iBoucle + 1, argv[iBoucle + 1], pMATTableauMatrice[iBoucle].MATToString());
			}

			//Saisie de la valeur
			while (dValeur == 0) {
				cout << "Entrer une valeur :" << endl;
				cin >> dValeur;
				cout << endl;
			}


			//Boucle de multiplication des matrices par le scalaire saisi
			for (iBoucle = 0; iBoucle < iNbMatrices; iBoucle++) {

				printf("Mutliplication matrice %d par %lf :\n%s\n", iBoucle + 1, dValeur, (pMATTableauMatrice[iBoucle] * dValeur).MATToString());
				cout << endl;
			}


			//Boucle de division des matrices par le scalaire saisi
			for (iBoucle = 0; iBoucle < iNbMatrices; iBoucle++) {
				printf("Division matrice %d par %lf :\n%s\n", iBoucle + 1, dValeur, (pMATTableauMatrice[iBoucle] / dValeur).MATToString());
				cout << endl;
			}

			//Entrée : plusieurs fichiers ont été passés en paramètre 
			if (iNbMatrices > 1) {
				CMatrice<double> MATtemporaire(pMATTableauMatrice[0]);

				//Boucle d'addition des matrices entre elles
				for (iBoucle = 1; iBoucle < iNbMatrices; iBoucle++) {
					MATtemporaire += pMATTableauMatrice[iBoucle];
				}
				printf("Résultat de l'addition des %d matrices :\n%s\n", iNbMatrices, MATtemporaire.MATToString());
				cout << endl;

				MATtemporaire = pMATTableauMatrice[0];

				//Boucle d'addition et soustration des matrices en elles
				//Càd : M1-M2+M3-M4+M5-M6+...
				for (iBoucle = 1; iBoucle < iNbMatrices; iBoucle++) {
					if (iBoucle % 2 == 0) {
						MATtemporaire += pMATTableauMatrice[iBoucle];
					}
					else {
						MATtemporaire -= pMATTableauMatrice[iBoucle];
					}
				}
				printf("Résultat de M1-M2+M3-M4+M5-M6+... :\n%s\n", MATtemporaire.MATToString());
				cout << endl;

				MATtemporaire = pMATTableauMatrice[0];

				//Boucle de multiplication des matrices entre elles
				for (iBoucle = 1; iBoucle < iNbMatrices; iBoucle++) {
					MATtemporaire *= pMATTableauMatrice[iBoucle];
				}

				printf("Résultat de la multiplication des %d matrices :\n%s\n", iNbMatrices, MATtemporaire.MATToString());
				cout << endl;
			}
		}
		catch (CException EXCLevee) {
			EXCLevee.EXCAfficherMessageErreur();
		}
	}
	else {
		cout << "Il faut passer au moins 1 fichier en argument" << endl;
	}

	cout << "Appuyez sur une touche pour fermer" << endl;
	_getch();
}