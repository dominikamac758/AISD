#include <iostream>
#include <iomanip>
using namespace std;

void szukajKwadratu(int n, int* kwadrat = nullptr, bool* uzyte = nullptr, int* sumaWiersza = nullptr, int* sumaKolumny = nullptr, int sumaPrzek1 = 0, int sumaPrzek2 = 0, int pozycja = 0, long long* ileRozwiazan = nullptr, int maksRozwiazan = -1) {
    if (!kwadrat) {
        // inicjalizacja przy pierwszym wywołaniu
        int nn = n * n;
        kwadrat = new int[nn];
        uzyte = new bool[nn + 1];
        sumaWiersza = new int[n];
        sumaKolumny = new int[n];

        for (int i = 0; i < nn; i++) kwadrat[i] = 0;
        for (int i = 0; i <= nn; i++) uzyte[i] = false;
        for (int i = 0; i < n; i++) sumaWiersza[i] = 0;
        for (int i = 0; i < n; i++) sumaKolumny[i] = 0;

        long long lokalneRozw = 0;
        ileRozwiazan = &lokalneRozw;
    }

    int nn = n * n;
    int sumaDocelowa = n * (nn + 1) / 2;

    if (*ileRozwiazan == maksRozwiazan && maksRozwiazan != -1) return;

    if (pozycja == nn) {
        (*ileRozwiazan)++;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) cout << setw(4) << kwadrat[r * n + c];
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for (int wart = 1; wart <= nn; wart++) {
        if (uzyte[wart]) continue;

        int r = pozycja / n;
        int c = pozycja % n;
        int nowyWiersz = sumaWiersza[r] + wart;
        int nowaKolumna = sumaKolumny[c] + wart;
        if (nowyWiersz > sumaDocelowa || nowaKolumna > sumaDocelowa) continue;
        if (c == n - 1 && nowyWiersz != sumaDocelowa) continue;
        if (r == n - 1 && nowaKolumna != sumaDocelowa) continue;
        if (r == c && (sumaPrzek1 + wart > sumaDocelowa || (r == n-1 && sumaPrzek1 + wart != sumaDocelowa))) continue;
        if (r + c == n-1 && (sumaPrzek2 + wart > sumaDocelowa || (r == n-1 && sumaPrzek2 + wart != sumaDocelowa))) continue;

        kwadrat[pozycja] = wart;
        uzyte[wart] = true;
        sumaWiersza[r] += wart;
        sumaKolumny[c] += wart;
        int dodPrzek1 = (r == c) ? wart : 0;
        int dodPrzek2 = (r + c == n-1) ? wart : 0;

        szukajKwadratu(n, kwadrat, uzyte, sumaWiersza, sumaKolumny, sumaPrzek1 + dodPrzek1, sumaPrzek2 + dodPrzek2, pozycja + 1, ileRozwiazan, maksRozwiazan);

        kwadrat[pozycja] = 0;
        uzyte[wart] = false;
        sumaWiersza[r] -= wart;
        sumaKolumny[c] -= wart;

        if (*ileRozwiazan == maksRozwiazan && maksRozwiazan != -1) break;
    }

    if (pozycja == 0) {
        delete[] kwadrat;
        delete[] uzyte;
        delete[] sumaWiersza;
        delete[] sumaKolumny;
        cout << "Znaleziono rozwiazan: " << *ileRozwiazan << "\n";
    }
}

int main() {
    int n, maks;
    cout << "Podaj N (rozmiar kwadratu N x N): ";
    cin >> n;
    cout << "Maksymalna liczba rozwiązań (-1 = wszystkie): ";
    cin >> maks;
    szukajKwadratu(n, nullptr, nullptr, nullptr, nullptr, 0, 0, 0, nullptr, maks);
    return 0;
}
