#include <string>
#include <iostream>
#include "Dictionnaire.h"
#include <fstream>
#include<vector>

using namespace std;

Dictionnaire::Dictionnaire(const string & nomFichier)
{
    int nbLigne, x, y;
    string name, property;
    ifstream input;
    input.open(nomFichier);

    input>>nbLigne;
    for (int i=0; i<nbLigne; i++)
    {
        input>>name;
        input>>x;
        input>>y;
        input>>property;
        _tuiles.push_back(Tuile(name,x,y,property));
    }
}

void Dictionnaire::afficher()const
{
    for(int i=0; i<_tuiles.size(); i++)
        _tuiles[i].afficher();
}

bool Dictionnaire::recherche(const string & name, Tuile & tuile)const  ///Dichotomie classique
{
    int first=0, last=_tuiles.size()-1, middle, ind=-1;
    bool found=false;

    while(!found && first<=last)
    {
        middle=(first+last)/2;
        found=_tuiles[middle].getName()==name;

        if (found)
        {
            ind=middle;
            tuile=_tuiles[middle];
        }

        else
        {
            if(_tuiles[middle].getName()>name)
                last=middle-1;
            else
                first=middle+1;
        }
    }
    return (found);
}

