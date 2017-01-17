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
		/*
		cout << "Type du fichier : " << filetype << "\n";
		cout << "Taille : " << width << " x " << height << " x 3 "<<"\n";
		cout << "Max scale : " << maxColor << "\n\n\n";
		*/

// remise sour la forme des formats PGM pour afficher (pas obligatoire)

	RED <<	"P2" << "\n"; //p2 pour le noir et blanc pour afficher avec open cv
	RED <<	width << " " << height <<"\n";
	RED <<	maxColor << "\n";

	GREEN << "P2" << "\n";
	GREEN << width << " " << height <<"\n";
	GREEN << maxColor << "\n";

	BLUE << "P2" << "\n";
	BLUE << width << " " << height <<"\n";
	BLUE << maxColor << "\n";

	nbBytes = width * height * 3;
	
	// creation d une matrice pour un futur traitement

	int MatriceImg[height-1][width-1][3];
	
	

	





	int HistRED[255];
	int HistGREEN[255];
	int HistBLUE[255];

	int l=0;
// TEST

for(l=0; l<255; l++)
{
	HistRED[l] = 0;
	HistGREEN[l] =0;
	HistBLUE[l] =0;
	
}
	

    
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

				// TEST Histogramme
				HistRED[pixel+256]=HistRED[pixel+256]+1;


				//HIST.at<float>(0,pixel+256) = HIST.at<float>(0,pixel+256) +1;

				}
			else if(compteur == 2 )
				{

				GREEN << pixel+256 << " ";
				MatriceImg[i][j][2] << pixel+256;
				i++;
				compteur++;
				HistGREEN[pixel+256]=HistGREEN[pixel+256]+1;


				}
			else
				{

				BLUE << pixel+256 << " ";
				MatriceImg[i][j][3] << pixel+256;
				i++;
				compteur = 1;
				compteur_col ++;
				HistBLUE[pixel+256]=HistBLUE[pixel+256]+1;
				
				//cout << HistBLUE[pixel+256];


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
				HistRED[pixel]=HistRED[pixel]+1;

				//HIST.at<float>(0,pixel) = HIST.at<float>(0,pixel) +1;


				}
			else if(compteur == 2 )
				{
				
				MatriceImg[i][j][2] << pixel;
				GREEN << pixel  << " ";
				i++;
				compteur++;
				HistGREEN[pixel]=HistGREEN[pixel]+1;
				}
			else
				{
				
				MatriceImg[i][j][3] << pixel;
				BLUE << pixel  << " ";
				compteur = 1;
				compteur_col ++;
				i++;
				HistBLUE[pixel]=HistBLUE[pixel]+1;
				//cout << HistBLUE[pixel];

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
		cout << "ca bug pas avant "<< "\n";
		cout << "ca bug pas avant "<< "\n";
	
//HIST.at<float>(0,1) = 5000;
		
// affichage matrice histogramme
/*
HIST.at<float>(0,1) = 5000;
HIST.at<float>(120,80) = 120;
HIST.at<float>(1100,90) = 1100;
HIST.at<float>(1150,91) = 1150;
HIST.at<float>(1151,90) = 1100;
HIST.at<float>(1152,91) = 10150;
*/
//int A;		
 //A << max(Histogramme[]) ;

cout << "ca bug pas avant "<< "\n";
cout << "ca bug pas avant "<< "\n";

Mat HistR(256,256,CV_32FC1,0.0f);
Mat HistG(256,256,CV_32FC1,0.0f);
//Mat HistB(256,256,CV_32FC1,0.0f);
		
	
 


		int n = 0;	
		for (n=0; n<255; n++)
		{
			
			
			
			HistR.at<float>(256-HistRED[n]   ,n) = HistRED[n];
			HistG.at<float>(256-HistGREEN[n] ,n) = HistGREEN[n];
			//HistB.at<float>(256-HistBLUE[n]  ,n) = HistBLUE[n];
			/*			
			cout << "\n";

			cout << Histogramme[n] << " la ";
			cout << "\n";

			cout << n << " prout ";
			//Histogramme[n];
			*/
		}



		//cout << "\n" << HIST << endl;
		// Affichage avec openCV		

		myfile.close();
		Mat image;
		
		//Mat Hist=Histogramme;		

  		namedWindow( "HISTOGRAMME ROUGE",  WINDOW_AUTOSIZE  );    
		imshow( "HISTOGRAMME ROUGE ", HistR );
		waitKey(0);
		namedWindow( "HISTOGRAMME GREEN",  WINDOW_AUTOSIZE  );    
		imshow( "HISTOGRAMME GREEN ", HistG );
		waitKey(0);
		//namedWindow( "HISTOGRAMME BLUE", 1256 );    
		//imshow( "HISTOGRAMME BLUE ", HistB );
 		//waitKey(0);
    		


		//cout << histImg;
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
