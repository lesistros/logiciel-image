
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <algorithm> 

#include"imageIO.h"


#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"


using namespace std;

Image::Image()
	{



	}

Image::Image(string lena, int width, int hight, int prix)
	{ 
		_nom=lena;
		_width=width;
		_height=hight;
		_prix=prix;
	}

string Image::getNom()const
	{
		return _nom;
	}

int Image::getWidth()
	{
		//_width = width;
		return _width;
	}

int** Image::getMatriceR()
	{
		
		return _MatriceImgRED;
	}
 

int** Image::getMatriceG()
	{
		
		return _MatriceImgGREEN;
	}

int** Image::getMatriceB()
	{
		
		return _MatriceImgBLUE;
	}
 


int* Image::getHistRED()
	{
		
		return _HistRED;
	}

int* Image::getHistGREEN()
	{
		
		return _HistGREEN;
	}

int* Image::getHistBLUE()
	{
		
		return _HistBLUE;
	}


int Image::getHeight()
	{
		return _height;
	}		


int Image::getPrix()const
	{
		return _prix;
	}

  // les setters
void Image::setNom(string nom)
	{ 
		_nom=nom;
	}
void Image::setHeight(int height)
	{
		_height=height;
	}
void Image::setWidth(int width)
	{
		_width=width;
	}
void Image::setPrix(int prix)
	{
		_prix=prix;
	}


void Image::openPGM(string path)
{       
	string line;
	ifstream myfile(path, ios::binary);
	int i =0;
	string filetype = "";
	//int width = 0;
	//int height= 0;
	int maxColor = 0;
	string temp;
	int nbrBytes;
	char byte;
	int pixel;
	
	



	
	if(myfile.is_open())
	{	
		//lecture du type de fichier P5 ou P6
		getline (myfile,line);
		filetype = line;

		
		//lecture des dimensions de l'image;
		getline (myfile,line);
		sscanf(line.c_str(),"%i %i",&_width,&_height);

		//read max value
		getline(myfile , line);
		
		maxColor = atoi ( line.c_str());


		
		//cout << "Type du fichier : " << filetype << "\n";
		//cout << "Taille : " << _width << " x " << _height << "\n";
		//cout << "Max scale : " << maxColor << "\n\n\n";
		   
		nbrBytes = _width * _height;

		//nbrBytes = 20;
		int compteur=1;
		unsigned int compteur_col=1;
		unsigned int compteur_lign=1;
		
		while (nbrBytes != 0 )
		{
			myfile.get(byte);
			pixel = byte;
			if (byte<0)
			{
			
			//cout << "byte : " << int(byte) << endl;
			
			//cout << "pixel numero = " << compteur<< endl; 
			//cout << "colonne : " << compteur_col << " ligne : " << compteur_lign << endl;
			//cout << "valeur du pixel : " << 256+pixel << "\n";
				nbrBytes--;
				compteur ++;
				compteur_col ++;
				if(compteur_col == _width+1)
					{
						compteur_col = 1;
						compteur_lign = compteur_lign + 1;
						
					}	
			}
			else
				{
			
					
					nbrBytes--;
					compteur ++;
					compteur_col ++;
					
					if(compteur_col == _width+1)
						{
							compteur_col = 1;
							compteur_lign = compteur_lign + 1;
							
						}
					
				}
			
		}
		
		
		myfile.close();

	}


	
	else cout << "pas possible d ouvrir l image";


		//cout << "fin de fonction pgm"<< endl;

}	



void Image::allocateMatrix(int _height, int _width)
{
	
	int h;

	_MatriceImgRED = new int*[_height];
	_MatriceImgGREEN = new int*[_height];
	_MatriceImgBLUE = new int*[_height];
	
	for(h = 0; h < _height; h++)
		{
			_MatriceImgRED[h] =  new int[_width];
			_MatriceImgGREEN[h] =  new int[_width];
			_MatriceImgBLUE[h] =  new int[_width];	
		}
}


