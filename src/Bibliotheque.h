

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
		float _cout;
		string _chemin;
		char _droit;
	public:

		//les constructeurs
		Bibliotheque();
		Bibliotheque(int numero, string titre, float Cout, string chemin, char droit );

		//les accesseurs

		int GetNumero() const;
		string GetTitre() const;
   		int GetCout() const;
   		string GetChemin() const;
   		char GetDroit() const;

   		//les modificateur

   		void SetNumero(int numero);
   		void SetTitre(string titre);
   		void SetCout(float Cout);
   		void SetChemin(string chemin);
   		void SetDroit(char droit);

   		// les fonctions a impl�menter

   		void ajout(vector<Bibliotheque>&);
		void affichage(const vector<Bibliotheque>&);
		void affichage_limite(const vector<Bibliotheque>&,vector<Bibliotheque>&);
		void recherche(const vector<Bibliotheque>&, vector<Bibliotheque>&);
		void modification(vector<Bibliotheque>&);
		void suppression(vector<Bibliotheque>&);
		void sauvegarde(vector<Bibliotheque>&);
	    bool operator<(const Bibliotheque & I) const;
	    bool operator>(const Bibliotheque & I) const;
	    void trie( vector<Bibliotheque>& _liste, vector<Bibliotheque>&_sousliste);
		void trie_par_cout(const vector<Bibliotheque>& _liste, vector<Bibliotheque>&_sousliste);
		void trie_par_titre(const vector<Bibliotheque>& _liste, vector<Bibliotheque>&_sousliste);
		void identification();


};
