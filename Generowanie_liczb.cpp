// Jeśli damy ziarno to dla danego ziarna zawsze będzie ta sama sekwencja liczb:
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    srand(123); // ustawienie ziarna
    cout << rand() << " " << rand() << " " << rand() << endl;
}

// Losowanie liczb pseudolosowych w danym zakresie:
int x = rand() % 100 + 1; // liczba 1-100

// Przykład:
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n = 5;
    int tab[5];
    srand(42); // ustawienie ziarna

    for(int i=0; i<n; i++)
        tab[i] = rand() % 50 + 1; // liczby 1-50

    for(int i=0; i<n; i++)
        cout << tab[i] << " ";
}






