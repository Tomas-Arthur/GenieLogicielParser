
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
    char* fileChosen;
    vector<char *> tabFichier;
    ofstream fichier;
    fichier.open("listFichier.txt", ios::out);
    DIR *dir; struct dirent *diread;
    vector<char *> files;

    if ((dir = opendir("/home/tomas/Bureau/genieLog/GenieLogicielParser/CORPUS_TRAIN")) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
            files.push_back(diread->d_name);
           //cout<<diread->d_name<<endl;
        }
        closedir (dir);
    } else {
        perror ("opendir");
        return NULL;
    }

    for(int i=0; i < files.size();i++)
    {
        cout<<i<<" : "<<files[i] << endl;
    }
    cout << "choose your file by entering the number"<<endl;
    cin >> chosenOne;

    if(chosenOne>=0 && chosenOne < files.size())
    {
        cout << "you choose : " << files[chosenOne] << endl;
        fileChosen = files[chosenOne];
    }

    fichier.close();
    

    return fileChosen;
}

    
void option (string s, string resume,string titre,string auteur,string reference,string nomFichier,string conclusion,string discussion,string introduction,string corps){
 if (s=="-t"){
 	ofstream fichier;
 	fichier.open("log.txt");
 	
 	 fichier << "Le nom du fichier d’origine " << nomFichier << endl;
 	
 	 fichier << "le titre : " << titre << endl;
                fichier << "les auteurs : " << auteur << endl;
                fichier << "le resume : " << resume << endl;
                fichier << "l'introduction : "<<introduction<<endl;
                fichier << "le corps : "<<corps<<endl;
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
    fichier <<"<introduction> introduction article" << introduction<< "</introduction>" <<endl;
    fichier <<" <corps> Le corps "<<corps<<" </corps>"<<endl;
    fichier <<" <conclusion> La conclusion "<<conclusion<<" </conclusion>"<<endl;
    fichier <<" <discussion> La discussion "<<discussion<<" </discussion>"<<endl;
	fichier <<"<biblio> Les references graphiques papier" <<reference<<"</biblio>" <<endl;
       fichier <<	"</article> " ;
 
 
 
 
 }
 }
     
 int parseur(string s , char * fileName){
 
        ifstream fichier("compression.txt", ios::in);  // on ouvre le fichier en lecture

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
            string corps;
            string discussion;
            string conclusion;
            int a = 0;
            
            nomFichier=fileName;
            getline(fichier, contenu);  // on met dans "contenu" la ligne
            
            titre = contenu;
            getline(fichier, contenu);
            while (contenu.find("Abstract") == string::npos && a < 10)
            {
                auteur += contenu;
                a++;
                getline(fichier, contenu);
            }
            a=0;
            if (contenu.find("Abstract") != string::npos) {
                getline(fichier, contenu);
                while (contenu.find("Introduction") == string::npos) {

                    resume += contenu;
                    getline(fichier, contenu);

                }

            while (contenu.find("Introduction") == string::npos && a < 100)
            {
                
                getline(fichier, contenu);
            }
            if (contenu.find("Introduction") != string::npos) 
            {
                getline(fichier, contenu);
                
                while (contenu.find("2 ") == string::npos && contenu.find("2.") == string::npos)
                {
                    
                    introduction += contenu;
                    getline(fichier, contenu);

                }
            }
            a=0;

                
            while (contenu.find("Conclusions") == string::npos && contenu.find("Conclusion") == string::npos && contenu.find("Discussion") == string::npos&& !fichier.eof())
            {
                corps += contenu;
                getline(fichier, contenu);
            }
            if (contenu.find("Conclusions") != string::npos || contenu.find("Conclusion") != string::npos) 
            {
                getline(fichier, contenu);
               // cout << "je detecte la conclusion"<<endl;
                while (contenu.find("Acknowledgments") == string::npos && contenu.find("References") == string::npos)
                {
                   // cout << "je recupere la conclusion";
                    conclusion += contenu;
                    getline(fichier, contenu);

                }
            }
            
            if (contenu.find("Discussion") != string::npos) 
            {
                getline(fichier, contenu);
               // cout << "je detecte la conclusion"<<endl;
                while (contenu.find("Acknowledgments") == string::npos && contenu.find("References") == string::npos)
                {
                   // cout << "je recupere la conclusion";
                    conclusion += contenu;
                    getline(fichier, contenu);

                }
            }



                ///////
            while (contenu.find("References") == string::npos  && !fichier.eof())
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
                
                option(s, resume, titre, auteur,reference ,nomFichier,conclusion,discussion,introduction,corps);




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