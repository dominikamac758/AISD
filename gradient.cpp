// gradient
#include <iostream>
#include <fstream>
#include <cstdlib>     // dla atoi
using namespace std;

inline unsigned char S(int w, int k, int WYSOKOSC, int SZEROKOSC) {
    return  w * 255 / (WYSOKOSC-1);
}
inline unsigned char N(int w, int k, int WYSOKOSC, int SZEROKOSC) {
    return  (WYSOKOSC - 1 - w) * 255 / (WYSOKOSC-1);
}
inline unsigned char E(int w, int k, int WYSOKOSC, int SZEROKOSC) {
    return  k * 255 / (SZEROKOSC-1);
}
inline unsigned char W(int w, int k, int WYSOKOSC, int SZEROKOSC) {
    return  (SZEROKOSC - 1 - k) * 255 / (SZEROKOSC-1);
}

inline unsigned char NW(int w, int k, int WYSOKOSC, int SZEROKOSC) {
    return  ((WYSOKOSC - 1 - w) * 255 / (WYSOKOSC-1) + (SZEROKOSC - 1 - k) * 255 / (SZEROKOSC-1)) / 2;
}
inline unsigned char NE(int w, int k, int WYSOKOSC, int SZEROKOSC) {
    return  ((WYSOKOSC - 1 - w) * 255 / (WYSOKOSC-1) + k * 255 / (SZEROKOSC-1)) / 2;
}
inline unsigned char SW(int w, int k, int WYSOKOSC, int SZEROKOSC) {
    return  (w * 255 / (WYSOKOSC-1) + (SZEROKOSC - 1 - k) * 255 / (SZEROKOSC-1)) / 2;
}
inline unsigned char SE(int w, int k, int WYSOKOSC, int SZEROKOSC) {
    return  (w * 255 / (WYSOKOSC-1) + k * 255 / (SZEROKOSC-1)) / 2;
}

int main(int argc, char *argumenty[])
{
    if (argc < 5)
    {
        cerr << "Użycie: " << argumenty[0] << " <szer> <wys> <kierunek> <ścieżka>\n";
        return 1;
    }
    const int WYSOKOSC = atoi(argumenty[2]), SZEROKOSC = atoi(argumenty[1]);
    string kierunek = argumenty[3];
    ofstream plik(argumenty[4], ios::out | ios::binary);
    plik << "P5\n"
         << SZEROKOSC << " " << WYSOKOSC << "\n"
         << "255\n";
    unsigned char (*licz)(int , int , int , int );
    if (kierunek == "N") {
        licz = N;
    } else if (kierunek == "S") {
        licz = S;
    } else if (kierunek == "E") {
        licz = E;
    } else if (kierunek == "W") {
        licz = W;
    } else if (kierunek == "NE") {
        licz = NE;
    } else if (kierunek == "NW") {
        licz = NW;
    } else if (kierunek == "SE") {
        licz = SE;
    } else if (kierunek == "SW") {
        licz = SW;
    } else {
        cerr << "Niepoprawny kierunek\n";
        return 1;
    }

    for (int w = 0; w < WYSOKOSC; ++w)
    {
        for (int k = 0; k < SZEROKOSC; ++k)
        {
            plik.put(licz(w, k, WYSOKOSC, SZEROKOSC));
        }
    }
    plik.close();

    return 0;
}
