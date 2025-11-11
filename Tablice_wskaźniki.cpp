// Inicjalizacja tablicy dynamicznej jedowymiarowej i wypełnienie jej kolejnymi liczbami:
#include<iostream>

using namespace std;

int main()
{
    int N;
    cout<<"N: ";
    cin>>N;
    int licznik=1;
    int *tab=new int[N];
    
    for(int i=0; i<N; i++)
    {
        tab[i]=licznik;
        licznik++;

    }
    
    for(int i=0; i<N; i++)
    {
       cout<<tab[i]<<" ";
    }
    
       delete [] tab;
    return 0;
}

//Inicjalizacja tablicy dynamicznej dwuwymiarowej i wypełnienie jej kolejnymi liczbami:
#include<iostream>

using namespace std;

int main()
{
    int W, K;
    cout<<"W: ";
    cin>>W;
    cout<<"K: ";
    cin>>K;
    int licznik=1;
    int **tab=new int*[W];
    for(int i=0; i<W; i++)
    {
        tab[i]=new int[K];
    }
    
    for(int i=0; i<W; i++)
    {
        for(int j=0; j<K; j++)
        {
            tab[i][j]=licznik;
            licznik++;
        }
    }
    
    for(int i=0; i<W; i++)
    {
        for(int j=0; j<K; j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for(int i=0; i<W; i++)
      delete [] tab[i];
       delete [] tab;
    return 0;
}

// Wskaźniki do funckji- przykłady:
//1
#include <iostream>
using namespace std;

int dodaj(int a, int b) {
    return a + b;
}

int main() {
    int (*wsk)(int, int); // wskaźnik na funkcję int(int,int)
    wsk = dodaj;          // przypisujemy adres funkcji

    int wynik = wsk(5, 3); // wywołanie funkcji przez wskaźnik
    cout << "Wynik: " << wynik << endl; // Wynik: 8
}
//2
#include <iostream>
using namespace std;

void drukuj(int x) {
    cout << "Liczba: " << x << endl;
}

int main() {
    void (*wsk)(int); // wskaźnik do funkcji void(int)
    wsk = drukuj;

    wsk(10); // wywołanie funkcji przez wskaźnik
    wsk(25);
}
//3
#include<iostream>
#include<iomanip>

using namespace std;

float dodaj(float a, float b)
{
   return a+b; 
}

float odejmij(float a, float b)
{
    return a-b;
}

float pomnoz(float a, float b)
{
    return a*b;
}

float podziel(float a, float b)
{
    return a/b;
}

int main()
{
    cout<<fixed<<setprecision(6);
    float a, b;
    char znak;
    cout<<"Działanie: "; cin>>a>>znak>>b;
    
    float(*wsk)(float, float);
    if(znak=='+') wsk=dodaj;
    else if(znak=='-') wsk=odejmij;
    else if(znak=='*') wsk=pomnoz;
    else if(znak=='/') wsk=podziel;
    else{
       cout<<"Nieprawidłowe działanie"<<endl;
       return 0;
    }
    
    float wynik=wsk(a,b);  
    cout<<"Wynik: "<<wynik<<endl;
    
    return 0;
}

//Wskaźniki:
//1:
#include <iostream>
using namespace std;

int main() {
    int tab[5] = {10, 20, 30, 40, 50};
    int *wsk = tab; // wskaźnik na pierwszy element tablicy

    for(int i=0; i<5; i++) {
        cout << *wsk << " "; // odczyt wartości
        wsk++;               // przejście do następnego elementu
    }
}

//2:
#include <iostream>
using namespace std;

int main() {
    int tab[4] = {1, 2, 3, 4};
    int *wsk = tab;

    for(int i=0; i<3; i++) {
        cout << *wsk << " " << *(wsk+1) << endl;
        wsk++; // przesunięcie wskaźnika
    }
}
// Wynik
1 2
2 3
3 4
// Zmiana wartości z tablicy:
#include <iostream>
using namespace std;

int main() {
    int tab[3] = {5, 10, 15};
    int *wsk = tab;
    for(int i=0; i<3; i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
    
    for(int i=0; i<3; i++) {
        *wsk = *wsk * 2; // zmiana wartości przez wskaźnik
        wsk++;
    }

    for(int i=0; i<3; i++)
        cout << tab[i] << " "; // 10 20 30
}
// Wynik:
5 10 15 
10 20 30 

// Wskaźniki w tablicy dynamicznej:
#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int *tab = new int[n]; // dynamiczna tablica

    for(int i=0; i<n; i++)
        tab[i] = i+1;

    int *wsk = tab; // wskaźnik na pierwszy element
    for(int i=0; i<n; i++) {
        cout << *wsk << " "; // odczyt
        wsk++;
    }

    delete[] tab; // zwolnienie pamięci
}
// Wynik:
1 2 3 4







W
