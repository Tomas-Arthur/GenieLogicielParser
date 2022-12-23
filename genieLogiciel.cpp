
#include <iostream>
#include <fstream>
#include <vector>
#include <dirent.h>
#include <string>
#include <filesystem>

using namespace std;
using std::cout; using std::cin;
using std::endl; using std::vector;
    
int fichierDansDossier()
{
    
    vector<char *> tabFichier;
    ofstream fichier;
    fichier.open("listFichier.txt", ios::out);
    DIR *dir; struct dirent *diread;
    vector<char *> files;

    if ((dir = opendir("/home/tomas/Bureau/genieLog/GenieLogicielParser/CORPUS_TRAIN")) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
            files.push_back(diread->d_name);
        }
        closedir (dir);
    } else {
        perror ("opendir");
        return EXIT_FAILURE;
    }

    for (auto file : files) 
    {
        tabFichier.push_back(file);
        fichier << file << "| ";
    }

    fichier.close();
    for(int i=0; i < tabFichier.size();i++)
    {
        cout<<tabFichier[i] << endl;
    }
    cout << "fin du programme"<<"\n";

    return EXIT_SUCCESS;
}

    
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
    fichierDansDossier();
 	parseur("-x");
 	return 0;
 }
