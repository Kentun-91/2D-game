#include <vector>

#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"
#include "Dictionnaire.h"
#include "Niveau.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
  // Initialisation du jeu
  Moteur moteur("Mon super jeu vidéo");

  // TODO: charger images, creer personnages, etc.

  /*
    Image fond;
    try
    {
    fond = Image(moteur, "assets/fond.png");
    }
    catch(runtime_error)
    {
        cout<<"Cette image n'existe pas"<<endl;
    }
    */

    ///Création des images et des personnages :

    Image img_hero;
    try
    {
    img_hero = Image(moteur, "assets/personnages.png");
    }
    catch(runtime_error)
    {
        cout<<"Erreur avec l'image du heros"<<endl;
    }
    Personnage heros= Personnage(img_hero,4,0,TAILLE_CASE,2*TAILLE_CASE);

    Image img_ennemi1;
    try
    {
    img_ennemi1 = Image(moteur, "assets/personnages.png");
    }
    catch(runtime_error)
    {
        cout<<"Erreur avec l'image de l'ennemi 1"<<endl;
    }
    Personnage ennemi1= Personnage(img_ennemi1,7,4,6*TAILLE_CASE,2*TAILLE_CASE,HAUT);

    Image img_ennemi2;
    try
    {
    img_ennemi2 = Image(moteur, "assets/personnages.png");
    }
    catch(runtime_error)
    {
        cout<<"Erreur avec l'image de l'ennemi 1"<<endl;
    }
    Personnage ennemi2= Personnage(img_ennemi2,4,4,TAILLE_CASE,5*TAILLE_CASE,DROITE);

    ///Création du niveau

    Image objets;
    try
    {
    objets = Image(moteur, "assets/objets.png");
    }
    catch(runtime_error)
    {
        cout<<"Erreur avec l'image pour le niveau"<<endl;
    }

    Dictionnaire dictionnaire("assets/dictionnaire.txt");
    //dictionnaire.afficher()

    Niveau niveau1(objets,"assets/niveau1.txt",dictionnaire);

    ///Création des images de fin
    Image bravo;
    try
    {
    bravo = Image(moteur, "assets/bravo.png");
    }
    catch(runtime_error)
    {
        cout<<"Erreur avec l'image de bravo"<<endl;
    }

    Image gameover;
    try
    {
    gameover = Image(moteur, "assets/gameover.png");
    }
    catch(runtime_error)
    {
        cout<<"Erreur avec l'image de gameover"<<endl;
    }

  bool quitter = false;

  // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
  // (en general, 60 fois par seconde)
  while (!quitter)
  {
    // I. Gestion des evenements
    Evenement evenement = moteur.evenementRecu();
    while (evenement != AUCUN)
    {
      switch (evenement)
      {
        // QUITTER = croix de la fenetre ou Echap
        case QUITTER_APPUYE:
          quitter = true;
          break;
        // TODO: gerer les autres evenements
        case ESPACE_APPUYE:
            break;
        case HAUT_APPUYE:
            heros.allerHautHeros(niveau1);
            break;
        case BAS_APPUYE:
            heros.allerBasHeros(niveau1);
            break;
        case GAUCHE_APPUYE:
            heros.allerGaucheHeros(niveau1);
            break;
        case DROITE_APPUYE:
            heros.allerDroiteHeros(niveau1);
            break;
        default:
          break;
      }

      evenement = moteur.evenementRecu();
    }

    // II. Mise à jour de l'état du jeu

    // TODO: faire bouger vos personnages, etc.

    if (moteur.animationsAmettreAjour())
    {
        heros.mettreAjourAnimation();
        ennemi1.mettreAjourAnimation();
        ennemi2.mettreAjourAnimation();
        ennemi1.avancer(niveau1);
        ennemi2.avancer(niveau1);
    }





    // III. Generation de l'image à afficher

    moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

    // TODO: afficher vos personnages, objets, etc.

    //fond.dessiner(0,0);

    niveau1.dessiner();

    heros.dessiner();
    ennemi1.dessiner();
    ennemi2.dessiner();

    /*
      Affiche l'image en se cadencant sur la frequence de
      rafraichissement de l'ecran (donc va en general mettre le
      programme en pause jusqu'a ce que l'ecran soit rafraichi). En
      general, 60 images fois par seconde, mais ca peut dependre du
      materiel
    */



    moteur.finaliserRendu();
    if (!quitter) ///Sans ça on ne peut plus cliquer sur la croix
    {
        quitter=(heros.touche(ennemi1) || heros.touche(ennemi2));
        if (quitter)
        {
            gameover.dessiner(2*TAILLE_CASE,3*TAILLE_CASE);
            moteur.finaliserRendu();
            moteur.attendre(3);
        }

        if(niveau1.gagne())
        {
            quitter=true;
            bravo.dessiner(2*TAILLE_CASE,3*TAILLE_CASE);
            moteur.finaliserRendu();
            moteur.attendre(3);
        }


    }
  }

  return 0;
}
