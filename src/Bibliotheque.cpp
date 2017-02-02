
#include"Bibliotheque.h"
#include<fstream>
#include<sstream>
#include<algorithm>
#include<string>

using namespace std;


//d�finition des constructeurs

	Bibliotheque::Bibliotheque()
	{
	}

	Bibliotheque::Bibliotheque(int numero, string titre, float Cout,string chemin, char droit)
	{
			_numero=numero;
			_titre=titre;
			_cout=Cout;
			_chemin=chemin;
			_droit=droit;
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
	string Bibliotheque::GetChemin() const
	{
		return _chemin;
	}
	char Bibliotheque::GetDroit() const
	{
		return _droit;
	}
// les modificateurs
	void Bibliotheque::SetNumero(int numero)
	{
		 _numero=numero;
	}
	void Bibliotheque::SetTitre(string titre)
	{
		_titre=titre;
	}
	void Bibliotheque::SetCout(float Cout)
	{
		 _cout=Cout;
	}
	void Bibliotheque::SetChemin(string chemin)
	{
		 _chemin=chemin;
	}
	void Bibliotheque::SetDroit(char droit)
	{
		 _droit=droit;
	}

//les fonctions impl�ment�es
//************************** Ajout d'une image*************************


   	void Bibliotheque::ajout(vector<Bibliotheque>&_liste)
   	{
   		cout<< "\t----- AJOUT D'UNE image -----\t\n\n" ;
   		cout<<"numero....:";//saisie du numero
        cin>>_numero;
   		cout<< "titre..... : " ; //saisie du titre
		cin>>_titre;
		cout<<"cout.....:";
		cin>>_cout;
		cout<<"chemin.....:";
		cin>>_chemin;
		cout<<"droit d'acces L:Libre R:Restreint .....:";
		cin>>_droit;

		_liste.push_back(Bibliotheque(_numero, _titre, _cout,_chemin,_droit));// ajout a la liste des images


    }
    //**************** Affichage & affichage limit�**********************

	void Bibliotheque::affichage(const vector<Bibliotheque>&_liste)
	{
	cout<< "\t----- LISTE DES IMAGES -----\t\n\n\n" ;
	cout<<" \tNumero \t Titre \t Cout\n";
		for (unsigned int it =0 ; it < _liste.size(); it++)
		 {
		 cout<<" \t" <<_liste[it].GetNumero()<<" \t" <<_liste[it].GetTitre()<< " \t" <<_liste[it].GetCout()<<endl;
  		 }
   cout<< "----- Fin liste. -----" <<endl;
	}
	void Bibliotheque::affichage_limite(const vector<Bibliotheque>&_liste,vector<Bibliotheque>&_sousliste)//affiche les images qui ont acc�s libre
	{
	 cout<< "\t----- LISTE DES IMAGES -----\t\n\n\n" ;
     cout<<" \tNumero \t Titre \t Cout\n";
		for (unsigned int it =0 ; it < _liste.size(); it++)
		  if(_liste[it].GetDroit()=='L')
		 _sousliste.push_back(_liste[it]);
		 for (unsigned int i =0 ;i < _sousliste.size(); i++)
		 cout<<" \t" <<i+1<<" \t" <<_sousliste[i].GetTitre()<< " \t" <<_sousliste[i].GetCout()<<endl;

  	cout<< "\n\t----- Fin liste. -----" <<endl;
	}




	//                  *********************** RECHERCHE D'IMAGES *********************

   //      ***choix du crit�re de recherche****
	//                   ***** par titre ******

void Bibliotheque::recherche(const vector<Bibliotheque>&_liste, vector<Bibliotheque>&_sousliste)
{	Bibliotheque Im;
	cout<< "\t voulez vous faire une recherche par:\n                \t  A-Titre\n                \t  B-Cout\n                \t";
	char R;
	cin>>R;
	if (R=='a')
	{
    cout<< "\n\t titre de la l image recherchee :\n " ;

    char titre[20];
    cin>>titre;

    for (unsigned int it = 0; it<_liste.size(); it++) //parcours de la liste
       if(titre==_liste[it].GetTitre())
        _sousliste.push_back(_liste[it]);
    sort(_sousliste.begin(),_sousliste.end());cout<<endl;
    for(unsigned int it = 0; it<_sousliste.size(); it++)
		cout<< "\n" <<_sousliste[it].GetNumero()<< "\t" <<_sousliste[it].GetTitre()<< "\t" <<_sousliste[it].GetCout()<<endl;
		_sousliste.clear();			//vider la sous liste

	}
	//              ********** par co�t*********

    if (R=='b') {
   cout<< "\n\t----- RECHERCHE D UNE IMAGE -----\t\n\n" ;
   cout<<"\t A- Gratuit\n  \t B-cout <9,99 Euros \n  \t C- 10 Euros < cout < 99.99 Euros\n \t D-cout>100 Euros\n \t E- choisir votre intervalle \n"<<endl;
   cout<< "\n\tcout de la l image recherch�e :\n " ;

   char Cout[1];
   cin>>Cout;
   // 1 er cas
   if (Cout[1]=='a')
    {for (unsigned int it = 0; it<_liste.size(); it++) //parcours de la liste
      if (_liste[it].GetCout() == 0)
    _sousliste.push_back(_liste[it]);// chargement dela sous liste si la condition est verifi�e.
    sort(_sousliste.begin(),_sousliste.end());cout<<endl; // trie de la sous liste
    for(unsigned int it = 0; it<_sousliste.size(); it++)// affichage de la sous liste tri�e
		cout<< "\n" <<_sousliste[it].GetNumero()<< "\t" <<_sousliste[it].GetTitre()<< "\t" <<_sousliste[it].GetCout()<<endl;

   _sousliste.clear();
	}
    //****** 2eme cas


	if(Cout[0]=='b')
    {
	for (unsigned int it = 0; it<_liste.size(); it++)
		if (_liste[it].GetCout()<=9.99)
       _sousliste.push_back(_liste[it]); // chargement de la sous liste
	    sort(_sousliste.begin(),_sousliste.end());cout<<endl;// trie de la sous liste
    for(unsigned int it = 0; it<_sousliste.size(); it++) //affichage de la sous liste trie�
		cout<< "\n" <<_sousliste[it].GetNumero()<< "\t" <<_sousliste[it].GetTitre()<< "\t" <<_sousliste[it].GetCout()<<endl;
	 _sousliste.clear();
	}
	///***** 3eme cas
	if(Cout[0]=='c')
    {
	for (unsigned int it = 0; it<_liste.size(); it++)
    if (_liste[it].GetCout()<=99.99 && _liste[it].GetCout()>=10 )
		_sousliste.push_back(_liste[it]);
    sort(_sousliste.begin(),_sousliste.end());cout<<endl;
    for(unsigned int it = 0; it<_sousliste.size(); it++)

	cout<< "\n" <<_sousliste[it].GetNumero()<< "\t" <<_sousliste[it].GetTitre()<< "\t" <<_sousliste[it].GetCout()<<endl;
	_sousliste.clear();
	}


	//***** 4eme cas
    if(Cout[0]=='d')
   {
	 for (unsigned int it = 0; it<_liste.size(); it++)
    if (_liste[it].GetCout()>=100)
		_sousliste.push_back(_liste[it]);
   sort(_sousliste.begin(),_sousliste.end());cout<<endl;
    for(unsigned int it = 0; it<_sousliste.size(); it++)
   	cout<< "\n" <<_sousliste[it].GetNumero()<< "\t" <<_sousliste[it].GetTitre()<< "\t" <<_sousliste[it].GetCout()<<endl;
	_sousliste.clear();
	}

    //***** 5eme cas
	if(Cout[0]=='e')
   	{
		cout<<"donner votre interval\n min: \t"<<endl;

		float min, max;
		cin>>min;
		cout<<" max"<<endl;
		cin>>max;
		for (unsigned int it = 0; it<_liste.size(); it++)
		if (_liste[it].GetCout()>=min && _liste[it].GetCout()<=max )
		_sousliste.push_back(_liste[it]);

	sort(_sousliste.begin(),_sousliste.end());cout<<endl;
	for(unsigned int it = 0; it<_sousliste.size(); it++)
		cout<< "\n" <<_sousliste[it].GetNumero()<< "\t" <<_sousliste[it].GetTitre()<< "\t" <<_sousliste[it].GetCout()<<endl;
		_sousliste.clear();
}
   cout<< "\n\n----- Fin recherche. -----\n" ;
}
}

 // ****** MODIFICATION D'UNE CARACTERISTIQUE DE L'IMAGE********

void Bibliotheque::modification(vector<Bibliotheque>&_liste)
{   char critere;
	int numero;
	cout<<"donnez le numero de l'image que vous souhaitez modifier:\t";
	cin>>numero;
	cout<<" voulez vous modifier quel crit�re?\n\t\t a-titre\n\t\t b-cout\n\t\t c-droits d acces \n\t\t d-chemin\n";
	cin>>critere;
	 if(critere=='a')
	 {
	 string titre;
	 cout<<"nouveau titre:\n";cin>>titre;_liste[numero-1].SetTitre(titre);}

	if(critere=='b')
	 {
	 float Cout;
	 cout<<"nouveau Cout:\n";cin>>Cout;_liste[numero-1].SetCout(Cout);}

	if(critere=='c')
	 {
	 char droit;
	 cout<<"entrez  L pour libre  R pour Retrient :\n";cin>>droit;_liste[numero-1].SetDroit(droit);}
	 if(critere=='d')
	 {
	 string chemin;
	 cout<<"nouveau chemin:\n";cin>>chemin;_liste[numero-1].SetChemin(chemin);}


}
//************** Suppression d'une image*****************

	void Bibliotheque::suppression(vector<Bibliotheque>&_liste)
	{

	cout<< "\t----- SUPPRESSION D'UNE Image -----\t\n\n" ;
   cout<< "\n numero de l image  � supprimer : " ;
   int numero;

   cin>>numero;

   bool suppression = false;
   for (unsigned int it = 0; it<_liste.size(); it++)
      if ( _liste[it].GetNumero() == numero )
	  {
	  	  _liste.erase (_liste.begin()+it);   //suppression de l'image
         suppression = true;
         for(unsigned int i=it;i<_liste.size();i++)   // r�arangement des num�ros des images suivantes
         {	_liste[i].SetNumero(i+1);}
         cout<< "\n----- Image supprim�e. -----\n" ;
         break;
      }
   if (!suppression)
      cout<< "\n----- Image inconnue. -----\n" ;

	}

	// ******************sauvegarde de la liste dan un fichier*****************

	void Bibliotheque::sauvegarde(vector<Bibliotheque>&_liste)
	{ string path;
	//	ifstream mon_fichier(path, ios::binary);
		ofstream liste_Image;
    	liste_Image.open ("/home/lesistros/Documents/logiciel-image/src/Ma_liste.txt"); // ouverture du fichier en ecriture
    	liste_Image<<"\t Num�ro \t Titre \t Cout \t Chemin \t Droit d'acc�s\n";
		for (unsigned int it = 0; it<_liste.size(); it++)   // remplissage du fichier
		{
		liste_Image<<" \t "<<_liste[it].GetNumero()<<" \t \t";
		liste_Image<<_liste[it].GetTitre()<<" \t ";
		liste_Image<<_liste[it].GetCout()<<" \t ";
		liste_Image<<_liste[it].GetChemin()<<" \t \t ";
		liste_Image<<_liste[it].GetDroit()<<endl;
		}

	}
	//**************trie de la liste*******************

	bool Bibliotheque::operator<(const Bibliotheque & I) const
{
	return ( _cout<I._cout);
}

	bool Bibliotheque::operator>(const Bibliotheque & I1) const
{
	return ( _titre>I1._titre );
}

struct trie_titre
{
   bool operator ()(const Bibliotheque & a1,const Bibliotheque & a2) const
   {
      return a1.GetTitre() < a2.GetTitre();
   }
};

// trie par cout
void Bibliotheque::trie_par_cout(const vector<Bibliotheque>& _liste, vector<Bibliotheque>&_sousliste)
{
	for (unsigned int it = 0; it<_liste.size(); it++)
	_sousliste.push_back(_liste[it]);
	sort(_sousliste.begin(),_sousliste.end());
	for (unsigned int it = 0; it<_sousliste.size(); it++)
		cout<< "\n" <<_sousliste[it].GetNumero()<< "\t" <<_sousliste[it].GetTitre()<< "\t" <<_sousliste[it].GetCout();
		_sousliste.clear();

}

void Bibliotheque::trie_par_titre(const vector<Bibliotheque>& _liste, vector<Bibliotheque>&_sousliste)
{
	for (unsigned int it = 0; it<_liste.size(); it++)

	_sousliste.push_back(_liste[it]);
	sort(_sousliste.begin(),_sousliste.end(),trie_titre());

	for (unsigned int it = 0; it<_sousliste.size(); it++)
		cout<< "\n" <<_sousliste[it].GetNumero()<< "\t" <<_sousliste[it].GetTitre()<< "\t" <<_sousliste[it].GetCout();
    _sousliste.clear();
}


void Bibliotheque::trie( vector<Bibliotheque>&_liste,vector<Bibliotheque>&_sousliste)
{



	Bibliotheque Im;
	int choix;
	cout<<"trier selon quel crit�re 1 Titre  2 Co�t\n";
	cin>>choix;
	switch(choix){
		case 1: Im.trie_par_titre(_liste,_sousliste);break;
		case 2: Im.trie_par_cout(_liste,_sousliste);break;
		default:cout<<"erreur"; break;

	}

 }

 //************************ Identification et appel des differentes fonctions**************


	void Bibliotheque::identification(vector<Bibliotheque>& liste)
	{	Bibliotheque Im;
		//vector<Bibliotheque> liste;
		vector<Bibliotheque> sousliste;
		// contenu de la liste
			liste.push_back(Bibliotheque( 6 , "lena" ,46, "/home/lesistros/Documents/logiciel-image/test/sample/lena.pgm" ,'L'));cout<<endl;
    		liste.push_back(Bibliotheque( 2 , "house" ,244, "/home/lesistros/Documents/logiciel-image/test/sample/house_1.ppm" ,'R')); cout<<endl;
    		liste.push_back(Bibliotheque( 3 , "west" ,446, "/home/lesistros/Documents/logiciel-image/test/sample/west_1.ppm" ,'L'));cout<<endl;
        liste.push_back(Bibliotheque( 4 , "tree" ,24, "/home/lesistros/Documents/logiciel-image/test/sample/tree_1.ppm" ,'R')); cout<<endl;
        liste.push_back(Bibliotheque( 5 , "stop" ,460, "/home/lesistros/Documents/logiciel-image/test/sample/stop_1.ppm",'L'));cout<<endl;






		int choix;

		char identifiant[4], mdp[20];
		cout<<" \tveuillez vous identifier_\n \t identifiant : ";
	cin>>identifiant;
	cout<<"\n \t mot de passe : ";
	cin>>mdp;

		cout<<"\n\tvous etes connecte\n"<<endl;
		 if(identifiant[4]=='0')
		 {
   do {
      cout<< "\n\t----- Bonjour -----" <<endl;
      cout<< "\t 1 - Ajout" <<endl;
      cout<< "\t 2 - Affichage" <<endl;
      cout<< "\t 3 - Recherche" <<endl;
      cout<< "\t 4 - Modification" <<endl;
      cout<< "\t 5 - Trie" <<endl;
      cout<< "\t 6 - Suppression" <<endl;
      cout<< "\t 7 - Sauvegarde" <<endl;
      cout<< "\t 8 - Sortie" <<endl;
      cout<< "\n  veuillez choisir une action (1 � 8) : " ;
      cin>>choix; //lecture du choix de l'utilisateur
      switch(choix)
		{

		case 1:	Im.ajout(liste);break;
		case 2:	Im.affichage(liste);break;
		case 3:	Im.recherche(liste,sousliste);break;
		case 4:	Im.modification(liste);break;
		case 5:	Im.trie(liste,sousliste);break;
		case 6:	Im.suppression(liste);break;
		case 7:	Im.sauvegarde(liste);break;
  //  case 8: Im.LireImg(liste.getChemin())
		case 8: cout<<"sortir du programme";break;
		default:cout<<"erreur;r";break;
		}
	}		while (choix!=8);
		 }
		  if(identifiant[4]=='1')
		  {

		  cout<<"\t niveau 1\n"<<endl;
		  do {
      cout<< "\n\t----- Bonjour -----" <<endl;
      cout<< "\t 1 - Affichage" <<endl;
      cout<< "\t 2 - Sortie" <<endl;
      cout<< "\n  veuillez choisir une action (1 ou 2) : " ;
      cin>>choix; //lecture du choix de l'utilisateur
      switch(choix)
		{

		case 1:	Im.affichage_limite(liste,sousliste);break;
		case 2: cout<<"sortir du programme";break;
		default:cout<<"erreur;r";break;
		}
	}		while (choix!=2);
			}
	else{

	cout<<"/t--------bonjour------";
	 cout<< "\n  appuiez sur 1 pour sortir: " ;
      cin>>choix;
		  	switch(choix)
		{

		case 1: cout<<"sortir du programme";break;
		default:cout<<"erreur";break;
		}


		}
	}

string  Bibliotheque::choisir(vector<Bibliotheque>& liste)
{
    int numero;
    cout<<"\n\n\n\n donnez le numero de l image que vous souhaitez traiter\n\n\n " << endl;
    cin >> numero;

    return liste[numero-1].GetChemin();




}

void Bibliotheque::DefinirListe(vector<Bibliotheque>& liste)
{
  liste.push_back(Bibliotheque( 1 , "lena" ,46, "/home/lesistros/Documents/logiciel-image/test/sample/lena.pgm" ,'L'));cout<<endl;
  liste.push_back(Bibliotheque( 2 , "house" ,244, "/home/lesistros/Documents/logiciel-image/test/sample/house_1.ppm" ,'R')); cout<<endl;
  liste.push_back(Bibliotheque( 3 , "west" ,446, "/home/lesistros/Documents/logiciel-image/test/sample/west_1.ppm" ,'L'));cout<<endl;
  liste.push_back(Bibliotheque( 4 , "tree" ,24, "/home/lesistros/Documents/logiciel-image/test/sample/tree_1.ppm" ,'R')); cout<<endl;
  liste.push_back(Bibliotheque( 5 , "stop" ,460, "/home/lesistros/Documents/logiciel-image/test/sample/stop_1.ppm",'L'));cout<<endl;






}
