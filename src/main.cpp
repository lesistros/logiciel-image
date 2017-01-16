#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include <sstream>

#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"


using namespace cv;
using namespace std;



int main( int argc, char** argv)
{	

	//format PPM
	
	string line;
	ifstream myfile("../test/sample/tree_1.ppm", ios::binary);
	
	int i =0;
	string filetype = "";
	int width = 0;
	int height= 0;
	int maxColor = 0;
	string temp;
	int nbBytes;
	char byte;
	int pixel;
	
	

	//initialisation couleurs

	ofstream RED;
	RED.open ("../test/ImageEnCoursDeTraitement/RED.pgm");
	ofstream GREEN;
	GREEN.open ("../test/ImageEnCoursDeTraitement/GREEN.pgm");
	ofstream BLUE;
	BLUE.open ("../test/ImageEnCoursDeTraitement/BLUE.pgm");
		
	if(myfile.is_open())
	{	

		// Lecture entete
		// lecture du type de fichier P5 ou P6
		getline (myfile,line);
		filetype = line;
	
		//lecture des dimensions de l'image;
		getline (myfile,line);
		sscanf(line.c_str(),"%i %i",&width,&height);

		//read max value
		getline(myfile , line);
		maxColor = atoi ( line.c_str());
		
		cout << "Type du fichier : " << filetype << "\n";
		cout << "Taille : " << width << " x " << height << " x 3 "<<"\n";
		cout << "Max scale : " << maxColor << "\n\n\n";


// remise sour la forme des formats PGM pour afficher (pas obligatoire)

	RED <<	"P2" << "\n";
	RED <<	width << " " << height <<"\n";
	RED <<	maxColor << "\n";

	GREEN << filetype << "\n";
	GREEN << width << " " << height <<"\n";
	GREEN << maxColor << "\n";

	BLUE << filetype << "\n";
	BLUE << width << " " << height <<"\n";
	BLUE << maxColor << "\n";

	nbBytes = width * height * 3;
	
	// creation d une matrice pour un futur traitement

	int MatriceImg[height-1][width-1][3];


    
    // Inserting the values into the test array
   
		//lecture pixels


		// a faire attention, isoler les couleurs (R G B)

		int i=0;
		int j=0;
		int compteur=1;
		unsigned int compteur_col=1;
		unsigned int compteur_lign=1;

		while (nbBytes != 0 )
		{	
			
			myfile.get(byte);
			pixel = byte;
			
			if(byte<0)
			{
			
			nbBytes--;
			
			if (compteur==1)
				{

  				RED << pixel+256 << " ";
				MatriceImg[i][j][1] << pixel+256;
				
				compteur++;
				//cout << MatriceImg[i][j][1];
				//cout << i<<" ";
				i++;

				}
			else if(compteur == 2 )
				{

				GREEN << pixel+256 << " ";
				MatriceImg[i][j][2] << pixel+256;
				i++;
				compteur++;

				}
			else
				{

				BLUE << pixel+256 << " ";
				MatriceImg[i][j][3] << pixel+256;
				i++;
				compteur = 1;
				compteur_col ++;

				}
			}
			else
			{
			
			nbBytes--;
		
			if (compteur==1)
				{
				
  				RED << pixel  << " ";
				MatriceImg[i][j][1] << pixel;
				//cout << i<<" ";
 				//cout << "colonne : "<< compteur_col << "\n"
				compteur++;
				i++;

				}
			else if(compteur == 2 )
				{
				MatriceImg[i][j][2] << pixel;
				GREEN << pixel  << " ";
				i++;
				compteur++;
				}
			else
				{
				MatriceImg[i][j][3] << pixel;
				BLUE << pixel  << " ";
				compteur = 1;
				compteur_col ++;
				i++;

				}
			}
			if(compteur_col == width+1)
				{

				RED << "\n";
				GREEN << "\n";
				BLUE << "\n";
				compteur_col = 1;
				i=0;
				//cout << j <<" ";
				j=j+1;
				
				}
		}

		
		myfile.close();
		Mat image;
		image = imread("../test/ImageEnCoursDeTraitement/RED.pgm");
		//cout << image;
		namedWindow( "Display window", WINDOW_AUTOSIZE );   // Create a window for display.
		imshow( "Display window", image );                    // Show our image inside it.    
		waitKey(0);
		destroyAllWindows();


		RED.close();
		GREEN.close();
		BLUE.close();

	}
	else cout << "pas possible d ouvrir l image";

	return 0;


}
