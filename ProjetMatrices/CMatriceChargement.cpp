#include "CMatriceChargement.h"
#include "CMatrice.h"
#include "CException.h"
#include "CParser.h"
#include <regex>

/*************************************************
*****NOM : MACConversionChaineMatrice
**************************************************
*****Charge une matrice depuis un fichier
**************************************************
*****Entrée : sChemin, le chemin du fichier.
*****Nécessite : sChemin != null
*****Sortie : Un objet CMatrice initialisé à partir d'un fichier.
*****Entraine : /
*************************************************/
CMatrice<double>& CMatriceChargement::MACChargerMatriceFichier(const char* sChemin)
{
	CParser PARParser(sChemin);
	CMatrice<double> & MATNouvelleMatrice = MACConversionChaineMatrice(PARParser.PARLire());
	return MATNouvelleMatrice;
}

/*************************************************
*****NOM : MACConversionChaineMatrice
**************************************************
*****Charge une matrice depuis une chaine
**************************************************
*****Entrée : sChaine, la chaine à convertir
*****Nécessite : sChaine != null
*****Sortie : Un objet CMatrice initialisé à partir d'une chaine.
*****Entraine : /
*************************************************/
CMatrice<double> &CMatriceChargement::MACConversionChaineMatrice(const char* sChaine)
{
	if (!sChaine) {
		throw(CException(ChaineNulle));
	}

	CMatrice<double> * MATNouvelleMatrice = nullptr;

	CParser PARRegexParser("regex_template_CMatrice.txt");
	char *sRegex = PARRegexParser.PARLire();

	//On a pu récupérer le contenu du fichier contenant l'expression régulière 
	if (sRegex) {
		std::cmatch cmMatch;

		const size_t stTailleChaine = strlen(sChaine);
		const char *sDelimBreakLine = "\n";

		char *sLineRegex, *sNextLineRegex, *sRegexResult;
		char *sLineParam, *sNextLineParam, *sParam = new char[stTailleChaine + 1];

		strcpy_s(sParam, stTailleChaine + 1, sChaine);


		bool bIsGoodExec = true, inInitialization = false;

		sLineParam = strtok_s(sParam, sDelimBreakLine, &sNextLineParam);
		sLineRegex = strtok_s(sRegex, sDelimBreakLine, &sNextLineRegex);
		int iCurrentLine = 0;

		char *sTypeMatrice;
		int iNbLignes, iNbColonnes;

		//On parcourt tous les éléments de currentFile (séparés par espace, tab, fin de ligne)
		while (bIsGoodExec && sLineParam && sLineRegex)
		{

			//On vérifie si l'élément parcouru correspond à la zone d'initialisation de la matrice
			inInitialization = regex_match(sLineRegex, std::regex("initializing_content"));

			//Entrée : Nous ne parcourons pas la zone d'initialisation de la matrice
			if (!inInitialization) {

				//L'élément parcouru correspond bien au template
				if (std::regex_search(sLineParam, cmMatch, std::regex(sLineRegex))) {

					//On récupère la chaîne de caractère issue de premier groupe donné par l'expression régulière
					//(on met a null si pas de 1er groupe)
					sRegexResult = cmMatch.size() > 1 ? (char *)cmMatch[1].first : nullptr;

					//Entrée : On est sur les lignes où on attend de trouver un paramètre (càd toutes les lignes sauf celles indiquant le début et la fin de l'initialisation)
					//		ET On ne l'a pas trouvé
					/*if (sLineParam != "]" && iCurrentLine != 3 && sRegexResult == nullptr) {
						std::printf("Erreur dans la chaîne de caractères");
						bIsGoodExec = false;
					}*/

					switch (iCurrentLine)
					{
					case 0:
						//On récupère le type de données de la matrice
						sTypeMatrice = new char[strlen(sRegexResult) + 1];
						strcpy_s(sTypeMatrice, strlen(sRegexResult) + 1, sRegexResult);
						break;

					case 1:
						//On récupère le nombre de lignes
						iNbLignes = atoi(sRegexResult);
						break;

					case 2:
						//On récupère le nombre de colonnes
						iNbColonnes = atoi(sRegexResult);

						if (iNbLignes == 0 && iNbColonnes != 0) {
							throw(CException(DimensionColonnesInvalide));
							//std::printf("Erreur : Nombre de colonnes defini a %d mais nombre de lignes defini a 0.\n", iNbColonnes);
							bIsGoodExec = false;
						}
						break;

					default:
						break;
					}

					//On passe à la ligne suivante
					sLineParam = strtok_s(NULL, sDelimBreakLine, &sNextLineParam);
					++iCurrentLine;
				}
				else {
					switch (iCurrentLine)
					{
					case 0:
						throw(CException(SyntaxeTypeInvalide));
						break;

					case 1:
						throw(CException(SyntaxeLignesInvalide));
						break;

					case 2:
						throw(CException(SyntaxeColonnesInvalide));
						break;

					default:
						throw(CException(SyntaxeDelimiteursInvalide));
						break;
					}

					//std::printf("La ligne %d : \"%s\" ne correspond pas a l'expression reguliere attendue : \"%s\"\n", iCurrentLine + 1, sLineParam, sLineRegex);
					bIsGoodExec = false;
				}

			}
			else {

				MATNouvelleMatrice = new CMatrice<double>(iNbLignes, iNbColonnes);

				int iCurrentRow = 0, iCurrentCol, iLineLength;

				char *sColMat = (char *)malloc(sizeof(char)), *sNextColMat;
				const char *sDelimSpace = " ";

				//On on parcourt toutes les lignes du fichier correspondant à l'initialisation de la matrice
				while (bIsGoodExec && iCurrentRow < iNbLignes && sLineParam) {

					iCurrentCol = 0;
					iLineLength = strlen(sLineParam);

					//On récupère la valeur (séparée par un espace)
					sColMat = strtok_s(sLineParam, sDelimSpace, &sNextColMat);

					//On parcourt les colonnes (séparées par des espaces)
					while (bIsGoodExec && sColMat) {
						MATNouvelleMatrice->MATModifierCase(iCurrentRow, iCurrentCol, atof(sColMat));

						sColMat = strtok_s(NULL, sDelimSpace, &sNextColMat);
						++iCurrentCol;
					}

					if (iCurrentCol != iNbColonnes) {
						bIsGoodExec = false;
						throw(DimensionColonnesInvalide);
						//std::printf("%d colonnes attendues, %d trouvees dans la chaîne de caractères (l. %d)\n", iNbColonnes, iCurrentCol, iCurrentLine);
					}

					//On passe à la ligne suivante
					sLineParam = strtok_s(NULL, sDelimBreakLine, &sNextLineParam);
					++iCurrentLine;
					++iCurrentRow;
				}


				if (iCurrentRow != iNbLignes) {
					bIsGoodExec = false;
					throw(DimensionLignesInvalide);
					//std::printf("%d lignes attendues, %d trouvees dans la chaîne de caractères (l. %d)\n", iNbLignes, iNbColonnes, iCurrentLine);
				}

				--iCurrentLine;
			}

			sLineRegex = strtok_s(NULL, sDelimBreakLine, &sNextLineRegex);

		}
	} else {
		throw(CException(RegexVide));
	}

	return *MATNouvelleMatrice;
}
