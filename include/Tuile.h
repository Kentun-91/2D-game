#ifndef TUILE_H_INCLUDED
#define TUILE_H_INCLUDED


#include <string>

using namespace std;

class Tuile{
    string _name;
    int _skinx;
    int _skiny;
    string _property;

public:
    Tuile(const string & name="vide", int skinx=0, int skiny=0, const string & property="vide");

    void afficher()const;
    string getName()const;
    int getSkinx()const;
    int getSkiny()const;
    string getProperty()const;
};



#endif // TUILE_H_INCLUDED
