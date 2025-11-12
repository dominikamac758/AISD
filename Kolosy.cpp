// GRUPA 1:
// czy fibo:
#include <iostream>
using namespace std;

bool czyFibo(int n) {
    if (n < 0) return false;
    if (n == 0 || n == 1) return true;

    int poprzednia = 0;
    int nastepna = 1;
    int temp;

    while (nastepna < n) {
        temp = nastepna;
        nastepna = poprzednia + nastepna;
        poprzednia = temp;
    }

    return nastepna == n;
}

int main() {
    int liczba;
    cout << "Podaj liczbe: ";
    cin >> liczba;

    if (czyFibo(liczba))
        cout << liczba << " jest liczba Fibonacciego.\n";
    else
        cout << liczba << " nie jest liczba Fibonacciego.\n";

    return 0;
}

// ostatnia cyfra liczby słownie:
#include <iostream>
using namespace std;

int main() {
    int liczba;
    cout << "Podaj liczbe: ";
    cin>>liczba;

    if (liczba < 0) {
        cout << "Blad: liczba ujemna\n";
        return 1;
    }

    int ostatniaCyfra = liczba % 10;

    switch (ostatniaCyfra) {
        case 0: cout << "zero\n"; break;
        case 1: cout << "jeden\n"; break;
        case 2: cout << "dwa\n"; break;
        case 3: cout << "trzy\n"; break;
        case 4: cout << "cztery\n"; break;
        case 5: cout << "pięć\n"; break;
        case 6: cout << "sześć\n"; break;
        case 7: cout << "siedem\n"; break;
        case 8: cout << "osiem\n"; break;
        case 9: cout << "dziewięć\n"; break;
    }

    return 0;
}

// konwersja na małe:
#include <iostream>
using namespace std;

char* male_litery(const char* tekst, int n) {
    // alokujemy nową tablicę (z miejscem na znak końca '\0')
    char* nowy = new char[n + 1];

    for (int i = 0; i < n; i++) {
        char znak = tekst[i];

        // jeśli to wielka litera (A-Z), zamieniamy ją na małą
        if (znak >= 'A' && znak <= 'Z') {
            znak = znak + ('a' - 'A');  // różnica między wielką a małą literą w ASCII
        }

        nowy[i] = znak;
    }

    nowy[n] = '\0'; // zakończenie łańcucha
    return nowy;
}

int main() {
    const char tekst[] = "HeLLo WoRLd!";
    int n = 12; // długość tekstu (bez '\0')

    char* wynik = male_litery(tekst, n);

    cout << "Oryginalny tekst: " << tekst << endl;
    cout << "Po zamianie na male litery: " << wynik << endl;

    delete[] wynik; // zwalniamy pamięć
    return 0;
}

// lub:
#include <iostream>
using namespace std;

char* male_litery(const char* tekst, int n) {
    char* wynik = new char[n + 1]; // nowa tablica z miejscem na '\0'

    for (int i = 0; i < n; i++) {
        if (tekst[i] >= 'A' && tekst[i] <= 'Z')
            wynik[i] = tekst[i] + 32;   // zamiana wielkiej litery na małą
        else
            wynik[i] = tekst[i];        // zostaw bez zmian
    }

    wynik[n] = '\0'; // koniec tekstu
    return wynik;
}

int main() {
    const char tekst[] = "ProSTy PrzyKLad!";
    int n = 17; // długość tekstu bez '\0'

    char* wynik = male_litery(tekst, n);

    cout << "Oryginalny: " << tekst << endl;
    cout << "Male litery: " << wynik << endl;

    delete[] wynik; // zwolnienie pamięci
    return 0;
}

// podzielne przez 3 i 4:
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void podzielne_3_4(int* tab, int n) {
    srand(time(NULL));
    int maxPowtorzen = n / 5;

    for (int i = 0; i < n; i++) {
        int liczba;
        bool poprawna;

        do {
            liczba = 1000 + rand() % 999; // losowanie z [1000, 1999)
            poprawna = (liczba % 3 == 0 && liczba % 4 == 0);

            if (poprawna) {
                int count = 0;
                for (int j = 0; j < i; j++) {
                    if (tab[j] == liczba) count++;
                }
                if (count >= maxPowtorzen) poprawna = false;
            }

        } while (!poprawna);

        tab[i] = liczba;
    }
}

int main() {
    const int n = 20;
    int tab[n];

    podzielne_3_4(tab, n);

    cout << "Tablica liczb podzielnych przez 3 i 4 (mniej niz 20% powtorzen):\n";
    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;

    return 0;
}

