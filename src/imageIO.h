#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <algorithm> 

#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"



using namespace cv;
using namespace std;



class Image
{ private: 
	string _nom;
  	int _width;
	int _height;
  	int _prix;

  public:
   Image();
   Image(string lena, int width, int hight, int prix);

   string getNom()const;
   int getWidth()const;
   int getHeight()const;
   int getPrix()const;

   void setNom(string nom);
   void setWidth(int width);
   void setHeight(int height);
   void setPrix( int prix);
   
   void fiche_Image();
   void openPGM (string path);
   void lecture_descriptif(int choix);



};
 


