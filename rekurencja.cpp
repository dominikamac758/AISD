// ciąg kolos 1grupa
#include <iostream>
using namespace std;

// funkcja rekurencyjna licząca ciąg
int ciag(int n) {
    if (n < 2) return 2;            // przypadek bazowy
    int poprzedni = ciag(n - 1);    // obliczamy a_{n-1}
    if (n % 2 == 0) return 2 + poprzedni; // parzyste
    else return 2 * poprzedni;             // nieparzyste
}

int main() {
    int n;
    cout << "Podaj n: ";
    cin >> n;
    cout << ciag(n) << endl;
    return 0;
}

//geometryczny 
#include <iostream>
using namespace std;

// Funkcja rekurencyjna licząca n-ty wyraz ciągu geometrycznego
double ciagGeometryczny(int n, double a0, double r) {
    if (n == 0) return a0;           // przypadek bazowy
    return ciagGeometryczny(n - 1, a0, r) * r; // wyraz n = poprzedni * r
}

int main() {
    double a0, r;
    int n;

    cout << "Podaj pierwszy wyraz a0: ";
    cin >> a0;
    cout << "Podaj iloraz r: ";
    cin >> r;
    cout << "Podaj numer wyrazu n: ";
    cin >> n;

    double wynik = ciagGeometryczny(n, a0, r);
    cout << "a[" << n << "] = " << wynik << endl;
    return 0;
}

//funkcja:
#include <iostream>
using namespace std;

// Funkcja rekurencyjna z różnymi wzorami w zależności od zakresu x
int funkcja(int x) {
    if (x == 0) return 1;              // przypadek bazowy
    if (x < 10) return funkcja(x - 1) + 3;       // x < 10: rośnie liniowo
    if (x <= 20) return 2 * funkcja(x - 1);     // 10 <= x <= 20: rośnie geometrycznie
    return funkcja(x - 1) - 1;                  // x > 20: maleje liniowo
}

//Prwdopodobienstwo:
#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time
using namespace std;

// Funkcja losująca liczbę oczek według niestandardowego rozkładu
int rzutKostka() {
    // Tablica kumulatywnych prawdopodobieństw w procentach
    // 1 -> 0..39, 2 -> 40..49, 3 -> 50..59, 4 -> brak, 5 -> 60..89, 6 -> 90..99
    int los = rand() % 100; // losujemy liczbę 0-99

    if (los < 40) return 1;      // 40%
    else if (los < 50) return 2; // 10%
    else if (los < 60) return 3; // 10%
    else if (los < 60) return 4; // 0% (nigdy)
    else if (los < 90) return 5; // 30%
    else return 6;               // 10%
}

int main() {
    srand(time(0)); // inicjalizacja generatora losowego

    int liczbaRzutow;
    cout << "Ile razy chcesz rzucić kostką? ";
    cin >> liczbaRzutow;

    for (int i = 0; i < liczbaRzutow; i++) {
        cout << "Rzut " << i + 1 << ": " << rzutKostka() << endl;
    }

    return 0;
}

//#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Funkcja losująca jedną kulę zgodnie z rozkładem
string losujKule() {
    // liczba kul dla każdego koloru
    int czarne = 50;
    int biale = 30;
    int zielone = 20;
    int szare  = 10;
    int niebieskie = 10;

    int suma = czarne + biale + zielone + szare + niebieskie;
    int los = rand() % suma; // losujemy liczbę od 0 do suma-1

    if (los < czarne) return "czarna";
    else if (los < czarne + biale) return "biala";
    else if (los < czarne + biale + zielone) return "zielona";
    else if (los < czarne + biale + zielone + szare) return "szara";
    else return "niebieska";
}

int main() {
    srand(time(0));

    string kula1 = losujKule();
    string kula2 = losujKule();

    cout << kula1 << " " << kula2 << endl;

    return 0;
}

//Palindrom
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tekst;
    cout << "Ciąg znaków: "; 
    getline(cin, tekst);

    string nowy_tekst="";
    for (char c : tekst)
    {
        if (c != ' ') 
            nowy_tekst += c;
    }

   
    int d = nowy_tekst.length();
    bool palindrom = true;

    for (int i = 0; i < d / 2; i++)
    {
        if (nowy_tekst[i] != nowy_tekst[d - 1 - i])
        {
            palindrom = false;
            break;
        }
    }

 
    if (palindrom)
        cout << "Ciąg \"" << tekst << "\" jest palindromem";
    else
        cout << "Ciąg \"" << tekst << "\" nie jest palindromem";

    return 0;
}


//Sortowanie:
#include <iostream>
using namespace std;

