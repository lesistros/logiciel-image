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
  int Image::getWidth()const
	{
		return _width;
	}
  int Image::getHeight()const
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
	int width = 0;
	int height= 0;
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


		
		cout << "Type du fichier : " << filetype << "\n";
		cout << "Taille : " << _width << " x " << _height << "\n";
		cout << "Max scale : " << maxColor << "\n\n\n";
		   
		nbrBytes = _width * _height;

		//nbrBytes = 20;
		int compteur=1;
		unsigned int compteur_col=1;
		 unsigned int compteur_lign=1;
		
		while (nbrBytes != 0 )
		{
			myfile.get(byte);
			pixel = byte;
			if(byte<0)
			{
			
			//cout << "byte : " << int(byte) << endl;
			
			//cout << "pixel numero = " << compteur<< endl; 
			//cout << "colonne : " << compteur_col << " ligne : " << compteur_lign << endl;
			cout << "valeur du pixel : " << 256+pixel << "\n";
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
			//cout << "byte : " << int(byte) << endl;

			//cout << "pixel numero = " << compteur<< endl;
			//cout << "colonne : " << compteur_col << " ligne : " << compteur_lign << endl;
                        ofstream fichier("test.txt", ios::in);

			for (int i=0;i<_width;i++)
				 
				{for(int j=0;j<_height;j++)
					
						fichier<<pixel;
				}





			cout << "valeur du pixel : " << pixel << "\n";
			
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
	

}	

			



