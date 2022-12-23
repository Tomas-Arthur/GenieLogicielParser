
#include <iostream>
#include <fstream>
#include <vector>
#include <dirent.h>
#include <string>
#include <filesystem>

using namespace std;
using std::cout; using std::cin;
using std::endl; using std::vector;
    
char * fichierDansDossier()
{
    int chosenOne;
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
        return NULL;
    }
cout  << endl;
    for (auto file : files) 
    {
        
        tabFichier.push_back(file);
    }

    fichier.close();
    for(int i=0; i < tabFichier.size();i++)
    {
        cout<<i<<" : "<<tabFichier[i] << endl;
    }
    cout << "choose your file by entering the number"<<endl;
    cin >> chosenOne;

    if(chosenOne>=0 && chosenOne < tabFichier.size())
    {
        cout << "you choose : " << tabFichier[chosenOne] << endl;
    }

    return tabFichier[chosenOne];
}

    
void option (string s, string resume,string titre,string auteur,string reference,string nomFichier,string conclusion,string discussion){
 if (s=="-t"){
 	ofstream fichier;
 	fichier.open("log.txt");
 	
 	 fichier << "Le nom du fichier d’origine " << nomFichier << endl;
 	
 	 fichier << "le titre : " << titre << endl;
                fichier << "les auteurs : " << auteur << endl;
                fichier << "le resume : " << resume << endl;
                fichier << "les references : " << reference << endl;
                fichier << "les discussions : " << discussion << endl;
                fichier << "les conclusions : " << conclusion << endl;
                fichier.close();
                cout << "fin du programme";
 
 
 
 
 
 }
 else if (s=="-x"){
 
 ofstream fichier;
 fichier.open("log.xml");
 fichier<< "<?xml version='1.0' encoding='utf-8'?>"<<endl;
 fichier<< "<article>"<<endl;
	fichier <<" <preamble> Le nom du fichier "<<nomFichier<<" </preamble>"<<endl;
	fichier <<"<titre> "<< titre << " </titre>"<<endl;
	fichier <<"<auteur> La section auteurs et leur adresse"<< auteur<<" </auteur>"<<endl;
	fichier <<"<abstract> resume article" << resume<< "abstract>" <<endl;

    fichier <<" <conclusion> La conclusion "<<conclusion<<" </conclusion>"<<endl;
    fichier <<" <discussion> La discussion "<<discussion<<" </discussion>"<<endl;
	fichier <<"<biblio> Les references graphiques papier" <<reference<<"</biblio>" <<endl;
       fichier <<	"</article> " ;
 
 
 
 
 }
 }
     
 int parseur(string s , char * fileName){
 
        ifstream fichier(fileName, ios::in);  // on ouvre le fichier en lecture

        if (fichier)  // si l'ouverture a réussi
        {
            
            string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
            string abstract("Abstract");
            string resume;
            string titre;
            string auteur;
            string reference;
            string nomFichier;
            string introduction;
            string discussion;
            string conclusion;
            int a = 0;
            
            nomFichier=fileName;
            getline(fichier, contenu);  // on met dans "contenu" la ligne
            
            titre = contenu;
            getline(fichier, contenu);
            while (contenu.find("Abstract") == string::npos )
            {
                auteur += contenu;
                
                getline(fichier, contenu);
            }
            
            if (contenu.find("Abstract") != string::npos) {
                getline(fichier, contenu);
                while (contenu.find("Introduction") == string::npos) {

                    resume += contenu;
                    getline(fichier, contenu);

                }
                
         /*   while (contenu.find("Conclusions") == string::npos )
            {
                cout << "je suis dans le while de la conclusions";
                getline(fichier, contenu);
            }
            if (contenu.find("Conclusions") != string::npos) {
                getline(fichier, contenu);
                cout << "je recupere la conclusion";
                while (contenu.find("Acknowledgments") != string::npos) {

                    conclusion += contenu;
                    getline(fichier, contenu);

                }
                }*/


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
                
                option(s, resume, titre, auteur,reference ,nomFichier,conclusion,discussion);




            }
            
        else
            cerr << "Impossible d'ouvrir le fichier !" << endl;

        
    }
    return 0;
 }
 int main(){
    
 	parseur("-x",fichierDansDossier());
 	return 0;
 }
