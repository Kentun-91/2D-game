#include <string>
#include <iostream>
#include <stdexcept>
#include "Personnage.h"
#include "Image.h"

using namespace std;

//empty constructor
Personnage::Personnage()
{
    _x= 0;
    _y= 0;
}

//Constructeur
Personnage::Personnage(Image & image, int skin_x, int skin_y, int x, int y, int direction, int posAnim)
{
    image.selectionnerRectangle(skin_x,skin_y,TAILLE_CASE,TAILLE_CASE);
    _image=image;
    _x=x;
    _y=y;
    _skin_x=skin_x;
    _skin_y=skin_y;
    _direction=direction;
    _posAnim=posAnim;
}


//Affiche le personnage
void Personnage::dessiner()const
{
    _image.dessiner(_x,_y);
}

bool Personnage::bordAtteint(int x, int y, int direction)const
{
    switch (direction)
    {
    case DROITE :
        return ((_x+2*TAILLE_CASE>LARGEUR_FENETRE));
    case GAUCHE:
        return ((_x-TAILLE_CASE<0));
    case BAS:
        return ((_y+2*TAILLE_CASE>HAUTEUR_FENETRE));
    case HAUT:
        return ((_y-TAILLE_CASE<0));
    }
}

void Personnage::allerDroite(Niveau & niveau)
{
    if(!bordAtteint(_x,_y,GAUCHE) && niveau.caseEstLibre(_x+1*TAILLE_CASE,_y))
        _x=_x+TAILLE_CASE;
    mettreAJourDirection(DROITE);
}

void Personnage::allerGauche(Niveau & niveau)
{
    if (!bordAtteint(_x,_y,GAUCHE)&& niveau.caseEstLibre(_x-1*TAILLE_CASE,_y))
        _x=_x-TAILLE_CASE;
    mettreAJourDirection(GAUCHE);
}

void Personnage::allerBas(Niveau & niveau)
{
    if (!bordAtteint(_x,_y,BAS)&& niveau.caseEstLibre(_x,_y+1*TAILLE_CASE))
        _y=_y+TAILLE_CASE;
    mettreAJourDirection(BAS);
}

void Personnage::allerHaut(Niveau & niveau)
{
    if (!bordAtteint(_x,_y,HAUT)&& niveau.caseEstLibre(_x,_y-1*TAILLE_CASE))
        _y=_y-TAILLE_CASE;
    mettreAJourDirection(HAUT);
}

///Evite que les ennemis réupère les pièces
void Personnage::allerDroiteHeros(Niveau & niveau)
{
    allerDroite(niveau);
    niveau.testerBonusEtPrendre(_x,_y);
}

void Personnage::allerGaucheHeros(Niveau & niveau)
{
    allerGauche(niveau);
    niveau.testerBonusEtPrendre(_x,_y);
}

void Personnage::allerHautHeros(Niveau & niveau)
{
    allerHaut(niveau);
    niveau.testerBonusEtPrendre(_x,_y);
}

void Personnage::allerBasHeros(Niveau & niveau)
{
    allerBas(niveau);
    niveau.testerBonusEtPrendre(_x,_y);
}

void Personnage::mettreAJourDirection(const int direction)
{
    switch (direction)
    {
    case DROITE :
        _image.selectionnerRectangle(_skin_x*TAILLE_CASE,(_skin_y+2)*TAILLE_CASE,TAILLE_CASE,TAILLE_CASE);
        _direction=DROITE;
        break;
    case GAUCHE:
        _image.selectionnerRectangle(_skin_x*TAILLE_CASE,(_skin_y+1)*TAILLE_CASE,TAILLE_CASE,TAILLE_CASE);
        _direction=GAUCHE;
        break;
    case BAS:
        _image.selectionnerRectangle(_skin_x*TAILLE_CASE,_skin_y*TAILLE_CASE,TAILLE_CASE,TAILLE_CASE);
        _direction=BAS;
        break;
    case HAUT:
        _image.selectionnerRectangle(_skin_x*TAILLE_CASE,(_skin_y+3)*TAILLE_CASE,TAILLE_CASE,TAILLE_CASE);
        _direction=HAUT;
    }
}

void Personnage::avancer(Niveau & niveau)
{
    _direction= rand() % 4;
    if (bordAtteint(_x,_y,_direction))
    {
        switch (_direction)
        {
        case DROITE :
            _direction=GAUCHE;
            break;
        case GAUCHE:
            _direction=DROITE;
            break;
        case BAS:
            _direction=HAUT;
            break;
        case HAUT:
            _direction=BAS;
        }
    }

    switch (_direction)
    {
    case DROITE :
        allerDroite(niveau);
        break;
    case GAUCHE:
        allerGauche(niveau);
        break;
    case BAS:
        allerBas(niveau);
        break;
    case HAUT:
        allerHaut(niveau);
    }
}

bool Personnage::touche(const Personnage & personnage)const
{
    return(_x==personnage._x && _y ==personnage._y);
}

void Personnage::mettreAjourAnimation()
{
    _posAnim=(_posAnim+1)%4;
    switch (_posAnim)
    {
    case 0:
        _image.selectionnerRectangle(_skin_x*TAILLE_CASE, (_skin_y+_direction)*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
        break;
    case 1:
        _image.selectionnerRectangle((_skin_x+1)*TAILLE_CASE, (_skin_y+_direction)*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
        break;
    case 2:
        _image.selectionnerRectangle(_skin_x*TAILLE_CASE, (_skin_y+_direction)*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
        break;
    case 3:
        _image.selectionnerRectangle((_skin_x-1)*TAILLE_CASE, (_skin_y+_direction)*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
        break;
    }
}






