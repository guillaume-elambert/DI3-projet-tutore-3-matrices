#include <fstream>
#include <regex>
#include <iostream>
#include "CMatrice.h"
#include "CFichier.h"


int main(int argc, char *argv[])
{
	int m5NbRows = 2, m5NbCols = 5;
	int **tab = new int*[m5NbRows];
	for (int i = 0; i < m5NbRows; ++i) {
		tab[i] = new int[m5NbCols];
		for (int j = 0; j < m5NbCols; ++j) {
			tab[i][j] = (i+1) * j;
		}
	}

	for (int i = 0; i < m5NbRows; ++i) {
		for (int j = 0; j < m5NbCols; ++j) {
			std::cout << tab[i][j] << " ";
		}
		std::cout << std::endl;
	}

	CMatrice<int> m1;
	CMatrice<int> m2(m1);
	CMatrice<int> m3(1, 2);
	CMatrice<int> m4(2, 1, nullptr);
	CMatrice<int> m5(2, 2, tab);

	m3.MATModifierElmt(0, 0, 1);
	m3.MATModifierElmt(0, 1, 2);
	char *m3Str = m3.MATToString();
	printf("%s\n", m3Str);
	m4.MATModifierElmt(0, 0, 1);
	m4.MATModifierElmt(1, 0, 2);

	CMatrice<int> multipl = m3*m4;
	printf("%s\n", multipl.MATToString());

	/*CFichier monFichier;
	char **cc = &argv[1];
	void *mesMatrices = malloc(argc - 1);
	monFichier.FICfilesToCMatrices(argc-1, cc, &mesMatrices);

	//std::std::cout << "Hello World!\n";*/
	return 0;

	float c;
	std::cout << "Saisissez une valeur (réel ou entier)" << std::endl;
	std::cin >> c;
	
	//char * resultatProduitParC 
	// char * resultatProduitsMatriciels
	// char * resultatDivision
	// char * resultatDivision
	// char * resultatAddition
	// char * resultatSoustraction
	

}
