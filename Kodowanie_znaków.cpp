// Char:
// Przykład 1:
#include <iostream>
using namespace std;

int main() {
    char znak = 'A';
    cout << znak << endl;  // wyświetli: A
    cout << int(znak) << endl; // wyświetli: 65 (kod ASCII)
}
// Przykład 2:
#include <iostream>
using namespace std;

int main() {
    char tab[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    cout << tab << endl; // Hello
}

// Przykład 3:
#include <iostream>
using namespace std;

int main() {
    char litera = 'C';
    int kod = int(litera); // 67
    cout << "Znak: " << litera << ", Kod ASCII: " << kod << endl;

    int liczba = 100;
    char znak = char(liczba); // 'd'
    cout << "Liczba: " << liczba << ", Znak: " << znak << endl;
}
// Wynik:
Znak: C, Kod ASCII: 67
Liczba: 100, Znak: d




