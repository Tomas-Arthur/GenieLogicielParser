
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

    using namespace std;
    
    
  
    
void option (string s, string resume,string titre,string auteur,string reference,string nomFichier){
 if (s=="-t"){
 	ofstream fichier;
 	fichier.open("log.txt");
 	
 	 fichier << "Le nom du fichier d’origine " << nomFichier << endl;
 	
 	 fichier << "le titre : " << titre << endl;
                fichier << "les auteurs : " << auteur << endl;
                fichier << "le resume : " << resume << endl;
                fichier << "les references : " << reference << endl;
                fichier.close();
                cout << "fin du programme";
 
 
 
 
 
 }
 else if (s=="-x"){
 
 ofstream fichier;
 fichier.open("log.xml");
 fichier<< "<article>"<<endl;
	fichier <<" <preamble> Le nom du fichier "<<nomFichier<<" </preamble>"<<endl;
	fichier <<"<titre> "<< titre << " </titre>"<<endl;
	fichier <<"<auteur> La section auteurs et leur adresse"<< auteur<<" </auteur>"<<endl;
	fichier <<"<abstract> resume article" << resume<< "abstract>" <<endl;
	fichier <<"<biblio> Les references graphiques papier" <<reference<<"</biblio>" <<endl;
       fichier <<	"</article> " ;
 
 
 
 
 }
 }
     
 int parseur(string s){
 
        ifstream fichier("Boudin-Torres-2006.txt", ios::in);  // on ouvre le fichier en lecture

        if (fichier)  // si l'ouverture a réussi
        {
            
            string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
            string abstract("Abstract");
            string resume;
            string titre;
            string auteur;
            string reference;
            string nomFichier;
            int a = 0;
            
            nomFichier="Boudin-Torres-2006";
            getline(fichier, contenu);  // on met dans "contenu" la ligne
            /*while (contenu.find("Abstract") == string::npos && a < 1000)
            {
                auteur += contenu;
                a++;
                getline(fichier, contenu);
            }*/
            
            titre = contenu;
            getline(fichier, contenu);
            while (contenu.find("Abstract") == string::npos &&  a < 1000)
            {
                auteur += contenu;
                a++;
                getline(fichier, contenu);
            }
            if (contenu.find("Abstract") != string::npos) {
                getline(fichier, contenu);
                while (contenu.find("Introduction") == string::npos) {

                    resume += contenu;
                    getline(fichier, contenu);

                }
                
                
                
                ///////
                 while (contenu.find("References") == string::npos )
            {
           
                getline(fichier, contenu);
            }
            if (contenu.find("References") != string::npos) {
                getline(fichier, contenu);
                while (!fichier.eof()) {

                    reference += contenu;
                    getline(fichier, contenu);

                }
                }
                
                
                
                
                
                fichier.close();  // on ferme le fichier
                
                option(s, resume, titre, auteur,reference ,nomFichier);




            }
            
        else
            cerr << "Impossible d'ouvrir le fichier !" << endl;

        
    }
    return 0;
 }
 int main(){

 	parseur("-x");
 	return 0;
 }
 
    
    
    
    
    


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.