void Image::openPPM(string path)
{ 

string line;
ifstream myfile(path, ios::binary);
int i =0;
string filetype = "";
//int _width = 0;
//int _height= 0;
int maxColor = 0;
string temp;
int nbBytes;
char byte;
int pixel;


int l=0;
// TEST
// initialisation a 0
for(l=0; l<255; l++)
{
	_HistRED[l] = 0;
	_HistGREEN[l] =0;
	_HistBLUE[l] =0;
	
}


	

//initialisation couleurs
//ce ci sert pour d eventuels back ups
ofstream RED;
RED.open ("../test/ImageEnCoursDeTraitement/RED.pgm");
ofstream GREEN;
GREEN.open ("../test/ImageEnCoursDeTraitement/GREEN.pgm");
ofstream BLUE;
BLUE.open ("../test/ImageEnCoursDeTraitement/BLUE.pgm");
ofstream verif;
verif.open ("../test/ImageEnCoursDeTraitement/verif.txt");

	
if(myfile.is_open())
	{	

		// Lecture entete
		// lecture du type de fichier P5 ou P6
		getline (myfile,line);
		filetype = line;
	
		//lecture des dimensions de l'image;
		getline (myfile,line);
		sscanf(line.c_str(),"%i %i",&_width,&_height);

		//read max value
		getline(myfile , line);
		maxColor = atoi ( line.c_str());
		/*
		cout << "Type du fichier : " << filetype << "\n";
		cout << "Taille : " << width << " x " << height << " x 3 "<<"\n";
		cout << "Max scale : " << maxColor << "\n\n\n";
		*/

		// remise sour la forme des formats PGM pour afficher (pas obligatoire)

		RED <<	"P2" << "\n"; //p2 pour le noir et blanc pour afficher avec open cv
		RED <<	_width << " " << _height <<"\n";
		RED <<	maxColor << "\n";

		GREEN << "P2" << "\n";
		GREEN << _width << " " << _height <<"\n";
		GREEN << maxColor << "\n";

		BLUE << "P2" << "\n";
		BLUE << _width << " " << _height <<"\n";
		BLUE << maxColor << "\n";

		nbBytes = _width * _height *3 ;
	
		// creation d une matrice pour un futur traitement
		



		allocateMatrix(_height, _width);
		
		//lecture pixels
		// a faire attention, isoler les couleurs (R G B)

		//initialisation des compteurs pour remplir les matrices :
		//Rouge
		int i=0; //Ligne
		int j=0; //Colonne
		//Vert
		int a=0; //Ligne
		int s=0; //Colonne
		//BLEU
		int d=0; //Ligne
		int f=0; //Colonne



		int compteur=1;
		unsigned int compteur_col=1;
		unsigned int compteurPIX=1;
		
	while (nbBytes != 0)
		{	
			
			myfile.get(byte);
			pixel = byte;


			compteurPIX++;


			if(byte<0)
				{
			
					nbBytes--;
			
					if (compteur==1)
						{
							// MATRICE COULEUR ROUGE

  							RED << pixel+256 << " ";
							_MatriceImgRED[i][j] = pixel+256;
							//cout << _MatriceImgRED[i][j] << " "; 
							compteur++;
							j=j+1;

							// TEST Histogramme
							_HistRED[pixel+256]=_HistRED[pixel+256]+1;
							
				
						}
					else if(compteur == 2 )
						{
							// VERT
							GREEN << pixel+256 << " ";
							_MatriceImgGREEN[a][s] = pixel+256;
							s=s+1;
							compteur++;
							_HistGREEN[pixel+256]=_HistGREEN[pixel+256]+1;
	

						}
					else
						{
							// BLEU

							BLUE << pixel+256 << " ";
							_MatriceImgBLUE[d][f] = pixel+256;
							f=f+1;
							compteur = 1;
							compteur_col ++;
							_HistBLUE[pixel+256]=_HistBLUE[pixel+256]+1;
							if(pixel+256>255 || pixel+256<0 )
							verif << pixel+256 <<" ";
							}
				}
			else
				{
			
					nbBytes--;
		
					if (compteur==1)
						{
							//ROUGE
  							RED << pixel  << " ";
							_MatriceImgRED[i][j] = pixel;
							//verif << _MatriceImgRED[i][j] << " "; 
							//cout << MatriceImgRED[i][j] <<endl;
							compteur++;
							j=j+1;
							_HistRED[pixel]=_HistRED[pixel]+1;
//cout << _HistRED[pixel]<< "VERIFICATION"<<endl;


						}
					else if(compteur == 2 )
						{
							//VERT
							_MatriceImgGREEN[a][s] = {pixel};
							GREEN << pixel  << " ";
							s=s+1;
							compteur++;
							_HistGREEN[pixel]=_HistGREEN[pixel]+1;
						}
					else
						{
							//BLEU
							_MatriceImgBLUE[d][f] = {pixel};
							BLUE << pixel  << " ";
							compteur = 1;
							compteur_col ++;
							f=f+1;
							
							_HistBLUE[pixel]=_HistBLUE[pixel]+1;
							//cout << d <<" "<< f << endl;
							//cout << "ca bug ici"<< endl;
							if(pixel>255 || pixel<0 )
							verif << pixel <<" ";
						}
				}
			
			if(j == _width)
				{	//Cette verification sert a pouvoir rester dans les dim de la matrice et la structurer
				
					i=i+1;
					j=0;
				}	
			if(s == _width)
				{
					a=a+1;
					s=0;
				}
			if(f == _width)	
				{
					d=d+1;
					f=0;
					
				}
			
			if(compteur_col == _width && compteur == 3)
				{

					RED << "\n";
					GREEN << "\n";
					BLUE << "\n";
					//cout << compteur_col << " ";
					compteur_col = 1;
				
				
				}
				
			if(compteurPIX==_width*_height*3)
				{
					//cout << compteurPIX << endl; 
					nbBytes=0;
			 	}
			//cout << d << endl;
			//cout << "ligne "<<a <<"colonne "<< s << endl;
			//cout << MatriceImgGREEN[i][j] << endl;
			
		}
		//cout << compteur_col << endl;	
		RED.close();
		GREEN.close();
		BLUE.close();
		verif.close();

	}
	else cout << "pas possible d ouvrir l image"<< endl;	
		//cout<< "openppm "<< _HistRED[67] <<" openppm"<<endl ;
		//cout << "fin de fonction openppm"<< endl;

}

