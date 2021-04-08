#include <fstream>
#include <regex>
#include "CFichier.h"


void* CFichier::FICcreerCMatrice(char *sType, const int iNbLignes, const int iNbColonnes) {
	void *toReturn;

	if (strcmp(sType, "double")) {
		toReturn = new CMatrice<double>(iNbLignes, iNbColonnes);
	}
	else {
		toReturn = nullptr;
		printf("Le type %s n'est pas pris en charge.\n", sType);
	}

	return toReturn;
}

void CFichier::FICfilesToCMatrices(int iNombreFichiers, char **pCheminsFichiers, void **tableMatrices)
{

	//Entr�e : Des chemins vers un ou plusieurs fichiers sont pass�s en param�tre
	if (iNombreFichiers > 0) {

		//On ouvre le fichier template
		std::ifstream regexTemplateFile("regex_template_CMatrice.txt");

		//On stock la position du d�but du fichier template
		//std::streampos regexTemplateStartOfFile = regexTemplateFile.tellg();

		int currentFileIndex = 1, templateLinesCount = 0, currentFileLinesCount = 0;
		const int currentFileBufferSize = 255, regexTemplateBufferSize = 255;
		char currentFileBuffer[currentFileBufferSize], regexTemplateBuffer[regexTemplateBufferSize];


		//Entr�e : Le fichier template a pu �tre ouvert
		if (regexTemplateFile.is_open()) {

			//On compte le nombre de lignes du fichier template
			while (regexTemplateFile.getline(regexTemplateBuffer, regexTemplateBufferSize)) {
				++templateLinesCount;
			}
			//Retour au d�but du fichier template
			regexTemplateFile.clear();
			regexTemplateFile.seekg(0);

			//On parcourt l'ensemble des fichiers pass�s en param�tre
			while (currentFileIndex < iNombreFichiers) {

				printf("-------- Fichier \"%s\" --------\n", pCheminsFichiers[currentFileIndex]);

				//On ouvre le fichier dont le chemin se trouve � pCheminsFichiers[currentFileIndex]
				std::ifstream currentFile(pCheminsFichiers[currentFileIndex]);

				//Entr�e : Le fichier cible � pu �tre ouvert
				if (currentFile.is_open())
				{

					//On compte le nombre de lignes du fichier courrant
					while (currentFile.getline(currentFileBuffer, currentFileBufferSize)) {
						++currentFileLinesCount;
					}

					//Retour au d�but du fichier courrant
					currentFile.clear();
					currentFile.seekg(0);

					//On v�rifie que le fichier courrant contient au moins le m�me nombres de lignes que le fichier template
					//(on soustrait 1 � templateLinesCount car il peut ne pas y avoir de contenu si nbLignes et nbColonnes � 0) 
					if (currentFileLinesCount >= templateLinesCount - 1) {

						char *typeMatrice = (char *)"", *regexRes;
						int currentLine = 0, nbLignes, nbColonnes;

						regexTemplateFile >> regexTemplateBuffer;

						//On parcourt tous les �l�ments de currentFile (s�par�s par espace, tab, fin de ligne)
						while (currentFile >> currentFileBuffer) {
							int inInitialization = std::regex_match(regexTemplateBuffer, std::regex("initializing_content"));
							//Entr�e : Nous ne parcourons pas la zone d'initialisation de la matrice
							if (!inInitialization) {

								std::cmatch match;

								//L'�l�ment parcouru correspond bien au template
								if (std::regex_search(currentFileBuffer, match, std::regex(regexTemplateBuffer))) {

									//On r�cup�re la cha�ne de caract�re issue de premier groupe donn� par l'expression r�guli�re
									//(on met a null si pas de 1er groupe)
									regexRes = match.size() > 1 ? (char *)match[1].first : nullptr;

									//Entr�e : On est sur les lignes o� on attend de trouver un param�tre
									//		ET On ne l'a pas trouv�
									if (currentLine != currentFileLinesCount && currentLine != 3 && regexRes == nullptr) {
										printf("Erreur dans le fichier cible \"%s\" ligne : %d", pCheminsFichiers[currentFileIndex], currentLine);
									}

									switch (currentLine)
									{
									case 0:
										//On r�cup�re le type de donn�es de la matrice
										typeMatrice = new char[strlen(regexRes) + 1];
										strcpy_s(typeMatrice, strlen(regexRes) + 1, regexRes);
										printf("Type matrice : %s\n", typeMatrice);
										break;

									case 1:
										//On r�cup�re le nombre de lignes
										nbLignes = atoi(regexRes);
										printf("Nombre de lignes : %d\n", nbLignes);
										break;

									case 2:
										//On r�cup�re le nombre de colonnes
										nbColonnes = atoi(regexRes);

										if (nbLignes == 0 && nbColonnes != 0) {
											printf("Erreur : Nombre de colonnes defini a %d mais nombre de lignes defini a %d.\n", nbColonnes, nbLignes);
										}
										printf("Nombre de colonnes : %d\n", nbColonnes);

										tableMatrices[currentFileIndex - 1] = FICcreerCMatrice(typeMatrice, nbLignes, nbColonnes);
										break;

									default:
										break;
									}

									++currentLine;
									regexTemplateFile >> regexTemplateBuffer;
								}

							}
							else {
								int i = 1, currentRow = 0, currentCol = 0;
								printf("Contenu :\n");
								do {
									printf("%s\t", currentFileBuffer);
									if (i%nbColonnes == 0) {
										tableMatrices[currentFileIndex - 1];
										printf("\n");
										++currentLine;
									}
									++i;
								} while (currentFile >> currentFileBuffer && i <= nbLignes * nbColonnes);
								regexTemplateFile >> regexTemplateBuffer;
								printf("\n");
							}

						}
					}
					else {
						printf("Le fichier \"%s\" ne suit pas le format utilise.\n", pCheminsFichiers[currentFileIndex]);
					}
				}
				else {
					printf("Impossible d'ouvrir le fichier en lecture !\n");
				}

				//Retour au d�but du fichier template
				regexTemplateFile.clear();
				regexTemplateFile.seekg(0);
				currentFile.close();
				printf("Fichier OK\n\n");
				++currentFileIndex;
			}


		}
		else {
			printf("Impossible d'ouvrir le fichier template en lecture !\n");
		}

		regexTemplateFile.close();
	}
	else {
		printf("Aucun fichiers passes en parametre...\n");
	}
}