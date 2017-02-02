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
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"



using namespace cv;
using namespace std;



int main()
{
string path;
vector<Bibliotheque> liste;
	Bibliotheque Im;
  /*
    liste.push_back(Bibliotheque( 1 , "lena" ,46, "/home/lesistros/Documents/logiciel-image/test/sample/lena.pgm" ,'L'));cout<<endl;
    liste.push_back(Bibliotheque( 2 , "house" ,244, "/home/lesistros/Documents/logiciel-image/test/sample/house_1.ppm" ,'R')); cout<<endl;
    liste.push_back(Bibliotheque( 3 , "west" ,446, "/home/lesistros/Documents/logiciel-image/test/sample/west_1.ppm" ,'L'));cout<<endl;
    liste.push_back(Bibliotheque( 4 , "tree" ,24, "/home/lesistros/Documents/logiciel-image/test/sample/tree_1.ppm" ,'R')); cout<<endl;
    liste.push_back(Bibliotheque( 5 , "stop" ,460, "/home/lesistros/Documents/logiciel-image/test/sample/stop_1.ppm",'L'));cout<<endl;

*/


		Im.identification(liste);

//vector<Bibliotheque> _liste;
//path=_liste.GetChemin();
Im.DefinirListe(liste);
path=Im.choisir(liste);

cout << path << endl;

// TRAITEMENT D IMAGE
	Image  Tree ;
//path.ChoixImage();
	Tree.LireImg(path);
	//Tree.openPPM("/home/lesistros/Documents/logiciel-image/test/sample/west_1.ppm");
	Tree.histogramme();
	Tree.convolution();
	Tree.afficher();
	return 0;


}
