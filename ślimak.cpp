// Zwykły ślimak:
#include <iostream>
#include <iomanip>

using namespace std;

void wypelnij(int** tab, int N, int M) {
    int licznik = 1;
    int min_wiersz = 0, max_wiersz = N - 1;
    int min_kolumna = 0, max_kolumna = M - 1;

    while (min_wiersz <= max_wiersz && min_kolumna <= max_kolumna) {
        // W prawo
        for (int i = min_kolumna; i <= max_kolumna; ++i) {
            tab[min_wiersz][i] = licznik++;
        }
        min_wiersz++;

        // W dół
        for (int i = min_wiersz; i <= max_wiersz; ++i) {
            tab[i][max_kolumna] = licznik++;
        }
        max_kolumna--;

        // W lewo
        if (min_wiersz <= max_wiersz) {
            for (int i = max_kolumna; i >= min_kolumna; --i) {
                tab[max_wiersz][i] = licznik++;
            }
            max_wiersz--;
        }

        // W górę
        if (min_kolumna <= max_kolumna) {
            for (int i = max_wiersz; i >= min_wiersz; --i) {
                tab[i][min_kolumna] = licznik++;
            }
            min_kolumna++;
        }
    }
}

int main() {
    int N, M;
    cout << "N: ";
    cin >> N;
    cout << "M: ";
    cin >> M;
    cout<<endl;
    
    int** tab = new int*[N];
    for (int i = 0; i < N; ++i) {
        tab[i] = new int[M];
    }

    wypelnij(tab, N, M);
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << setw(6) << tab[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < N; ++i) {
        delete[] tab[i];
    }
    delete[] tab;

    return 0;
}

// Po kolumnach zygzakiem z góry w dół:
#include <iostream>
#include <iomanip>
using namespace std;

void wypelnij_zygzak(int** tab, int N, int M) {
    int licznik = 1;

    for (int j = 0; j < M; j++) { // iterujemy po kolumnach
        if (j % 2 == 0) {
            // kolumna w dół
            for (int i = 0; i < N; i++)
                tab[i][j] = licznik++;
        } else {
            // kolumna w górę
            for (int i = N - 1; i >= 0; i--)
                tab[i][j] = licznik++;
        }
    }
}

int main() {
    int N, M;
    cout << "N: ";
    cin >> N;
    cout << "M: ";
    cin >> M;

    int** tab = new int*[N];
    for (int i = 0; i < N; i++)
        tab[i] = new int[M];

    wypelnij_zygzak(tab, N, M);

    // wypisanie tablicy
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << setw(4) << tab[i][j];
        cout << endl;
    }

    for (int i = 0; i < N; i++)
        delete[] tab[i];
    delete[] tab;

    return 0;
}
// Zygzakiem prawo-lewo:
#include <iostream>
#include <iomanip>
using namespace std;

void wypelnij_zygzak_wiersze(int** tab, int N, int M) {
    int licznik = 1;

    for (int i = 0; i < N; i++) { // iterujemy po wierszach
        if (i % 2 == 0) {
            // wiersz w prawo
            for (int j = 0; j < M; j++)
                tab[i][j] = licznik++;
        } else {
            // wiersz w lewo
            for (int j = M - 1; j >= 0; j--)
                tab[i][j] = licznik++;
        }
    }
}

int main() {
    int N, M;
    cout << "N: ";
    cin >> N;
    cout << "M: ";
    cin >> M;

    int** tab = new int*[N];
    for (int i = 0; i < N; i++)
        tab[i] = new int[M];

    wypelnij_zygzak_wiersze(tab, N, M);

    // wypisanie tablicy
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << setw(4) << tab[i][j];
        cout << endl;
    }

    for (int i = 0; i < N; i++)
        delete[] tab[i];
    delete[] tab;

    return 0;
}




