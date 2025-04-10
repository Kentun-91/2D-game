#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include <iostream>
#include <string>
#include "Moteur.h"
#include "Image.h"
#include "Dictionnaire.h"

using namespace std;

class Objet{
    Image _image;
    int _x;
    int _y;
    string _property;

public:
    Objet(Image & image, const string & nom, const Dictionnaire & dictionnaire, int x, int y);
    void dessiner()const;

    int getx()const;
    int gety()const;
    string getProperty()const;
    void cacher();
};


#endif // OBJET_H_INCLUDED
