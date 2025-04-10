#include <string>
#include <iostream>
#include "Niveau.h"

using namespace std;

Niveau::Niveau(Image & image, const string & nomFichier, const Dictionnaire & dictionnaire)
{
    _bonus=0;
    int nbLigne, x, y;
    string nom;
    ifstream input;
    input.open(nomFichier);
    input>>nbLigne;
    for (int i=0; i<nbLigne; i++)
    {
        input>>nom;
        input>>x;
        input>>y;
        _objets.push_back(Objet(image,nom,dictionnaire,x,y));
        if(_objets[i].getProperty()=="bonus")
            _bonus++;
    }
}

void Niveau::dessiner()const
{
    for(int i=0; i<_objets.size(); i++)
    {
        if(_objets[i].getProperty() != "cache")
            _objets[i].dessiner();
    }

}

bool Niveau::caseEstLibre(int x, int y)
{
    for (int i=0; i<_objets.size(); i++)
    {
        if(_objets[i].getProperty()=="solide")
        {
            if(_objets[i].getx()==x && _objets[i].gety()==y)
            {
                return false;
            }
        }
    }
    return true;
}


void Niveau::testerBonusEtPrendre(int x, int y)
{
    for (int i=0; i<_objets.size(); i++)
    {
        if(_objets[i].getProperty()=="bonus")
        {
            if(_objets[i].getx()==x && _objets[i].gety()==y)
            {
                _objets[i].cacher();
                _bonus--;
            }
        }
    }
}

bool Niveau::gagne()const
{
    if(_bonus==0)
        return true;
    else
        return false;
}


