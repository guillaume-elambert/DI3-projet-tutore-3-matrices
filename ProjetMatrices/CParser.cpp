#include "CParser.h"

CParser::CParser()
{
	throw(CException(Utilisation_Constructeur_Interdite));
}


CParser::CParser(const char * sChemin)
{
	if (sChemin == nullptr)
	{
		throw(CException(Ouverture_Fichier_Impossible));
	}
	sBuffer = (char *)malloc(sizeof(char) * 4);
	uTailleBuffer = 0;
	uMaxTailleBuffer = 4;
	ifstream FILfichier(sChemin, ios::in);
	if (FILfichier.fail())
	{
		FILfichier.close();
		throw(CException(Ouverture_Fichier_Impossible));
	}

	this->PARLireFichier(sChemin);
	/*while (FILfichier.get(*sBuffer))
	{
		uTailleBuffer++;
		sBuffer++;

		if (uTailleBuffer == uMaxTailleBuffer)
		{
			sBuffer -= uTailleBuffer;
			sBuffer = (char *)realloc((void *)(sBuffer), uMaxTailleBuffer * 2);
			uMaxTailleBuffer *= 2;
			sBuffer += uTailleBuffer;
		}
	}
	*sBuffer = '\0';

	sBuffer -= uTailleBuffer;

	FILfichier.close();*/
}

CParser::~CParser()
{
	free(sBuffer);
}

char * CParser::PARLire()
{
	return sBuffer;
}

void CParser::PARLireFichier(const char * sChemin)
{
	this->PARVider();
	ifstream FILfichier(sChemin, ios::in);
	if (FILfichier.fail())
	{
		FILfichier.close();
		throw(CException(Ouverture_Fichier_Impossible));
	}
	while (FILfichier.get(*sBuffer))
	{
		uTailleBuffer++;
		sBuffer++;
		if (uTailleBuffer == uMaxTailleBuffer)
		{
			sBuffer -= uTailleBuffer;
			sBuffer = (char *)realloc((void *)(sBuffer), uMaxTailleBuffer * 2);
			uMaxTailleBuffer *= 2;
			sBuffer += uTailleBuffer;
		}
	}
	//sBuffer++;
	*sBuffer = '\0';
	//uTailleBuffer++;
	sBuffer -= uTailleBuffer;
	FILfichier.close();
}

void CParser::PARVider()
{
	free(sBuffer);
	sBuffer = (char *)malloc(sizeof(char)),
		uTailleBuffer = 0;
	uMaxTailleBuffer = 1;
}
