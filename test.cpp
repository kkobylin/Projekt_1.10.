/*Krzysztof Kobyliñski
Projekt 1.10. na PROI*/

#include <iostream>
#include "test.h"
#include "vector.h"
#include <cstdlib>
//#include <conio.h>
#include <stdio.h>

using namespace std;

int funkcja_testujaca()
{
    int wymiar1, wymiar2;
    cout<<"Podaj wymiary obu wektorow"<<endl;

    cin>>wymiar1;

    while(cin.fail())
    {
        cout<<"Wymiar musi byc liczba calkowita. Sprobuj ponownie."<<endl;
        cin.sync();
        cin.clear();
        cin>>wymiar1;
    }

    cin>>wymiar2;

    while(cin.fail())
    {
        cout<<"Wymiar musi byc liczba calkowita. Sprobuj ponownie."<<endl;
        cin.sync();
        cin.clear();
        cin>>wymiar2;
    }

    Vec a(wymiar1), b(wymiar2),c;

    //system("cls");

    char wybor;
    int nr_wektora,i;
    double iloczyn;

    for(;;)
{

    cout << "MENU" << endl;
    cout << "-----------------" << endl;
    cout << "1. Zaladowanie nowych wartosci wektora" << endl;
    cout << "2. Drukowanie wektora" << endl;
    cout << "3. Odczytanie wartosci elementu o danej wspolrzednej." << endl;
    cout << "4. Zmiana wartosci elementu o danej wspolrzednej" << endl;
    cout << "5. Dodawanie wektorow(+ albo +=)" << endl;
    cout << "6. Odejmowanie wektorow(- albo -=)" << endl;
    cout << "7. Iloczyn skalarny wektorow" << endl;
    cout << "8. Porownywanie wektorow(== albo !=)" << endl;
    cout << "9. Koniec programu" << endl;


    cout << endl;
    cin >> wybor;

    switch(wybor)
    {
    case '1':
            cout<<"Podaj numer wektora"<<endl;
            cin>>nr_wektora;
            if(nr_wektora==1)
                {
                cout<<"Podaj "<<wymiar1<<" wartosci."<<endl;
                cin>>a;
                }
            else
                 {
                cout<<"Podaj "<<wymiar2<<" wartosci."<<endl;
                cin>>b;
                }

    break;

    case '2':
            cout<<"Podaj numer wektora"<<endl;
            cin>>nr_wektora;
            if(nr_wektora==1)
                cout<<a;
            else
                cout<<b;
    break;

    case '3':
            cout<<"Podaj numer wektora oraz wspolrzedna ktora chcesz odczytac (numerowana od zera)"<<endl;
            cin>>nr_wektora>>i;
            if(nr_wektora==1)
                a.odczyt(i);
            else
                b.odczyt(i);
    break;

    case '4':
            cout<<"Podaj numer wektora ,wspolrzedna ktora chcesz zmienic oraz nowa wartosc"<<endl;
            cin>>nr_wektora>>i>>iloczyn;
            if(nr_wektora==1)
                a.zmiana(i,iloczyn);
            else
                b.zmiana(i,iloczyn);
    break;

    case '5':
           cout<<"1.a+b="<<endl<<"2. a+=b"<<endl<<"3. b+=a"<<endl;
            cin>>i;
            if(i==1)
                {
                    c=a+b;
                    if(wymiar1==wymiar2)cout<<c<<endl;
                }
            else if(i==2)
                {
                    a+=b;
                }
            else b+=a;

    break;

    case '6':
            cout<<"1.a-b="<<endl<<"2.b-a="<<endl<<"3. a-=b"<<endl<<"4. b-=a"<<endl;
            cin>>i;
            if(i==1)
                {
                    c=a-b;
                    if(wymiar1==wymiar2) cout<<c<<endl;
                }
            else if(i==2)
                {
                    c=b-a;
                    if(wymiar1==wymiar2) cout<<c<<endl;
                }
            else if(i==3)
                a-=b;
            else
                b-=a;
    break;

    case '7':
            iloczyn=a*b;
            if(wymiar1==wymiar2) cout<<iloczyn<<endl;
    break;

    case '8':
            cout<<"1.a==b"<<endl<<"2. a!=b"<<endl;
            cin>>i;
            if(i==1)
                {
                    if(a==b)
                    {
                         cout<<"Wektory sa takie same"<<endl;
                    }
                    else
                         cout<<"Wektory sa rozne"<<endl;
                }
            else if(i==2)
                {
                    if(a!=b)
                    {
                         cout<<"Wektory sa rozne"<<endl;
                    }
                    else
                         cout<<"Wektory sa takie same"<<endl;
                }

    break;

    case '9':
             return 1;;
    break;

    default: cout<<"Nie ma takiej opcji w menu!";
    }

    cout<<"Gotowe"<<endl;
    getchar();getchar();
   // system("cls");
}

}
