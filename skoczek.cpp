#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int **board;
int N;

int moveX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int moveY[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

bool isSafe(int x, int y) {
    return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == 0);
}

bool solveKTUtil(int x, int y, int moveCount) {
    if (moveCount == N * N + 1)
        return true;

    for (int i = 0; i < 8; i++) {
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];

        if (isSafe(nextX, nextY)) {
            board[nextX][nextY] = moveCount;

            if (solveKTUtil(nextX, nextY, moveCount + 1))
                return true;

            board[nextX][nextY] = 0;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Uzycie: ./skoczek.exe <N> <W> <K>\n";
        return 1;
    }

    N = atoi(argv[1]);
    int W = atoi(argv[2]) - 1; 
    int K = atoi(argv[3]) - 1;


    board = new int*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N];
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    }

    
    board[W][K] = 1;

    if (!solveKTUtil(W, K, 2)) {
        cout << "Brak rozwiazania.\n";
        return 1;
    }

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << setw(4) << board[i][j] << " ";
        cout << "\n";
    }

    
    for (int i = 0; i < N; i++)
        delete[] board[i];
    delete[] board;

    return 0;
}
