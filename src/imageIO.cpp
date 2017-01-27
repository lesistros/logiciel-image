
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


void Image::LireImg(string path)
{
	 
 

	string line;
	ifstream myfile(path, ios::binary);
	stringstream ss;
	string filetype = "";
	if(myfile.is_open())
	{	
		//lecture du type de fichier P5 ou P6
		getline (myfile,line);
		filetype = line;
		if ((line.compare("P6") == 0))
		{
		cout << "je suis ici" << endl;		
		myfile.close();
		openPPM(path);
		}		
		else
		{
		cout << "je suis la" << endl;	
		myfile.close();		
		openPGM(path);
		}
	}	
	else
	cout << "erreur version image" << endl;



}

void Image::openPGM(string path)
{       
	PGM=1;
	string line;
	ifstream myfile(path, ios::binary);
	int i =0;
	string filetype = "";
	int maxColor = 0;
	string temp;
	int nbrBytes;
	char byte;
	int pixel;
	
	
int l=0;
// TEST
// initialisation a 0
for(l=0; l<256; l++)
{
	_HistNb[l] = 0;
	
	
}

//Initialisation de la copie nb de l image
ofstream ImageNb;
ImageNb.open ("../test/ImageEnCoursDeTraitement/ImageNb.pgm");
	
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

		ImageNb <<	"P2" << "\n"; //p2 pour le noir et blanc pour afficher avec open cv
		ImageNb <<	_width << " " << _height <<"\n";
		ImageNb <<	maxColor << "\n";
		
		//cout << "Type du fichier : " << filetype << "\n";
		//cout << "Taille : " << _width << " x " << _height << "\n";
		//cout << "Max scale : " << maxColor << "\n\n\n";
		
		nbrBytes = _width * _height;

		allocateMatrix(_height, _width);

		int i=0; // ligne
		int j=0; // colonne
		int compteur=1;
		unsigned int compteur_col=1;
		unsigned int compteur_lign=1;
		unsigned int compteurPIX=1;	

		while (nbrBytes != 0 )
		{	
			compteurPIX++;
			myfile.get(byte);
			pixel = byte;
			if (byte<0)
			{

				
				_MatriceImgNb[i][j] = pixel+256;
				j=j+1;
				//cout << j << endl;
				ImageNb << pixel+256 << " ";
				//compteur ++;
				compteur_col ++;
				//_HistNb[pixel+256]=_HistNb[pixel+256]+1;
		
				if(compteur_col == _width)
					{
						ImageNb  << "\n";


					}

	
			}
			else
				{
					_MatriceImgNb[i][j] = pixel;
					//cout << j << endl;
					j=j+1;
					ImageNb << pixel << " ";
					nbrBytes--;
					
					compteur_col ++;
					//_HistNb[pixel]=_HistNb[pixel]+1;


					
					 if(compteur_col == _width)
					{
						ImageNb << "\n";
						compteur_col = 1;


					}
					
				}
			
			if(j == _width)
				{	//Cette verification sert a pouvoir rester dans les dim de la matrice et la structurer
				
					
					i=i+1;
					j=0;
				}
			if(compteurPIX == (_width* _height))
				{
					
					nbrBytes=0;
			 	}
		}
		
		
		myfile.close();
		ImageNb.close();

	}


	
	else cout << "pas possible d ouvrir l image";



}	



void Image::allocateMatrix(int _height, int _width)
{
	
	int h;
	
	_MatriceImgNb	= new int*[_height];
	_MatriceImgRED = new int*[_height];
	_MatriceImgGREEN = new int*[_height];
	_MatriceImgBLUE = new int*[_height];
	_MatriceCovRED = new int*[_height];
	_MatriceCovGREEN = new int*[_height];
	_MatriceCovBLUE = new int*[_height];
	_MatriceCovNB = new int*[_height];


	for(h = 0; h < _height; h++)
		{
			_MatriceImgNb[h] =   new int[_width];
			_MatriceImgRED[h] =  new int[_width];
			_MatriceImgGREEN[h] =  new int[_width];
			_MatriceImgBLUE[h] =  new int[_width];	
			_MatriceCovNB[h] = new int[_width];
			_MatriceCovRED[h] = new int[_width];
			_MatriceCovGREEN[h] = new int[_width];
			_MatriceCovBLUE[h] = new int[_width];
		}

}