// lub:
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void podzielne_3_4(int* tab, int n) {
    srand(time(NULL));
    int maxPowtorzen = n / 5;

    for (int i = 0; i < n; ) { // nie zwiększamy i od razu, tylko gdy liczba zostanie zaakceptowana
        int liczba = 1000 + rand() % 999;

        // sprawdzamy podzielność
        if (liczba % 3 == 0 && liczba % 4 == 0) {
            // liczymy ile razy liczba występuje już w tablicy
            int count = 0;
            for (int j = 0; j < i; j++) {
                if (tab[j] == liczba) count++;
            }

            if (count < maxPowtorzen) { // warunek: liczba występuje mniej niż 20%
                tab[i] = liczba; // zapisujemy do tablicy
                i++;              // zwiększamy i tylko gdy liczba została zaakceptowana
            }
        }
        // jeśli warunki nie są spełnione, for i nie jest zwiększane → próbujemy ponownie
    }
}

int main() {
    const int n = 20;
    int tab[n];

    podzielne_3_4(tab, n);

    cout << "Tablica liczb podzielnych przez 3 i 4 (mniej niz 20% powtorzen):\n";
    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;

    return 0;
}
// wypełnienie kolumnami:
#include <iostream>
using namespace std;

int wypełnij_tablicę_i_sumuj(int n) {
    // dynamiczna alokacja tablicy n x n
    int** tab = new int*[n];
    for (int i = 0; i < n; i++)
        tab[i] = new int[n];

    // wypełnianie tablicy kolumnami
    int liczba = 1;
    for (int j = 0; j < n; j++) {        // po kolumnach
        for (int i = 0; i < n; i++) {    // po wierszach
            tab[i][j] = liczba++;
        }
    }

    // obliczanie sumy liczb na brzegu
    int suma = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n-1 || j == 0 || j == n-1) {
                suma += tab[i][j];
            }
        }
    }

    // wypisanie tablicy z formatowaniem 3 miejsca na liczbę
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout.width(3);
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }

    // zwolnienie pamięci
    for (int i = 0; i < n; i++)
        delete[] tab[i];
    delete[] tab;

    return suma;
}

int main() {
    int n;
    cout << "Podaj rozmiar tablicy kwadratowej n: ";
    cin >> n;

    int sumaBrzegu = wypełnij_tablicę_i_sumuj(n);
    cout << "Suma liczb na brzegu: " << sumaBrzegu << endl;

    return 0;
}

// formatowanie ręcznie:
// wypisanie tablicy – proste formatowanie
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tab[i][j] < 10) cout << "  ";    // dwie spacje dla liczb jednocyfrowych
            else if (tab[i][j] < 100) cout << " "; // jedna spacja dla liczb dwucyfrowych
            // liczby >=100 nie potrzebują dodatkowych spacji
            cout << tab[i][j] << " ";
        }
// Tablica rejestracyjna:
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char* tablica_rejestracyjna() {
    srand(time(NULL)); // inicjalizacja generatora losowego

    const char litery[] = {
        'A','C','E','F','G','H','J','K','L','M','N','P','Q','R','S','T','U','V','W','X','Y'
    };
    const int liczba_liter = sizeof(litery)/sizeof(litery[0]);

    char* tab = new char[8]; // "KR" + 5 znaków + '\0'
    tab[0] = 'K';
    tab[1] = 'R';

    // Generowanie 5 znaków
    for (int i = 2; i < 7; i++) {
        if (rand() % 2 == 0)
            tab[i] = '0' + rand() % 10;         // cyfra
        else
            tab[i] = litery[rand() % liczba_liter]; // litera
    }

    // Sprawdzenie i poprawienie, jeśli brak litery lub cyfry
    bool jest_cyfra = false, jest_litera = false;
    for (int i = 2; i < 7; i++) {
        if (tab[i] >= '0' && tab[i] <= '9') jest_cyfra = true;
        else jest_litera = true;
    }
    if (!jest_cyfra) tab[2] = '0' + rand() % 10;           // wymuszenie cyfry
    if (!jest_litera) tab[3] = litery[rand() % liczba_liter]; // wymuszenie litery

    tab[7] = '\0'; // zakończenie łańcucha
    return tab;
}

int main() {
    char* rejestracja = tablica_rejestracyjna();
    cout << "Tablica rejestracyjna: " << rejestracja << endl;
    delete[] rejestracja;
    return 0;
}

// Wypełnianie kolumnami od końca:
#include <iostream>
using namespace std;

