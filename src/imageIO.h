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
{
 private:
	string _nom;
  	int _width;
	int _height;
  	int _prix;
	int** _MatriceImgRED;
	int** _MatriceImgGREEN;
	int** _MatriceImgBLUE;
	int _HistR[255];
	int _HistG[255];
	int _HistB[255];
	// mettre les getteur histogramme rgb les rajouter dans cpp h et tester l affichage

	/*
	_MatriceImgRED = new int*[_height];                        
	for (int i=0; i < _withdh; i++) _MatriceImgRED[i] = new int[_width];



	*/
	void allocateMatrix(int _height, int _width);



 public:
	Image();
	Image(string lena, int width, int hight, int prix);
	void openPGM (string path);
	void openPPM(string path);
	string getNom()const;
	int getWidth();
	int getHeight();
	int getPrix()const;
	int** getMatriceR();
	int** getMatriceG();
	int** getMatriceB();
	int* getHistR();
	int* getHistG();
	int* getHistB();
	
	void setNom(string nom);
	void setWidth(int width);
	void setHeight(int height);
	void setPrix( int prix);
	void fiche_Image();
	void lecture_descriptif(int choix);
	void histogramme(int hist[255]);

};
 