void Image::openPPM(string path)
{ 
PPM=1;
string line;
ifstream myfile(path, ios::binary);
int i =0;
string filetype = "";

int maxColor = 0;
string temp;
int nbBytes;
char byte;
int pixel;


int l=0;
// TEST
// initialisation a 0
for(l=0; l<256; l++)
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

		nbBytes = _width * _height * 3;
	
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
							compteur++;
							j=j+1;
							_HistRED[pixel]=_HistRED[pixel]+1;
							


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
			
			
		}
		
		RED.close();
		GREEN.close();
		BLUE.close();
		verif.close();

	}
	else cout << "pas possible d ouvrir l image"<< endl;	
		

}

void Image::histogramme()
{ 
// MATRICES POUR LES HISTOGRAMMES DES COULEURS
//Initialisation matrice histogramme

int n = 0;

	if(PPM==1 && PGM==0)
		{
	Mat HISTR(256,256,CV_32FC1,0.0f);
	Mat HISTG(256,256,CV_32FC1,0.0f);
	Mat HISTB(256,256,CV_32FC1,0.0f);
		for (n=0; n<256; n++)
		{
			
			
			//cout << n << " ";
			HISTR.at<float>(256-_HistRED[n] ,n) = _HistRED[n];
			HISTG.at<float>(256-_HistGREEN[n] ,n) = _HistGREEN[n];
			HISTB.at<float>(256-_HistBLUE[n] ,n) = _HistBLUE[n];
			
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
destroyAllWindows();
	}

if(PPM==0 && PGM==1)
		{
		Mat HISTNB(256,256,CV_32FC1,0.0f);
		for (n=0; n<256; n++)
		{
			
			
			//cout << n << " ";
			HISTNB.at<float>(256-_HistNb[n] ,n) = _HistNb[n];
			
			
		}
		

namedWindow( "HISTOGRAMME NOIR et BLANC ",  WINDOW_AUTOSIZE  );    
imshow( "HISTOGRAMME NOIR et BLANC ", HISTNB );
waitKey(0);
destroyAllWindows();
	}


}


void Image::Filtre()
{
	int choix=0;
	cout << "quel type de filtrage voulez vous effectuer ?" << endl;
	cout << "1-filtre moyenneur" << "\n" << "2-fitre gradient en X" << "\n" << "3-filtre gradient en Y" << "\n" << "4- filtre rehausseur" << endl;
	cin >> choix;
	

	if(choix == 1)
{
	for(int i=0;i<3;i++)
		{
		for(int j=0;j<3;j++)
			{
			_Filtre[i][j]=filtre1[i][j];
			}
		}	

}
	else if(choix == 2)
	{
	for(int i=0;i<3;i++)
		{
		for(int j=0;j<3;j++)
			{
			_Filtre[i][j]=filtre2[i][j];
			}
		}

	}
	else if(choix == 3)
{
	for(int i=0;i<3;i++)
		{
		for(int j=0;j<3;j++)
			{
			_Filtre[i][j]=filtre3[i][j];
			}
		}

}
	else
	{
	for(int i=0;i<3;i++)
		{
		for(int j=0;j<3;j++)
			{
			_Filtre[i][j]=filtre4[i][j];
			}
		}

	}
		
  
}




void Image::convolution()
{
 
Filtre();
	int n=_height ,m=_width;
   
    int somme=0;
    
	int sommeRED=0;
	int sommeGREEN=0;
	int sommeBLUE=0;
	int sommeNb=0;

 
    
   
   for(int x=1;x<n-1;x++)
   	{
		
		   for(int y=1;y<m-1;y++)
   				{
				   for(int i=-1;i<2;i++)
   						{
						for(int j=-1;j<2;j++)
							{
   						

						if(PPM==1 && PGM==0)
							{
   							
							sommeRED=sommeRED+_MatriceImgRED[x+i][y+j]*_Filtre[i+1][j+1];
							sommeGREEN=sommeGREEN+_MatriceImgGREEN[x+i][y+j]*_Filtre[i+1][j+1];
							sommeBLUE=sommeBLUE+_MatriceImgBLUE[x+i][y+j]*_Filtre[i+1][j+1];
			

							sommeRED=round(sommeRED);
							sommeGREEN=round(sommeGREEN);	
							sommeBLUE=round(sommeBLUE);

						




							}

						if(PGM==1 && PPM==0)
							{
							
							sommeNb=sommeNb+_MatriceImgNb[x+i][y+j]*_Filtre[i+1][j+1];
							sommeNb=round(sommeNb);
							
							
									


						
							
							
						   }
					
					
					
			    
				}	
							if(sommeRED<0 )
							sommeRED=0;
							else if (sommeRED> 255)
							{
							sommeRED=255;
														
							}
							else 
							sommeRED=sommeRED;

							if(sommeGREEN<0 )
							sommeGREEN=0;
							else if (sommeGREEN> 255)
							{
							sommeGREEN=255;
														
							}
							else 
							sommeGREEN=sommeGREEN;


							if(sommeBLUE<0 )
							sommeBLUE=0;
							else if (sommeBLUE> 255)
							{
							sommeBLUE=255;
														
							}
							else 
							sommeBLUE=sommeBLUE;
							
							if(sommeNb<0 )
							sommeNb=0;
							else if (sommeNb> 255)
							{
							sommeNb=255;
														
							}
							else 
							sommeNb=sommeNb;
							}


					
					_MatriceCovNB[x][y]=sommeNb;
					_MatriceCovRED[x][y]=sommeRED;
					_MatriceCovGREEN[x][y]=sommeGREEN;
					_MatriceCovBLUE[x][y]=sommeBLUE;			
					
					sommeRED=0;
					sommeGREEN=0;
					sommeBLUE=0;
			    
			}
		   
	}

	   
		   
}



		
void Image::afficher()
{


// initialisation des matrices pour chaques couleurs
ofstream monimage;
monimage.open ("../test/ImageEnCoursDeTraitement/monimage");


ofstream OPCV;
OPCV.open ("../test/ImageEnCoursDeTraitement/OPVC.txt");
ofstream MOI;
MOI.open ("../test/ImageEnCoursDeTraitement/MOI.txt");	

int v=0;
int b=0;
int a=0;
int j=0;
int h=0;

Mat imageTraiteeNB(_height,_width,CV_8UC3,0.0f);
Mat imageTraiteeRED(_height,_width,CV_8UC3,0.0f);
Mat imageTraiteeGREEN(_height,_width,CV_8UC3,0.0f);
Mat imageTraiteeBLUE(_height,_width,CV_8UC3,0.0f);

Mat imageOriginaleNB(_height,_width,CV_8UC3,0.0f);
Mat imageOriginaleRED(_height,_width,CV_8UC3,0.0f);
Mat imageOriginaleGREEN(_height,_width,CV_8UC3,0.0f);
Mat imageOriginaleBLUE(_height,_width,CV_8UC3,0.0f);

if(PGM==1 && PPM==0)
{
ofstream ImageTraiteeNB;
ImageTraiteeNB.open ("../test/ImageEnCoursDeTraitement/ImageTraiteeNB.pgm");

ImageTraiteeNB << "P2" << "\n";
ImageTraiteeNB << _width << " " << _height <<"\n";
ImageTraiteeNB << 255 << "\n";	

for(h=0; h<_height ; h++ )
	{
	for(j=0; j<_width ;j++ )	
		{			
		ImageTraiteeNB << _MatriceCovNB[h][j] << " ";	

		if (j == _width)	
		{

		ImageTraiteeNB << "\n";
		
		}
		}	
	}

ImageTraiteeNB.close();
}
if(PGM==0 && PPM==1)
{

ofstream ImageTraiteeRED;
ImageTraiteeRED.open ("../test/ImageEnCoursDeTraitement/ImageTraiteeRED.pgm");	
ofstream ImageTraiteeGREEN;
ImageTraiteeGREEN.open ("../test/ImageEnCoursDeTraitement/ImageTraiteeGREEN.pgm");	
ofstream ImageTraiteeBLUE;
ImageTraiteeBLUE.open ("../test/ImageEnCoursDeTraitement/ImageTraiteeBLUE.pgm");
ImageTraiteeRED << "P2" << "\n";
ImageTraiteeRED << _width << " " << _height <<"\n";
ImageTraiteeRED << 255 << "\n";
ImageTraiteeGREEN << "P2" << "\n";
ImageTraiteeGREEN << _width << " " << _height <<"\n";
ImageTraiteeGREEN << 255 << "\n";
ImageTraiteeBLUE << "P2" << "\n";
ImageTraiteeBLUE << _width << " " << _height <<"\n";
ImageTraiteeBLUE << 255 << "\n";
	
for(h=0; h<_height ; h++ )
	{
	for(j=0; j<_width ;j++ )	
		{			
		ImageTraiteeRED << _MatriceCovRED[h][j] << " ";	
		ImageTraiteeGREEN << _MatriceCovGREEN[h][j] << " ";
		ImageTraiteeBLUE << _MatriceCovBLUE[h][j] << " ";		
		

		if (j == _width)	
		{

		ImageTraiteeRED << "\n";
		ImageTraiteeGREEN << "\n";
		ImageTraiteeBLUE << "\n";
		}
		}	
	}
ImageTraiteeRED.close();
ImageTraiteeGREEN.close();
ImageTraiteeBLUE.close();

}	


		for (v=0; v<_height ; v++ )	
			{
			for(b=0; b< _width*3; b++ )
				{
					

					

					if(PGM==1 && PPM==0)
					{
					imageTraiteeNB.at<uchar>(v,b)=_MatriceCovNB[v][a];
					imageTraiteeNB.at<uchar>(v,b+1)=_MatriceCovNB[v][a];
					imageTraiteeNB.at<uchar>(v,b+2)=_MatriceCovNB[v][a];
					
					imageOriginaleNB.at<uchar>(v,b)=_MatriceImgNb[v][a];
					imageOriginaleNB.at<uchar>(v,b+1)=_MatriceImgNb[v][a];
					imageOriginaleNB.at<uchar>(v,b+2)=_MatriceImgNb[v][a];
						

					if(a<_width-1)
					a=a+1;
					else
					{
					a=0;
					}
					b=b+2;
					}
				
					




					if(PPM==1 && PGM==0)
					{


					imageTraiteeRED.at<uchar>(v,b)=_MatriceCovRED[v][a];
					imageTraiteeRED.at<uchar>(v,b+1)=_MatriceCovRED[v][a];
					imageTraiteeRED.at<uchar>(v,b+2)=_MatriceCovRED[v][a];
					
					
					imageTraiteeGREEN.at<uchar>(v,b)=_MatriceCovGREEN[v][a];
					imageTraiteeGREEN.at<uchar>(v,b+1)=_MatriceCovGREEN[v][a];
					imageTraiteeGREEN.at<uchar>(v,b+2)=_MatriceCovGREEN[v][a];
					
					
					imageTraiteeBLUE.at<uchar>(v,b)=_MatriceCovBLUE[v][a];
					imageTraiteeBLUE.at<uchar>(v,b+1)=_MatriceCovBLUE[v][a];
					imageTraiteeBLUE.at<uchar>(v,b+2)=_MatriceCovBLUE[v][a];
					
					


					imageOriginaleRED.at<uchar>(v,b)=_MatriceImgRED[v][a];
					imageOriginaleRED.at<uchar>(v,b+1)=_MatriceImgRED[v][a];
					imageOriginaleRED.at<uchar>(v,b+2)=_MatriceImgRED[v][a];

					imageOriginaleGREEN.at<uchar>(v,b)=_MatriceImgGREEN[v][a];
					imageOriginaleGREEN.at<uchar>(v,b+1)=_MatriceImgGREEN[v][a];
					imageOriginaleGREEN.at<uchar>(v,b+2)=_MatriceImgGREEN[v][a];

					imageOriginaleBLUE.at<uchar>(v,b)=_MatriceImgBLUE[v][a];
					imageOriginaleBLUE.at<uchar>(v,b+1)=_MatriceImgBLUE[v][a];
					imageOriginaleBLUE.at<uchar>(v,b+2)=_MatriceImgBLUE[v][a];
					

					if(a<_width-1)
					a=a+1;
					else
					{
					a=0;
					
					}

					b=b+2;



					}						

					

		}	

	}


		if(PGM==1 && PPM==0)
		{
		namedWindow( "image traitee NOIRE ET BLANC");   
		imshow( "image traitee NOIRE ET BLANC", imageTraiteeNB);
		waitKey(0);
		destroyAllWindows();  
		namedWindow( "image originale NOIRE ET BLANC");   
		imshow( "image originale NOIRE ET BLANC", imageOriginaleNB);     

		waitKey(0);
		destroyAllWindows();   
		}             
		

		if(PPM==1 && PGM==0)
		{
			
		namedWindow( "image traitee ROUGE");   
		imshow( "image traitee ROUGE", imageTraiteeRED); 
		waitKey(0);
		destroyAllWindows(); 
		namedWindow( "image originale ROUGE");   
		imshow( "image originale ROUGE", imageOriginaleRED);
		waitKey(0);
		destroyAllWindows();

		namedWindow( "image traitee VERTE");   
		imshow( "image traitee VERTE", imageTraiteeGREEN); 
		waitKey(0);
		destroyAllWindows(); 
		namedWindow( "image originale VERTE");   
		imshow( "image originale VERTE", imageOriginaleGREEN);
		waitKey(0);
		destroyAllWindows();

		namedWindow( "image traitee BLEU");   
		imshow( "image traitee BLEU", imageTraiteeBLUE); 
		waitKey(0);
		destroyAllWindows(); 
		namedWindow( "image originale BLEU");   
		imshow( "image originale BLEU", imageOriginaleBLUE); 
		waitKey(0);
		destroyAllWindows();

                		

		}
}
		






