#include <string>
#include <iostream>
#include "Objet.h"
#include "Image.h"
#include "Dictionnaire.h"

using namespace std;

Objet::Objet(Image & image, const string & nom, const Dictionnaire & dictionnaire, int x, int y)
{
    Tuile tuile;
    if(dictionnaire.recherche(nom,tuile))
    {
        image.selectionnerRectangle(tuile.getSkinx()*TAILLE_CASE, tuile.getSkiny()*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
        _image=image;
        _property=tuile.getProperty();
        _x=x*TAILLE_CASE;
        _y=y*TAILLE_CASE;
    }
}

void Objet::dessiner()const
{
    _image.dessiner(_x, _y);
}
int Objet::getx()const
{
    return _x;
}

int Objet::gety()const
{
    return _y;
}

string Objet::getProperty()const
{
    return _property;
}

void Objet::cacher()
{
    _property="cache";
}
