/*Krzysztof Kobyliñski
Projekt 1.10. na PROI*/

#ifndef vec_definition
#define vec_definition

#include <iostream>

using namespace std;

/* Klasa reprezentujaca wektor liczb rzeczywistych
o ustalonej z góry liczbie wymiarow*/

class Vec
{
    int n;  //Liczba wymiarow
    double *tab; //Tablica dynamiczna przechowujaca wartosci

    public:

    Vec(int =5); //Konstruktor
    ~Vec(); //Destruktor
    void odczyt(int);   //Odczyt wartosci elementu o danej wspolrzednej
    void zmiana(int, double);   //Zmiana wartosci elementu o danej wspolrzednej
    void operator=(Vec const &v);   //Przypisywania wektora do innego wektora
    Vec operator+(Vec const &v);    //Dodawanie wektorow
    void operator+=(Vec const &v);  //Dodawanie wektorow za pomoca +=
    Vec operator-(Vec const &v);    //Odejmowanie wektorow
    void operator-=(Vec const &v);  //Odejmowanie wektorow za pomoca -=
    double operator*(Vec const &v); //Iloczyn skalarny wektorow
    bool operator==(Vec const &v);  //Porownywanie wektorow
    bool operator!=(Vec const &v);  //Porownywanie wektorow

    //Funkcja zaprzyjazniona drukujaca wektor
    friend
    ostream& operator<< (ostream &os, const Vec &v);

    //Funkcja zaprzyjazniona wczytujaca wektor
    friend
    istream& operator>>(istream &is, Vec &v);


};
#endif
