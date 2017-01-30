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
	int PPM=0;
	int PGM=0;
  int _maxcolor;
  int _width;
	int _height;
  int _prix;
	float** _MatriceImgNb;
	int** _MatriceImgRED;
	int** _MatriceImgGREEN;
	int** _MatriceImgBLUE;

	int _HistNb[255];
  int _maxNB;
	int _HistRED[255];
  int _maxRED;
	int _HistGREEN[255];
  int _maxGREEN;
	int _HistBLUE[255];
  int _maxBLUE;
	float _Filtre[3][3];
	float filtre1[3][3]={{0.110,0.110,0.110},{0.110,0.110,0.110},{0.110,0.110,0.110}};
	int filtre2[3][3]={{-1,0,1},{-1,0,1},{-1,0,1}};
	int filtre3[3][3]={{1,1,1},{0,0,0},{-1,-1,-1}};
	int filtre4[3][3]={{-1,-1,-1},{-1,18,-1},{-1,-1,-1}};
	// mettre les getteur histogramme rgb les rajouter dans cpp h et tester l affichage

	/*
	_MatriceImgRED = new int*[_height];
	for (int i=0; i < _withdh; i++) _MatriceImgRED[i] = new int[_width];



	*/
	void allocateMatrix(int _height, int _width);



 public:
	int** _MatriceCov;
	int** _MatriceCov2;
	int** _MatriceCovNB;
	int** _MatriceCovRED;
	int** _MatriceCovGREEN;
	int** _MatriceCovBLUE;
	Image();
	Image(string lena, int width, int hight, int prix);
	void openPGM (string path);
	void openPPM(string path);
	void LireImg(string path);
	string getNom()const;
	int getWidth();
	int getHeight();
	int getPrix()const;
	void Filtre();
  void maxhist();
	int** getMatriceR();
	int** getMatriceG();
	int** getMatriceB();
	int* getHistRED();
	int* getHistGREEN();
	int* getHistBLUE();

	void setNom(string nom);
	void setWidth(int width);
	void setHeight(int height);
	void setPrix( int prix);

	void fiche_Image();
	void lecture_descriptif(int choix);
	void convolution();
	void convolution2();
	void histogramme();
	void afficher();

};
