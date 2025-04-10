#include <string>
#include <iostream>
#include "Tuile.h"

using namespace std;

Tuile::Tuile(const string & name, int skinx, int skiny, const string & property)
{
    _name=name;
    _skinx=skinx;
    _skiny=skiny;
    _property=property;
}

void Tuile::afficher()const
{
    cout<<_name<<": x="<<_skinx<<", y="<<_skiny<<", objet"<<endl;
}

string Tuile::getName()const
{
    return _name;
}

int Tuile::getSkinx()const
{
    return _skinx;
}

int Tuile::getSkiny()const
{
    return _skiny;
}

string Tuile::getProperty()const
{
    return _property;
}