// Quicksort rosnąco
void quicksortRosnaco(int tab[], int lewy, int prawy) {
    if (lewy >= prawy) return;
    int pivot = tab[prawy];
    int i = lewy - 1;
    for (int j = lewy; j < prawy; j++) {
        if (tab[j] <= pivot) {
            i++;
            swap(tab[i], tab[j]);
        }
    }
    swap(tab[i+1], tab[prawy]);
    int p = i+1;
    quicksortRosnaco(tab, lewy, p-1);
    quicksortRosnaco(tab, p+1, prawy);
}

// Quicksort malejąco
void quicksortMalejaco(int tab[], int lewy, int prawy) {
    if (lewy >= prawy) return;
    int pivot = tab[prawy];
    int i = lewy - 1;
    for (int j = lewy; j < prawy; j++) {
        if (tab[j] >= pivot) {
            i++;
            swap(tab[i], tab[j]);
        }
    }
    swap(tab[i+1], tab[prawy]);
    int p = i+1;
    quicksortMalejaco(tab, lewy, p-1);
    quicksortMalejaco(tab, p+1, prawy);
}

int main() {
    int tablica[] = {5, 2, 9, 8, 4, 7, 6, 1, 3};
    int n = sizeof(tablica)/sizeof(tablica[0]);

    int parzyste[100], nieparzyste[100]; // zakładamy max 100 elementów
    int p = 0, np = 0;

    // Rozdzielenie liczb parzystych i nieparzystych
    for (int i = 0; i < n; i++) {
        if (tablica[i] % 2 == 0) parzyste[p++] = tablica[i];
        else nieparzyste[np++] = tablica[i];
    }


  #include <iostream>
using namespace std;

// Funkcja quicksort dla rosnącego porządku
void quicksortRosnaco(int tab[], int lewy, int prawy) {
    if (lewy >= prawy) return;
    int pivot = tab[prawy];
    int i = lewy - 1;
    for (int j = lewy; j < prawy; j++) {
        if (tab[j] <= pivot) {
            i++;
            int temp = tab[i]; tab[i] = tab[j]; tab[j] = temp;
        }
    }
    int temp = tab[i+1]; tab[i+1] = tab[prawy]; tab[prawy] = temp;
    int p = i+1;
    quicksortRosnaco(tab, lewy, p-1);
    quicksortRosnaco(tab, p+1, prawy);
}

// Funkcja quicksort dla malejącego porządku
void quicksortMalejaco(int tab[], int lewy, int prawy) {
    if (lewy >= prawy) return;
    int pivot = tab[prawy];
    int i = lewy - 1;
    for (int j = lewy; j < prawy; j++) {
        if (tab[j] >= pivot) {
            i++;
            int temp = tab[i]; tab[i] = tab[j]; tab[j] = temp;
        }
    }
    int temp = tab[i+1]; tab[i+1] = tab[prawy]; tab[prawy] = temp;
    int p = i+1;
    quicksortMalejaco(tab, lewy, p-1);
    quicksortMalejaco(tab, p+1, prawy);
}

int main() {
    int tablica[] = {5, 2, 9, 8, 4, 7, 6, 1, 3};
    int n = sizeof(tablica)/sizeof(tablica[0]);

    // Liczymy ile jest parzystych i nieparzystych
    int liczParz = 0, liczNieparz = 0;
    for (int i = 0; i < n; i++) {
        if (tablica[i] % 2 == 0) liczParz++;
        else liczNieparz++;
    }

    int parzyste[liczParz], nieparzyste[liczNieparz];
    int p = 0, np = 0;

    // Rozdzielamy liczby
    for (int i = 0; i < n; i++) {
        if (tablica[i] % 2 == 0) parzyste[p++] = tablica[i];
        else nieparzyste[np++] = tablica[i];
    }

    // Sortujemy parzyste malejąco, nieparzyste rosnąco
    if (p > 0) quicksortMalejaco(parzyste, 0, p-1);
    if (np > 0) quicksortRosnaco(nieparzyste, 0, np-1);

    // Wypisanie w jednej linii: najpierw parzyste, potem nieparzyste
    for (int i = 0; i < p; i++) cout << parzyste[i] << " ";
    for (int i = 0; i < np; i++) cout << nieparzyste[i] << " ";
    cout << endl;

    return 0;
}


    // Sortowanie
    if (p > 0) quicksortMalejaco(parzyste, 0, p-1);
    if (np > 0) quicksortRosnaco(nieparzyste, 0, np-1);

    // Wypisanie w jednej linii
    for (int i = 0; i < p; i++) cout << parzyste[i] << " ";
    for (int i = 0; i < np; i++) cout << nieparzyste[i] << " ";
    cout << endl;

    return 0;
}

