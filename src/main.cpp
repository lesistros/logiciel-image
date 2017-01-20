#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <algorithm> 

#include "imageIO.h"



#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"



using namespace cv;
using namespace std;



int main( int argc, char** argv)
{	
	//format PGM
	/*
	Image Lena,Tree,hauteur;
 	Lena.openPGM("/home/lesistros/Documents/logiciel-image/test/sample/lena.pgm");
	
	Lena.getWidth();
	cout << "taille : " << Lena.getWidth()<< endl; 
	*/

	//format PPM
	Image Tree,histr;
	Tree.openPPM("/home/lesistros/Documents/logiciel-image/test/sample/tree_1.ppm");
	Tree.histogramme(Tree.getHistRED());
//for (int n= 0; n<255;n++)	
	//cout << *Tree.getHistRED()<< " ";

	
	//A Image("../test/sample/lena.pgm");

	//format PPM

	
	
	
	return 0;


}
