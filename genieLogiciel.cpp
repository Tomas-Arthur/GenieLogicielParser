// genieLogiciel.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
//#include <Markup.h>

    using namespace std;
     
    int main()//int argc, char* argv[])
    {
        ifstream fichier("Boudin-Torres-2006.txt", ios::in);  // on ouvre le fichier en lecture

        if (fichier)  // si l'ouverture a réussi
        {
            
            string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
            
            string resume;
            string titre;
            string auteur;
            char test;
            int a ;
            getline(fichier, contenu);  // on met dans "contenu" la ligne
            
            
            for (a=0;contenu.find_first_not_of("\n") !=  string::npos  && a < 3;a++)
            {
                if(contenu.find("Florian") == string::npos)
                {
                    cout<<"contenu a la recherche du titre : " + contenu <<endl;
                    titre += contenu;
                    getline(fichier, contenu);
                }
                else
                {
                    a=3;    
                }
                
            }
            
            //titre = contenu;
            //getline(fichier, contenu);
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
                fichier.close();  // on ferme le fichier




            }

            if (true)
            {
                ofstream fichier;
                fichier.open("log.txt", ios::out);
                fichier << "le titre : " << titre << endl;
                fichier << "les auteurs : " << auteur << endl;
                fichier << "le resume : " << resume << endl;
                fichier.close();
                cout << "fin du programme"<<"\n";
            }
            
            
        }
        else
            cerr << "Impossible d'ouvrir le fichier !" << endl;

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
