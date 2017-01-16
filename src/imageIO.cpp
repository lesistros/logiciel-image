#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>


using namespace std;


//string path;


void openPGM (string path)
{


/// modif 1 FORMAT PGM
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
		sscanf(line.c_str(),"%i %i",&width,&height);

		//read max value
		getline(myfile , line);
		
		maxColor = atoi ( line.c_str());


		
		cout << "Type du fichier : " << filetype << "\n";
		cout << "Taille : " << width << " x " << height << "\n";
		cout << "Max scale : " << maxColor << "\n\n\n";
		   
		nbrBytes = width * height;

			


		


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
			
			cout << "pixel numero = " << compteur<< endl; 
			cout << "colonne : " << compteur_col << " ligne : " << compteur_lign << endl;
			cout << "valeur du pixel : " << 256+pixel << "\n";
			nbrBytes--;
			compteur ++;
			compteur_col ++;
			if(compteur_col == 513)
				{
				compteur_col = 1;
				compteur_lign = compteur_lign + 1;

				}	
			}
			else
			{
			//cout << "byte : " << int(byte) << endl;

			cout << "pixel numero = " << compteur<< endl;
			cout << "colonne : " << compteur_col << " ligne : " << compteur_lign << endl;
			cout << "valeur du pixel : " << pixel << "\n";
			
			nbrBytes--;
			compteur ++;
			compteur_col ++;

			if(compteur_col == 513)
				{
				compteur_col = 1;
				compteur_lign = compteur_lign + 1;

				}
			
			}
				
		}

		
		myfile.close();

	}
	
	else cout << "pas possible d ouvrir l image";
	
	/*
	// modif 2
	ifstream myfile2("../test/sample/lena.pgm", ios::binary);

	int lign=0,col=0,nb_lign=0,nb_col=0,bits;
	stringstream ss;
	string inputline = "";
	
	getline(myfile2,inputline);

	
	
	cout << "\n\n\n\nversion du pmg :" << inputline << endl;
	
	
	
	ss << myfile2.rdbuf();
	ss >> nb_col >> nb_lign;
	cout << nb_col << " colones et " << nb_lign << " lignes" << endl;

	int max_val;
	ss >> max_val;
	cout << "maximum de niveau de gris" << max_val;
	
	unsigned char pix;
	unsigned int pix_val[nb_lign][nb_col];
	unsigned int integral[nb_lign][nb_col];
	
	for (lign=0; lign< nb_lign; lign++)
		{
			for(col=0; col<nb_col ; col++)
			{
				ss >> pix;
				pix_val[lign][col]=pix;


			}	
		cout << endl;
		}



	*/



}




