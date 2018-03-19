/*Krzysztof Kobyliñski
Projekt 1.10. na PROI*/

#include <iostream>
#include "vector.h"
#include <cstdlib>

using namespace std;

//Konstruktor
Vec::Vec(int wymiar)
{
    tab = new double[wymiar];

    n=wymiar;

    //Wartosci domyslne wektora
    for(int i=0;i<wymiar;i++)
        tab[i]=i;

}


void Vec::odczyt(int i)
{
    //Sprawdzanie poprawnosci danych
    if(i<n && i>=0)
    cout<<tab[i];
    else
    cerr<<"Nie ma takiego elementu w wektorze"<<endl;
}

void Vec::zmiana(int i, double war=0)
{
    //Sprawdzanie poprawnosci danych
    if (i<n && i>=0)
        tab[i]=war;
    else
        cerr<<"Nie ma takiego elementu w wektorze"<<endl;
}

void Vec::operator=(Vec const &v)
{
    n=v.n;

    for(int i=0;i<n;i++)
        tab[i]=v.tab[i];

}

Vec Vec::operator+(Vec  const &v)
{
    Vec temp(v.n);

    if(v.n==n)
    {
    for(int i=0;i<n;i++)
    {
        temp.tab[i]=tab[i]+v.tab[i];
    }
    return temp;
    }

    else
    {
        cerr<<"Nie mozna dodac wektorow, poniewaz maja rozne wymiary"<<endl;
        //exit (EXIT_FAILURE);
    }



}

void Vec::operator+=(Vec const &v)
{
    if(v.n==n)
    {
    for(int i=0;i<n;i++)
    {
        tab[i]=v.tab[i]+tab[i];
    }
    }

    else
        {
        cerr<<"Nie mozna dodac wektorow, poniewaz maja rozne wymiary"<<endl;
        exit (EXIT_FAILURE);
        }
}

Vec Vec::operator-(Vec  const &v)
{
    Vec temp(v.n);

    if(v.n==n)
    {
    for(int i=0;i<n;i++)
    {
        temp.tab[i]=tab[i]-v.tab[i];
    }
    }

    else
    {
        cerr<<"Nie mozna odjac wektorow, poniewaz maja rozne wymiary"<<endl;
        exit (EXIT_FAILURE);
    }


    return temp;
}

void Vec::operator-=(Vec const &v)
{
    if(v.n==n)

    for(int i=0;i<n;i++)
    {
        tab[i]=tab[i]-v.tab[i];
    }

    else
        {
        cerr<<"Nie mozna odjac wektorow, poniewaz maja rozne wymiary"<<endl;
        exit (EXIT_FAILURE);
        }
}

double Vec::operator*(Vec const &v)
{
    double temp=0;

    if(n==v.n)

    for(int i=0;i<n;i++)
    {
        temp+=v.tab[i]*tab[i];
    }

    else
    {
         cerr<<"Nie mozna policzyc iloczynu skalarnego, poniewaz wektory maja rozne wymiary"<<endl;
        exit (EXIT_FAILURE);
    }

    return temp;
}

bool Vec::operator==(Vec const &v)
{

    bool temp=1;

    if(n==v.n)

    for(int i=0;i<n;i++)
    {
        if(v.tab[i]!=tab[i]) {temp=0;break;}
    }

    else temp=0;

    return temp;
}

bool Vec::operator!=(Vec const &v)
{

    bool temp=0;

    if(n==v.n)

    for(int i=0;i<n;i++)
    {
        if(v.tab[i]!=tab[i]) {temp=1;break;}
    }

    else temp=1;

    return temp;
}

ostream& operator<< (ostream &os, const Vec &v)
{

    for(int i=0;i<v.n;i++)
        os<<v.tab[i]<<" ";
    os<<endl;

    return os;
}

istream& operator>> (istream &is, Vec &v)
{
   double liczba;

    for(int i=0;i<v.n;i++)
        {
            is>>liczba;
            //Sprawdzanie poprawnosci wprowadzonych danych
            if(is.good()) v.tab[i]=liczba;
            else {cerr<<"To nie liczba. Podaj wspolrzedna "<<i<<" jeszcze raz."<<endl;
                    i--;
                    is.clear();
                    is.sync();
                }
        }


    return is;
}

//destruktor
Vec::~Vec()
{
    for(int i=0;i<n;i++)
        tab[i]=0;
    delete [] tab;
}
