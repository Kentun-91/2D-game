#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include "Moteur.h"
#include "Image.h"
#include "Niveau.h"

const int BAS=0,HAUT=3,GAUCHE=1,DROITE=2;

class Personnage{
    Image _image;
    int _x;
    int _y;
    int _skin_x;
    int _skin_y;
    int _direction;
    int _posAnim;

public:
    Personnage();

    Personnage(Image & image, int skin_x, int skin_y, int x=0, int y=0, int direction=BAS, int posAnim=0);

    //Affiche le personnage
    void dessiner()const;

    bool bordAtteint(int x, int y, int direction)const;

    void allerDroite(Niveau & niveau);
    void allerGauche(Niveau & niveau);
    void allerHaut(Niveau & niveau);
    void allerBas(Niveau & niveau);

    ///Evite que les ennemis recupere les pièces
    void allerDroiteHeros(Niveau & niveau);
    void allerGaucheHeros(Niveau & niveau);
    void allerHautHeros(Niveau & niveau);
    void allerBasHeros(Niveau & niveau);

    void mettreAJourDirection(const int direction);

    void avancer(Niveau & niveau);

    bool touche(const Personnage & personnage)const;

    void mettreAjourAnimation();

};



#endif // PERSONNAGE_H_INCLUDED
