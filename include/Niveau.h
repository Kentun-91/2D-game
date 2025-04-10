#ifndef NIVEAU_H_INCLUDED
#define NIVEAU_H_INCLUDED
#include "Objet.h"
#include<vector>
#include "Image.h"
#include "Dictionnaire.h"
#include<fstream>

class Niveau
{
    vector<Objet> _objets;
    int _bonus;

public:
    Niveau(Image & image, const string & nomFichier, const Dictionnaire & dictionnaire);

    void dessiner()const;
    bool caseEstLibre(int x, int y);
    void testerBonusEtPrendre(int x, int y);
    bool gagne()const;
};


#endif // NIVEAU_H_INCLUDED
