//------------------------------------------------------------ Fichier: variance.h ------------------------------------------------------------

#ifndef VARIANCE_H_INCLUDED
#define VARIANCE_H_INCLUDED

class variance
{
    public:

        //-- CONSTRUCTEUR --

        variance();

        //-- FONCTIONS --

        void saisie(std::vector<double> &);
        double moy(const std::vector<double> &);
        double var(const std::vector<double> & , bool);

};

#endif

//----------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------ Fichier: variance.cpp ------------------------------------------------------------

#include <iostream>
#include <vector>
#include <sstream>
#include "variance.h"

//-- CONSTRUCTEUR --

variance::variance(){}

//--FIN DU CONSTRUCTEUR --

//-- METHODES --

void variance::saisie(std::vector<double> &t)// saisie dans un tableau.
{

    std::cout<<std::endl<<"Entrer les valeurs:";
    std::cout<<std::endl<<"_________________________________";
    std::cout<<std::endl<<"  >(O_O)<  | Valeurs "<<std::endl;
    std::cout<<"-----------|---------------------";
    std::cout<<std::endl;

    // fin de présentation, ==> insertion.

    std::string saisie;
    std::string verif;

    size_t found;
    bool good=1;

    for(unsigned int i=0;i<t.size();i++)
    {
        std::cout<<"           | "<<i+1<<". :   ";
        do
        {
            if(good==0)// en cas d'erreur de saisie...
            {
                std::cout<<">RESSAISIR | "<<i+1<<". :   ";
            }

            std::cin>>saisie;

            found=saisie.find_first_of(",");
            while (found!=std::string::npos)
            {
                saisie[found]='.';// les virgules françaises seront automatiquement transformées en point.
                found=saisie.find_first_of(",",found+1);
            }

            std::istringstream iss(saisie);// conversion du type string en type double.
            iss>>t[i];
            if(iss.fail())
            {
                good=0;
            }
            else
            {
                std::ostringstream oss;
                oss<<t[i];
                verif=oss.str();

                if(verif.size() < saisie.size())
                {
                    good=0;
                }
                else{good=1;}
            }

        }while(good==0);
    }
}

double variance::moy(const std::vector<double> &t)
{
    double k=0;
    for(unsigned int i=0 ; i<t.size() ; i++)
    {
        k=k+t[i];
    }

    k=k/t.size();

    return k;
}

double variance::var(const std::vector<double> &t , bool bout)
{
    double u;
    u=moy(t);

    double k=0;
    for(unsigned int i=0 ; i<t.size() ; i++)
    {
        k=k+(t[i]-u)*(t[i]-u);
    }

    if(bout==0)
    {
        k=k/t.size();
    }
    else
    {
        k=k/(t.size()-1);
    }

    return k;
}

//--FIN DES METHODES--

//-------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------ Fichier: main.cpp ------------------------------------------------------------

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include "variance.h"

int entier()
{
    std::string saisie;
    std::string verif;

    bool good=1;
    bool trouble=0;
    int num;

    do
    {
        if(good==0)
        {
            std::cout<<std::endl<<"-> Saisie incorrecte, ressaisissez: ";
        }

        std::cin>>saisie;

        std::istringstream iss(saisie);// conversion du type string en type double.
        iss>>num;
        if(iss.fail())
        {
            good=0;
            trouble=1;
        }
        else
        {
            std::ostringstream oss;
            oss<<num;
            verif=oss.str();

            if(verif.size() < saisie.size())
            {
                good=0;
                trouble=1;
            }
            else{good=1;}
        }

        if(good==1 && trouble==1)
        {
            std::cout<<"-> OK!"<<std::endl;
        }

    }while(good==0);

    return num;
}

int main()
{
    std::cout<<">-------------------- CALCUL DE VARIANCE --------------------<"<<std::endl<<std::endl;

    std::cout<<"  |--------------------------------------------------------|"<<std::endl;
    std::cout<<"  |        sigma^2 = somme{i=1 -> i=n}[(Xi-u)^2/n]         |"<<std::endl;
    std::cout<<"  |                                                        |"<<std::endl;
    std::cout<<"  |   le i de Xi est l'observation <<i>> de la variable X  |"<<std::endl;
    std::cout<<"  |   u est la moyenne de la variable X                    |"<<std::endl;
    std::cout<<"  |   n est le nombre d'observations                       |"<<std::endl;
    std::cout<<"  |--------------------------------------------------------|"<<std::endl<<std::endl<<std::endl;

    int taille;
    int quitter=0;
    int choix;
    double sigma;

    variance v;

    do//pour le "quitter" de fin
    {
        std::cout<<"--------------------  MENU  --------------------"<<std::endl<<std::endl;

        std::cout<<"     1. Calcul de moyenne"<<std::endl;
        std::cout<<"     2. Calcul de variance sur une population"<<std::endl;
        std::cout<<"     3. Calcul de variance sur une partie de population"<<std::endl<<std::endl;
        std::cout<<"     0. ) Quitter ("<<std::endl;

        if(quitter==0)// cela ne sera possible que lors de la première utilisation, après il sera obligatoirement égal à 1 pour pouvoir recommencer un autre calcul.
        {
            std::cout<<std::endl<<std::endl;
            std::cout<<"  (NOTE: Le calcul de variance s'occupera de faire la moyenne.)";
            std::cout<<std::endl;
        }

        std::cout<<std::endl<<"--> Choix: ";
        do
        {
            choix=entier();
            if(choix<0 || choix>3){std::cout<<std::endl<<"-> Le choix "<<choix<<" n'existe pas, ressaisissez: ";}
        }while(choix<0 || choix>3);

	if(choix==0)
        {
            std::cout<<std::endl<<">------------------------------------------------------------<"<<std::endl<<std::endl;
            return 0;
        }

        std::cout<<std::endl;

        do
        {
            std::cout<<"Indiquer le nombre de valeurs: ";
            taille=entier();
            if(taille<1){std::cout<<std::endl<<"-> ATTENTION! Il doit subsister au moins une valeur. Ressaisissez."<<std::endl<<std::endl;}
        }while(taille<1);

        std::vector<double> VAL(taille,0);// définition du "tableau" de stockage des valeurs.

        v.saisie(VAL);

        if(choix==1)
        {
            std::cout<<std::endl<<"==> La moyenne est de "<<v.moy(VAL)<<std::endl;
        }
        else
        {
            if(choix==2)
            {
                sigma=v.var(VAL , 0);
            }
            else
            {
                sigma=v.var(VAL , 1);
            }

            std::cout<<std::endl<<"==> La variance est de "<<sigma<<std::endl;
            std::cout<<"==> sigma = "<<sqrt(sigma)<<std::endl;
        }

        std::cout<<std::endl<<std::endl<<">------------------------------------------------------------<"<<std::endl;
        std::cout<<std::endl<<"--> Faire un autre calcul? (1=oui/0=non): ";
        quitter=entier();
        std::cout<<std::endl<<">------------------------------------------------------------<"<<std::endl<<std::endl;

    }while(quitter>0);
    return 0;
}

//------------------------------
