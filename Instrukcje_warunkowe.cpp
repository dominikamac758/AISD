// Instrukcje warunkowe:

// 1. IF:
#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    if (x > 0)
        cout << "Dodatnia";
    else if (x < 0)
        cout << "Ujemna";
    else
        cout << "Zero";

    return 0;
}

// Składnia:
if (warunek1) {
    // kod gdy warunek1 jest prawdziwy
} else if (warunek2) {
    // kod gdy warunek1 jest fałszywy, a warunek2 prawdziwy
} else if (warunek3) {
    // kod gdy warunek1 i warunek2 są fałszywe, a warunek3 prawdziwy
} else {
    // kod gdy wszystkie powyższe warunki są fałszywe
}

// SWITCH:
#include <iostream>
using namespace std;

int main() {
    char znak;
    double a, b;
    cout << "Podaj operator: ";
    cin >> znak;
    cout << "Podaj dwie liczby: ";
    cin >> a >> b;

    switch (znak) {
        case '+': cout << a + b; break;
        case '-': cout << a - b; break;
        case '*': cout << a * b; break;
        case '/': cout << a / b; break;
        default:  cout << "Niepoprawny operator"; break;
    }
}
// Składnia:
switch (wyrazenie) {
    case wartosc1:
        // kod wykonywany, gdy wyrazenie == wartosc1
        break;

    case wartosc2:
        // kod wykonywany, gdy wyrazenie == wartosc2
        break;

    // ... kolejne case ...

    default:
        // kod wykonywany, gdy żadna wartość nie pasuje
        break;
}

//  PĘTLA FOR:
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    return 0;
}

// Pętla z wieloma zmiennymi:

for (int i = 0, j = 10; i <= 5; i++, j--) {
    cout << "i=" << i << " j=" << j << endl;
}

// Składnia:
for (inicjalizacja; warunek; inkrementacja) {
    // kod do wielokrotnego wykonania
}

// PĘTLA WHILE:
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    while (i < 5) {
        cout << i << " ";
        i++;  // ważne, inaczej pętla będzie nieskończona
    }
    return 0;
}

// Składnia:
while (warunek) {
    // kod do wielokrotnego wykonania
}

// PĘTLA DO WHILE:
int x;
do {
    cout << "Podaj liczbę > 0: ";
    cin >> x;
} while (x <= 0);

// Składnia:
do {
    // kod do wykonania
} while (warunek);


// BOOL:
bool czyDodatnia(int x) {
    return x > 0;
}

int main() {
    int a = 5;
    if (czyDodatnia(a))
        cout << "Liczba dodatnia";
    else
        cout << "Liczba niedodatnia";
}

// Przechowuje prawdę lub fałsz:

#include <iostream>
using namespace std;

int main() {
    bool b1 = true;
    bool b2 = false;

    cout << b1 << " " << b2;
}
// WYpisze 1 0