void Image::histogramme()
{ 
// MATRICES POUR LES HISTOGRAMMES DES COULEURS

//cout << " ca rentre meme pas icic "<< endl;
//Initialisation matrice histogramme

Mat HISTR(256,256,CV_32FC1,0.0f);
Mat HISTG(256,256,CV_32FC1,0.0f);
Mat HISTB(256,256,CV_32FC1,0.0f);

int n = 0;

//cout<< "histogramme "<< _HistRED[67] <<" histogramme"<<endl ;
	
		for (n=0; n<256; n++)
		{
			
			
			//cout << n << " ";
			HISTR.at<float>(256-_HistRED[n] ,n) = _HistRED[n];
			HISTG.at<float>(256-_HistGREEN[n] ,n) = _HistGREEN[n];
			//HISTB.at<float>(256-_HistBLUE[n] ,n) = _HistBLUE[n];
			
		}


namedWindow( "HISTOGRAMME ROUGE ",  WINDOW_AUTOSIZE  );    
imshow( "HISTOGRAMME  ROUGE ", HISTR );
waitKey(0);
namedWindow( "HISTOGRAMME VERT ",  WINDOW_AUTOSIZE  );    
imshow( "HISTOGRAMME VERT ", HISTG );
waitKey(0);
namedWindow( "HISTOGRAMME BLEU ",  WINDOW_AUTOSIZE  );    
imshow( "HISTOGRAMME BLEU ", HISTB );
waitKey(0);
//destroyAllWindows();
	

}


		
void Image::afficher()
{


// initialisation des matrices pour chaques couleurs



ofstream monimage;
monimage.open ("../test/ImageEnCoursDeTraitement/monimage");

	
//cout<< _height<<" sffdgsdfgfvavfev" ;
//Mat imageR(_height,_width,CV_32FC1,0.0f);
//Mat imageG(height,width,CV_32FC1,0.0f);	
//Mat imageB(height,width,CV_32FC1,0.0f);

ofstream OPCV;
OPCV.open ("../test/ImageEnCoursDeTraitement/OPVC.txt");
ofstream MOI;
MOI.open ("../test/ImageEnCoursDeTraitement/MOI.txt");		
	
//cout << _width << "sdfwefwefjkwehkjwhef"  ;

monimage << "[";

// mon imread
int v=0;
int b=0;
Mat image(_height,_width/2,CV_8UC3);
	

//_width << " " << _height

	
		for (v=0; v<_height ; v++ )	
			{
			for(b=0; b< _width ; b++ )
				{


					
					image.at<uchar>(v,b)=_MatriceImgBLUE[v][b];
					image.at<uchar>(v,b+1)=_MatriceImgBLUE[v][b];
					image.at<uchar>(v,b+2)=_MatriceImgBLUE[v][b];
					b=b+2;
					//cout << _MatriceImgRED[v][b] << endl;
					/*
					if(_MatriceImgRED[v][b]<100)
					{
					monimage<< " ";
					monimage <<_MatriceImgRED[v][b]<< ", ";
					}
					else {
					monimage <<_MatriceImgRED[v][b]<< ", ";
					}
					if(_MatriceImgRED[v][b]<100)
					{
					monimage<< " ";
					monimage <<_MatriceImgRED[v][b]<< ", ";
					}
					else {
					monimage <<_MatriceImgRED[v][b]<< ", ";
					}


					if(_MatriceImgRED[v][b]<100)
					{

					monimage<< " ";
					monimage <<_MatriceImgRED[v][b];
					if(b == _width-1)
					{
					monimage<< ";"<< "\n"<<" ";
					}
					else monimage << ", ";
										
					//monimage <<_MatriceImgRED[v][b]<< ", ";
									
					}
					else
					{
					monimage <<_MatriceImgRED[v][b];
					if(b == _width-1)
					{
					monimage<< ";"<< "\n"<<" ";
					}
					else monimage << ", ";

					}

					cout << b << endl;				
					
					//cout << MatriceImg[v][b][1] << endl;
					//imageR.at<float>(v,b+1) = _MatriceImgRED[v][b+1];
					//imageR.at<float>(v,b+2) = _MatriceImgRED[v][b+2];
					//b=b+2;		
					)
					*/

				}
			}


		//smonimage << "]";
		// Affichage avec openCV		

		//myfile.close();
		//Mat image;
		
			

  		monimage.close();
    		


		//cout << histImg;
		//image = imread("../test/ImageEnCoursDeTraitement/RED.pgm");
		OPCV << image;
		//MOI << imageR;
	
		//cout << image;
		namedWindow( "Display window");   // Create a window for display.
		imshow( "Display window", image);                    // Show our image inside it.    
		waitKey(0);
		destroyAllWindows();

OPCV.close();
MOI.close();
		




}