int wypelnij_kolumny_od_konca_i_sumuj_przekatne(int n) {
    // dynamiczna alokacja tablicy n x n
    int** tab = new int*[n];
    for (int i = 0; i < n; i++)
        tab[i] = new int[n];

    // wypełnianie kolumnami od końca
    int liczba = 1;
    for (int j = n - 1; j >= 0; j--) {     // kolumny od końca
        for (int i = 0; i < n; i++) {      // wiersze od góry
            tab[i][j] = liczba++;
        }
    }

    // obliczanie sumy liczb na przekątnych
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += tab[i][i];         // przekątna główna
        suma += tab[i][n - 1 - i]; // przekątna boczna
    }
    if (n % 2 == 1) suma -= tab[n / 2][n / 2]; // odjęcie środka, jeśli n jest nieparzyste

    // wypisanie tablicy – proste formatowanie 3 miejsca
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tab[i][j] < 10) cout << "  ";     // dwie spacje dla jednocyfrowych
            else if (tab[i][j] < 100) cout << " "; // jedna spacja dla dwucyfrowych
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }

    // zwolnienie pamięci
    for (int i = 0; i < n; i++)
        delete[] tab[i];
    delete[] tab;

    return suma;
}

int main() {
    int n;
    cout << "Podaj rozmiar tablicy kwadratowej n: ";
    cin >> n;

    int sumaPrzekatnych = wypelnij_kolumny_od_konca_i_sumuj_przekatne(n);
    cout << "Suma liczb na przekatnych: " << sumaPrzekatnych << endl;

    return 0;
}
// funkcja suma cyfr parzysta:
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void suma_cyfr_parzysta(int *tab, int n, int a, int b) {
    srand(time(NULL)); // inicjalizacja generatora losowego
    int maxPowtorzen = n / 5; // max 20% powtórzeń

    for (int i = 0; i < n; i++) {
        int liczba;
        do {
            liczba = a + rand() % (b - a);

            // liczymy sumę cyfr "w locie"
            int suma = 0;
            int temp = liczba;
            if (temp < 0) temp = -temp; // obsługa liczb ujemnych
            while (temp > 0) {
                suma += temp % 10;
                temp /= 10;
            }

            // sprawdzamy sumę cyfr i powtórzenia
            if (suma % 2 != 0) continue;

            int count = 0;
            for (int j = 0; j < i; j++)
                if (tab[j] == liczba) count++;

            if (count >= maxPowtorzen) continue;

            break; // liczba jest dobra, wychodzimy z pętli

        } while (true);

        tab[i] = liczba;
    }
}

int main() {
    const int n = 20;
    int tab[n];

    int a = 10, b = 100;

    suma_cyfr_parzysta(tab, n, a, b);

    cout << "Tablica liczb o parzystej sumie cyfr:\n";
    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;

    return 0;
}
//czy pierwsza
#include <iostream>
using namespace std;

bool czy_pierwsza(int n) {
    if (n < 2) return false;      // liczby < 2 nie są pierwsze
    for (int i = 2; i * i <= n; i++) { // sprawdzamy dzielniki do pierwiastka z n
        if (n % i == 0) return false;  // jeśli jest dzielnik → nie pierwsza
    }
    return true; // brak dzielników → liczba pierwsza
}

int main() {
    int liczba;
    cout << "Podaj liczbe: ";
    cin >> liczba;

    if (czy_pierwsza(liczba))
        cout << liczba << " jest liczba pierwsza.\n";
    else
        cout << liczba << " nie jest liczba pierwsza.\n";

    return 0;
}
// policz litere w teksie:
#include <iostream>
using namespace std;

int policz_litery(char *tekst, int n, char litera) {
    int licznik = 0;
    for (int i = 0; i < n; i++) {
        if (tekst[i] == litera) {
            licznik++;
        }
    }
    return licznik;
}

int main() {
    char tekst[] = "Hello World!";
    int n = sizeof(tekst) - 1; // długość tekstu bez znaku '\0'
    char litera = 'l';

    int ile = policz_litery(tekst, n, litera);
    cout << "Litera '" << litera << "' wystepuje " << ile << " razy." << endl;

    return 0;
}
// lub:
#include <iostream>
using namespace std;

int policz_litery(const char* tekst, char litera) {
    int licznik = 0;
    for (char c : string(tekst)) { // tworzymy tymczasowy std::string, żeby użyć range-for
        if (c == litera) {
            licznik++;
        }
    }
    return licznik;
}

int main() {
    char tekst[] = "Hello World!";
    char litera = 'l';

    int ile = policz_litery(tekst, litera);
    cout << "Litera '" << litera << "' wystepuje " << ile << " razy." << endl;

    return 0;
}



