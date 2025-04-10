#include <vector>
#include <iostream>
#include "Tuile.h"
#include "Dictionnaire.h"
#include "Objet.h"
#include "Image.h"

using namespace std;

int main(int, char**){

    Dictionnaire dictionnaire("assets/dictionnaire.txt");
    dictionnaire.afficher();
    cout<<endl<<endl<<endl;

    Tuile tuile;
    if (dictionnaire.recherche("Montagne_1", tuile))
    {
        cout<<"Test OK"<<endl;
        tuile.afficher();
    }
    else
        cout<<"Test not OK"<<endl;

    if (dictionnaire.recherche("caseQuiNexistePasDuTout", tuile))
    {
        cout<<"Test not OK"<<endl;
        tuile.afficher();
    }
    else
        cout<<"Test OK"<<endl;



    return 0;

}
