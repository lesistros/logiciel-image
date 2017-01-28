#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <algorithm>


#include "Bibliotheque.h"
#include "imageIO.h"


#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"



using namespace cv;
using namespace std;



int main()
{


	Bibliotheque Im(1,"lena",1);

	vector<Bibliotheque> liste;
	//remplissage de la liste

	liste.push_back(Bibliotheque( 1 , "lena" ,46));cout<<endl;
    liste.push_back(Bibliotheque( 2 , "house" ,24)); cout<<endl;
    liste.push_back(Bibliotheque( 3 , "west" ,46));cout<<endl;



    int choix;
   do {
      cout<< "\t----- Bonjour -----" <<endl;
      cout<< "\t 1 - Ajout" <<endl;
      cout<< "\t 2 - Affichage" <<endl;
      cout<< "\t 3 - Recherche" <<endl;
      cout<< "\t 4 - Suppression" <<endl;
      cout<< "\t 5 - Sauvegarde" <<endl;
      cout<< "\t 6 - Sortie" <<endl;
      cout<< "\n  veuillez choisir une action (1 à 5) : " ;
      cin>>choix; //lecture du choix de l'utilisateur
      switch(choix)
		{

		case 1:	Im.ajout(liste);break;
		case 2:	Im.affichage(liste);break;
		case 3:	Im.recherche(liste);break;
		case 4:	Im.suppression(liste);break;
		case 5:	Im.sauvegarde(liste);break;

		case 6: cout<<"sortir du programme";break;
		default:cout<<"erreur;r";break;
		}
	}
		while (choix!=6);


// TRAITEMENT D IMAGE
	Image  Tree;

	Tree.LireImg("../test/sample/lena.pgm");

	//Tree.openPPM("/home/lesistros/Documents/logiciel-image/test/sample/west_1.ppm");
	Tree.histogramme();


	Tree.convolution();
	Tree.afficher();
	return 0;


}
