
#include"Bibliotheque.h"
#include<fstream>
#include<sstream>


using namespace std;


//définition des constructeurs

	Bibliotheque::Bibliotheque()
	{
	}
	
	Bibliotheque::Bibliotheque(int numero, string titre, int cout)
	{
			_numero=numero;
			_titre=titre;
			_cout=cout;
	}	
	
// les accesseurs

	int Bibliotheque::GetNumero() const
	{	
		return _numero;
	}
	string Bibliotheque::GetTitre() const
	{
		return _titre;
	}
	int Bibliotheque::GetCout() const
	{
		return _cout;
	}
   		

//les fonctions implémentées
	

   	void Bibliotheque::ajout(vector<Bibliotheque>&_liste)
   	{
   		cout<< "\t----- AJOUT D'UNE image -----\t\n\n" ;
   		cout<<"numero....:";
        cin>>_numero;
   		cout<< "Nom..... : " ; //saisie de l'image
		cin>>_titre;
		cout<<"cout.....:";
		cin>>_cout;
		_liste.push_back(Bibliotheque(_numero, _titre, _cout));
    }
	
	void Bibliotheque::affichage(const vector<Bibliotheque>&_liste)
	{
	cout<< "\t----- LISTE DES IMAGES -----\t\n\n\n" ;
		for (int it =0 ; it < _liste.size(); it++)
		 {
		 cout<<" Image numero : " <<_liste[it].GetNumero()<<endl;
     	 cout<< "titre : " <<_liste[it].GetTitre()<<endl;
      	 cout<< "cout : " <<_liste[it].GetCout()<<endl;
  		 }
   cout<< "----- Fin liste. -----" <<endl;
	}
	
	void Bibliotheque::recherche(const vector<Bibliotheque>&_liste)
{
   cout<< "\t----- RECHERCHE D UNE IMAGE -----\t\n\n" ;
   cout<< "Numero de la l image recherchée : " ;
   int numero;
   cin>>numero;
    for (int it = 0; it<_liste.size(); it++) //parcours de la liste
      if (_liste[it].GetNumero() == numero) {
         cout<< "\n" <<numero<< "\t" <<_liste[it].GetTitre()<< "\t" <<_liste[it].GetCout();
         break;
      }
   cout<< "\n\n----- Fin recherche. -----\n" ;
}



	void Bibliotheque::suppression(vector<Bibliotheque>&_liste)
	{
	
	cout<< "\t----- SUPPRESSION D'UNE Image -----\t\n\n" ;
   cout<< "\n numero de l image  à supprimer : " ;
   int numero;
   cin>>numero;
   bool suppression = false;
   for (int it = 0; it<_liste.size(); it++)
      if ( _liste[it].GetNumero() == numero ) 
	  {
         _liste.pop_back();
         suppression = true;
         cout<< "\n----- Image supprimée. -----\n" ;
         break;
      }
   if (!suppression)
      cout<< "\n----- Image inconnue. -----\n" ;
	
	}
	
	void Bibliotheque::sauvegarde(vector<Bibliotheque>&_liste)
	{ string path;
	//	ifstream mon_fichier(path, ios::binary);
		ofstream liste_Image;
    	liste_Image.open ("/home/lesistros/Documents/logiciel-image/test/sample/ImageEnCoursDeTraitement/Ma_liste.txt");
    	for (int it = 0; it<_liste.size(); it++)
		{
		liste_Image<<_liste[it].GetNumero()<<endl;
		liste_Image<<_liste[it].GetTitre()<<endl;
		liste_Image<<_liste[it].GetCout()<<endl;}
		
	}
