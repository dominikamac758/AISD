#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int **plansza;     
int N;             

int ruchX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int ruchY[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

bool bezpiecznePole(int x, int y) {
    return (x >= 0 && y >= 0 && x < N && y < N && plansza[x][y] == 0);
}

bool znajdzTrase(int x, int y, int numerRuchu) {

    if (numerRuchu == N * N + 1)
        return true;

    
    for (int i = 0; i < 8; i++) {

        int nastepnyX = x + ruchX[i];
        int nastepnyY = y + ruchY[i];

        if (bezpiecznePole(nastepnyX, nastepnyY)) {

            plansza[nastepnyX][nastepnyY] = numerRuchu;

            
            if (znajdzTrase(nastepnyX, nastepnyY, numerRuchu + 1))
                return true;

            
            plansza[nastepnyX][nastepnyY] = 0;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {

    if (argc != 4) {
        cout << "Uzycie: ./skoczek <N> <wiersz> <kolumna>\n";
        return 1;
    }

    N = atoi(argv[1]);
    int startWiersz = atoi(argv[2]) - 1;  
    int startKolumna = atoi(argv[3]) - 1; 

    
    plansza = new int*[N];
    
    for (int i = 0; i < N; i++) {
        plansza[i] = new int[N];
        for (int j = 0; j < N; j++)
            plansza[i][j] = 0;
    }

    plansza[startWiersz][startKolumna] = 1;

    if (!znajdzTrase(startWiersz, startKolumna, 2)) {
        cout << "Brak rozwiazania.\n";
        return 1;
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << setw(4) << plansza[i][j] << " ";
        cout << "\n";
    }

    for (int i = 0; i < N; i++)
        delete[] plansza[i];
    delete[] plansza;

    return 0;
}
