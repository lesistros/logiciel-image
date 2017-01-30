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


	Bibliotheque Im;


		Im.identification();



// TRAITEMENT D IMAGE
	Image  Tree;

	Tree.LireImg("../test/sample/west_1.ppm");

	//Tree.openPPM("/home/lesistros/Documents/logiciel-image/test/sample/west_1.ppm");
	Tree.histogramme();


	Tree.convolution();
	Tree.afficher();
	return 0;


}
