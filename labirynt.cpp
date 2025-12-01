#include <iostream>
using namespace std;

const int N = 5;

char maze[N][N] = {
    {'1','0','1','1','1'},
    {'1','0','1','0','1'},
    {'1','1','1','0','1'},
    {'0','0','0','0','1'},
    {'1','1','1','1','1'}
};

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == '1');
}

bool solveMazeUtil(int x, int y) {
    // jeśli doszliśmy do końca
    if (x == N-1 && y == N-1) {
        maze[x][y] = '*';
        return true;
    }

    if (isSafe(x, y)) {
        // oznaczamy aktualne pole jako część ścieżki
        maze[x][y] = '*';

        // ruch w prawo
        if (solveMazeUtil(x, y + 1)) return true;
        // ruch w dół
        if (solveMazeUtil(x + 1, y)) return true;
        // ruch w lewo
        if (solveMazeUtil(x, y - 1)) return true;
        // ruch w górę
        if (solveMazeUtil(x - 1, y)) return true;

        // backtracking – jeśli droga nie prowadzi do wyjścia, cofamy oznaczenie
        maze[x][y] = '1';
        return false;
    }

    return false;
}

void printMaze() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    cout << "Labirynt przed rozwiazaniem:" << endl;
    printMaze();

    if (solveMazeUtil(0, 0)) {
        cout << "\nZnaleziono sciezke:" << endl;
        printMaze();
    } else {
        cout << "\nNie ma sciezki!" << endl;
    }

#include <iostream>
using namespace std;

const int ROZMIAR = 5;

int labirynt[ROZMIAR][ROZMIAR] = {
    {1,0,1,1,1},
    {1,0,1,0,1},
    {1,1,1,0,1},
    {0,0,0,0,1},
    {1,1,1,1,1}
};

bool bezpieczne(int x, int y) {
    return (x >= 0 && x < ROZMIAR && y >= 0 && y < ROZMIAR && labirynt[x][y] == 1);
}

bool znajdzSciezke(int x, int y) {
    if (x == ROZMIAR-1 && y == ROZMIAR-1) { // doszlismy do konca
        labirynt[x][y] = 2; // oznaczamy koniec sciezki
        return true;
    }

    if (bezpieczne(x, y)) {
        labirynt[x][y] = 2; // oznaczamy aktualne pole jako czesc sciezki

        // ruch w prawo
        if (znajdzSciezke(x, y + 1)) return true;
        // ruch w dol
        if (znajdzSciezke(x + 1, y)) return true;
        // ruch w lewo
        if (znajdzSciezke(x, y - 1)) return true;
        // ruch w gore
        if (znajdzSciezke(x - 1, y)) return true;

        // backtracking – cofamy oznaczenie
        labirynt[x][y] = 1;
        return false;
    }

    return false;
}

void wypiszLabirynt() {
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            if (labirynt[i][j] == 2) cout << "* ";
            else cout << labirynt[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Labirynt przed rozwiazaniem:" << endl;
    wypiszLabirynt();

    if (znajdzSciezke(0, 0)) {
        cout << "\nZnaleziono sciezke:" << endl;
        wypiszLabirynt();
    } else {
        cout << "\nNie ma sciezki!" << endl;
    }

    return 0;
}

    return 0;
}
