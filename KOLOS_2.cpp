// PRAWDOPODOBIEŃSTWO:

//Losowanie kolorów z enum z zadanym prawdopodobieństwem:
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum class Kolor {
    Czerwony,
    Zielony,
    Niebieski,
    Zolty,
    Czarny
};

Kolor losujKolor() {
    int los = rand() % 100 + 1;

    if (los >= 1 && los <= 50)
        return Kolor::Czerwony;

    if (los >= 51 && los <= 70)
        return Kolor::Zielony;

    if (los >= 71 && los <= 85)
        return Kolor::Niebieski;

    if (los >= 86 && los <= 95)
        return Kolor::Zolty;

    return Kolor::Czarny; // 96–100
}

int main() {
    srand(time(0));

    int n;
    cout << "Ile kolorow wylosowac? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Kolor k = losujKolor();

        switch (k) {
            case Kolor::Czerwony:  cout << "czerwony" << endl; break;
            case Kolor::Zielony:   cout << "zielony" << endl; break;
            case Kolor::Niebieski: cout << "niebieski" << endl; break;
            case Kolor::Zolty:     cout << "zolty" << endl; break;
            case Kolor::Czarny:    cout << "czarny" << endl; break;
        }
    }

    return 0;
}

// Inny przykład:
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum class Priorytet {
    czarne,
    biale,
    zielone,
    szare,
    niebieskie
};

Priorytet* priorytety(int n) {
    Priorytet* tab = new Priorytet[n];

    int p_czarne = 50;
    int p_biale = p_czarne + 30;
    int p_zielone = p_biale + 20;
    int p_szare = p_zielone + 10;
    int p_niebieskie = p_szare + 10;

    for (int i = 0; i < n; i++) {
        int los = rand() % 120 + 1;

        if (los <= p_czarne)
            tab[i] = Priorytet::czarne;
        else if (los <= p_biale)
            tab[i] = Priorytet::biale;
        else if (los <= p_zielone)
            tab[i] = Priorytet::zielone;
        else if (los <= p_szare)
            tab[i] = Priorytet::szare;
        else
            tab[i] = Priorytet::niebieskie;
    }
    return tab;
}

int main() {
    srand(time(0));

    int n = 2;
    Priorytet* wynik = priorytety(n);

    for (int i = 0; i < n; i++) {
        switch (wynik[i]) {
            case Priorytet::czarne: cout << "czarna kula "; break;
            case Priorytet::biale: cout << "biala kula "; break;
            case Priorytet::zielone: cout << "zielona kula "; break;
            case Priorytet::szare: cout << "szara kula "; break;
            case Priorytet::niebieskie: cout << "niebieska kula "; break;
        }
    }

    delete[] wynik;
}


//Policz wyrazy
#include <iostream>
#include <string>

using namespace std;
struct Pacjent {
    string nazwisko;
    int waga;
};
string tab[6]={"ski","ska","wski","wska","cki","cka"};
bool szukanie( string nazwisko) {
    int a=0;
    for (int j=0; j<6;  j++) {
        int b=tab[0].size();
        for(int i=0; i<nazwisko.size(); i++) {
            cout<<i<<" "<<nazwisko[i]<<"  "<<tab[j][a]<<endl;
            if(nazwisko[i]==tab[j][a])
                a++;
            else
                a=0;
            if (a==b) {
                return true;
            }

        }
    }
    return false;
}
    int policz_wyrazy(const Pacjent *pacjenci, int n) {
        int licznik=0;
        for (int i=0; i<sizeof(pacjenci)/sizeof(pacjenci[0]); i++) {
            if (szukanie(pacjenci->nazwisko))
                licznik++;
        }
        return licznik;
    }

    int main(){

        cout<<szukanie("Kowalski");




        return 0;
    }


//HISTOGRAM:
#include <iostream>
#include <iomanip>

int *histogram_wagi(Pacjent *pacjenci, int n, int bin) {
    int max=0;
    for (int i=0; i<n;i++) {
        if (max<pacjenci->waga)
            max=pacjenci->waga;
    }
    int min=0;
    for (int i=0; i<n;i++) {
        if (min>pacjenci->waga)
            min=pacjenci->waga;
    }
    int *histogram=new int[bin]{};

    for (int i=0; i<n; i++) {
        histogram[pacjenci[i].waga-min]++;
    }
    return histogram;
}


// WYSZUKIWANIE BINARNE:
int wyszukiwanieBinarne(int tablica[], int rozmiar, int szukana) {
    int lewy = 0;
    int prawy = rozmiar - 1;

    while (lewy <= prawy) {
        int srodek = (lewy + prawy) / 2;

        if (tablica[srodek] == szukana)
            return srodek;

        if (tablica[srodek] < szukana)
            lewy = srodek + 1;
        else
            prawy = srodek - 1;
    }

    return -1; // nie znaleziono
}


// Wyszukiwanie po wieku ze struktury pacjent:
struct Pacjent {
    string nazwisko;
    int wiek;
};
int wyszukiwanieBinarnePoWieku(Pacjent pacjenci[], int rozmiar, int szukanyWiek) {
    int lewy = 0;
    int prawy = rozmiar - 1;

    while (lewy <= prawy) {
        int srodek = (lewy + prawy) / 2;

        if (pacjenci[srodek].wiek == szukanyWiek)
            return srodek;

        if (pacjenci[srodek].wiek < szukanyWiek)
            lewy = srodek + 1;
        else
            prawy = srodek - 1;
    }

    return -1; // nie znaleziono pacjenta o podanym wieku
}

