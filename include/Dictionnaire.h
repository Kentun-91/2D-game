#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED
#include <vector>
#include "Tuile.h"

class Dictionnaire{
    vector<Tuile> _tuiles;

public:
    Dictionnaire(const string & nomFichier);

    void afficher()const;
    bool recherche(const string & name, Tuile & tuile)const; ///Dichotomie classique
};

#endif // DICTIONNAIRE_H_INCLUDED
