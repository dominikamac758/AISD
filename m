#include <iostream>
using namespace std;

// Zmienne globalne
int sumaPol = 0;                // Suma wartości w jednym „polu” (obszarze)
int liczbaPol = 0;              // Liczba pól w obrębie jednego obszaru
float najlepszySredniStosunek = 0; // Najlepszy stosunek suma/liczba pól
int najlepszaSuma = 0;
int najlepszaLiczbaPol = 0;

bool znalezionoWiecejTychSamych = false;

int szerokosc, wysokosc;
int **mapa;

// Funkcja do wyświetlania liczby w formacie (opcjonalnie)
void wypiszLiczbe(int liczba) {
    int dlugosc = 1;
    if (liczba >= 10)
        dlugosc = 2;
    for (int i = 0; i < 4 - dlugosc; i++)
        cout << " ";

    cout << liczba;
}

// Rekurencyjne sprawdzanie jednego obszaru („pola”) w mapie
void sprawdzPole(int x, int y) {
    sumaPol += mapa[x][y];    // Dodaj wartość pola do sumy
    mapa[x][y] = 0;           // Oznacz pole jako odwiedzone
    liczbaPol++;               // Zwiększ licznik pól w tym obszarze

    // Sprawdź sąsiednie pola (N, S, W, E)
    if (y + 1 < wysokosc && mapa[x][y + 1] > 0) // S
        sprawdzPole(x, y + 1);
    if (y - 1 >= 0 && mapa[x][y - 1] > 0)       // N
        sprawdzPole(x, y - 1);
    if (x - 1 >= 0 && mapa[x - 1][y] > 0)       // W
        sprawdzPole(x - 1, y);
    if (x + 1 < szerokosc && mapa[x + 1][y] > 0) // E
        sprawdzPole(x + 1, y);
}

int main() {
    cin >> wysokosc >> szerokosc;

    mapa = new int*[szerokosc];
    for (int i = 0; i < szerokosc; i++)
        mapa[i] = new int[wysokosc];

    // Wczytanie mapy
    for (int y = 0; y < wysokosc; y++)
        for (int x = 0; x < szerokosc; x++)
            cin >> mapa[x][y];

    // Przechodzimy po wszystkich polach
    for (int y = 0; y < wysokosc; y++) {
        for (int x = 0; x < szerokosc; x++) {
            if (mapa[x][y] > 0) { // Jeśli pole nie jest odwiedzone
                sprawdzPole(x, y);

                float sredniStosunek = (float)sumaPol / liczbaPol;

                if (sredniStosunek > najlepszySredniStosunek) {
                    // Znaleziono nowy najlepszy obszar
                    najlepszySredniStosunek = sredniStosunek;
                    najlepszaSuma = sumaPol;
                    najlepszaLiczbaPol = liczbaPol;
                    znalezionoWiecejTychSamych = false;
                } else if (sredniStosunek == najlepszySredniStosunek) {
                    // Znaleziono drugi obszar o tym samym średnim stosunku
                    znalezionoWiecejTychSamych = true;
                }

                // Reset licznika dla następnego obszaru
                sumaPol = 0;
                liczbaPol = 0;
            }
        }
    }

    // Wyświetlanie wyniku
    if (znalezionoWiecejTychSamych)
        cout << -1;                  // Więcej niż jeden najlepszy obszar
    else if (najlepszySredniStosunek == 0)
        cout << 0;                   // Brak dodatnich pól
    else
        cout << najlepszaSuma << " " << najlepszaLiczbaPol << endl;

    // Zwolnienie pamięci
    for (int i = 0; i < szerokosc; i++)
        delete[] mapa[i];
    delete[] mapa;

    return 0;
}
