

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<vector>


using namespace std;

class Bibliotheque
{		
	private:
		int _numero;
		string _titre;
		int _cout;
	public:
		
		//les constructeurs
		Bibliotheque();
		Bibliotheque(int numero, string titre, int cout);
		
		//les accesseurs
		
		int GetNumero() const;
		string GetTitre() const;
   		int GetCout() const;
   		
   		// les fonctions a implémenter 
   		
   		void ajout(vector<Bibliotheque>&);
		void affichage(const vector<Bibliotheque>&);
		void recherche(const vector<Bibliotheque>&);
		void suppression(vector<Bibliotheque>&);
		void sauvegarde(vector<Bibliotheque>&);
		
		
};

   		
			 
		

