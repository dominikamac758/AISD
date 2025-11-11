// Silnia iteracyjnie:
#include<iostream>
using namespace std;
int main()
{
  int N;
  cout<<"N: "; cin>>N;
  if(N>=0)
  {
    long long s=1;
    for( int i=1; i<=N; i++)
     {
       s*=i;
     }
     cout<<"Silnia = "<<s<<endl;
  }
  else
  cout<<"N musi być nieujemne"<<endl;
}

// Fibonacci iteracyjnie do while:
#include<iostream>
using namespace std;

int fib( int liczba)
{
    if(liczba==0)
    return 1;
    
    int poprzednia=1, nastepna=1;
    do{
        int temp=nastepna;
        nastepna+=poprzednia;
        poprzednia=temp;
        
        
    }while(liczba>=nastepna);
    
   return nastepna;
}

int main()
{
    int liczba;
    cout<<"Podaj wartość: "; cin>>liczba;
    if(liczba<0)
      cout<<"Wartość nie może być ujemna"<<endl;
    else
      cout<<"Następny wyraz ciągu to "<<fib(liczba);
      
    return 0;
}

// Fibonacci kolejne wyrazy do podanego:
#include<iostream>
using namespace std;

int main()
{
    int liczba;
    cout<<"Podaj wartość: "; cin>>liczba;
    if(liczba<0)
      cout<<"Wartość nie może być ujemna"<<endl;
    else
     {
         cout<<"Kolejne wyrazy ciągu to ";
         if(liczba==0)
         return 1;
    
         int poprzednia=0, nastepna=1;
         while(liczba>=nastepna)
          {
            int temp=nastepna;
            nastepna+=poprzednia;
            poprzednia=temp;
            cout<<temp<<" ";
          }
     } 
    return 0;
}

// suma liczb od 1 do n:
#include<iostream>
using namespace std;

int main()
{
    int n, suma=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        suma+=i;
    }
    cout<<suma;
    return 0;
}
// lub wzorkiem:
#include<iostream>
using namespace std;
int main()
{
    int n, suma=0;
    cin>>n;
    suma=n*(n+1)/2;
    cout<<suma;
    return 0;
}
// suma cyfr liczby:
#include<iostream>
using namespace std;

int main()
{
    int n, suma=0;
    cin>>n;
    while(n>0)
    {
       suma+=n%10;
       n=n/10; 
    }
    cout<<suma;
    return 0;
}

// iloczyn cyfr liczby:
#include<iostream>
using namespace std;

int main()
{
    int n, iloczyn=1;
    cin>>n;
    while(n>0)
    {
       iloczyn*=n%10;
       n=n/10; 
    }
    cout<<iloczyn;
    return 0;
}

// sprawdzenie czy liczba jest pierwsza:
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    
    cout<<"N: ";cin>>n;
    
    if(n==1 | n==0)
    {
      cout<<"Liczba nie jest liczbą ani pierwszą ani złożoną"<<endl;
    }
    else
    {
        bool pierwsza=true;
        for(int i=2; i<=sqrt(n); i++)
        {
            if(n%i==0)
            {
              pierwsza=false;
              break;
            }
        }
        
        if(pierwsza)
          cout<<"Liczba jest liczbą pierwszą"<<endl;
        else
          cout<<"Liczba jest liczbą złożoną"<<endl;
    }
}

// wypisywanie wszystkich liczb pierwszych do podanej wartości:
#include<iostream>
using namespace std;

int main()
{
    int N;
    cout<<"N: "; cin>>N;
    int *tab=new int[N];
    
    for(int i=1; i<=N; i++)
    {
        tab[i]=1;
    }
    
    for(int i=2; i<=N; i++ )
    {
        if(tab[i]!=0)
        {
    
        for(int j=2*i; j<=N; j+=i)
          {
            tab[j]=0;
          }
        }
    }
    
    cout<<"Liczby pierwsze do "<<N<<" to: ";
    for(int i=2; i<=N;i++)
    {
       if(tab[i]==1)
         cout<<i<<" ";
    }
    
    delete [] tab;
    
    return 0;
}

// NWD (największy wspólny dzielnik:
#include<iostream>
using namespace std;

int main()
{
    int a, b, wynik;
    cout<<"Podaj liczbę naturalną a: "; cin>>a;
    cout<<"Podaj liczbę naturalną b: "; cin>>b;
    cout<<"Największy wspólny dzielnik liczb "<<a<<" i "<<b<<" to ";
    while(a!=b)
    {
      if(a>b)
       a=a-b;
      else
       b=b-a;
    }
    cout<<a<<"."<<endl;
    
    
    return 0;
}

// NWW (najmniejsza wspólna wielokrotność:
#include<iostream>
using namespace std;

int nwd1(int a, int b)
{
     while(a!=b)
    {
      if(a>b)
       a=a-b;
      else
       b=b-a;
    }
    return a;
}


int main()
{
    int a,b, nwd;
    cout<<"Podaj liczbę naturalną a: "; cin>>a;
    cout<<"Podaj liczbęnaturalną b: "; cin>>b;
    cout<<"Najmniejsza wspólna wielokrotność liczb "<<a<<" i "<<b<<" to "<<(a*b)/nwd1(a,b)<<".";
   
    
    return 0;
}

// zliczanie ilości cyfr w liczbie:
#include<iostream>
using namespace std;

int main()
{
    int n, licznik=0;
    cin>>n;
    while(n>0)
    {
       n=n/10; 
       licznik++;
    }
    cout<<licznik;
    return 0;
}

// najmniejsza cyfra liczby:
#include<iostream>
using namespace std;

int main()
{
    int n, a;
    cin>>n;
    int minimum=9;
    while(n>0)
    {
       a=n%10;
       n=n/10; 
       if(minimum>a)
       {
         minimum=a;
       }
       
    }
    cout<<minimum;
    return 0;
}
// analogicznie największa cyfra liczby:
#include<iostream>
using namespace std;

int main()
{
    long long n, a;
    cin>>n;
    int maximum=0;
    while(n>0)
    {
       a=n%10;
       n=n/10; 
       if(maximum<a)
       {
         maximum=a;
       }
       
    }
    cout<<maximum;
    return 0;
}
// palindrom:
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tekst;
    cout << "Ciąg znaków: "; 
    getline(cin, tekst);

    string nowy_tekst="";
    for (char c : tekst)
    {
        if (c != ' ') 
            nowy_tekst += c;
    }

   
    int d = nowy_tekst.length();
    bool palindrom = true;

    for (int i = 0; i < d / 2; i++)
    {
        if (nowy_tekst[i] != nowy_tekst[d - 1 - i])
        {
            palindrom = false;
            break;
        }
    }

 
    if (palindrom)
        cout << "Ciąg \"" << tekst << "\" jest palindromem";
    else
        cout << "Ciąg \"" << tekst << "\" nie jest palindromem";

    return 0;
}
// palindrom liczby:
//sposob 1:
#include <iostream>
using namespace std;

int main() {
    int liczba;
    cout << "Podaj liczbę: ";
    cin >> liczba;

    int oryginalna = liczba;
    int odwrocona = 0;

    while (liczba > 0) {
        int cyfra = liczba % 10;
        odwrocona = odwrocona * 10 + cyfra;
        liczba /= 10;
    }

    if (oryginalna == odwrocona)
        cout << oryginalna << " jest palindromem." << endl;
    else
        cout << oryginalna << " nie jest palindromem." << endl;

    return 0;
}
// sposób 2:
#include <iostream>
#include <string>
using namespace std;

int main() {
    int liczba;
    cout << "Podaj liczbę: ";
    cin >> liczba;

    string str = to_string(liczba);
    bool palindrom = true;

    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - 1 - i]) {
            palindrom = false;
            break;
        }
    }

    if (palindrom)
        cout << liczba << " jest palindromem." << endl;
    else
        cout << liczba << " nie jest palindromem." << endl;

    return 0;
}

// odwracanie liczby:
#include <iostream>
using namespace std;

int main() {
    long long liczba;
    cout << "Podaj liczbę: ";
    cin >> liczba;

    int oryginalna = liczba;
    int odwrocona = 0;
    while(liczba%10==0)
    {
        cout<<"0";
        liczba/=10;
    }
        while (liczba > 0) 
        {
        int cyfra = liczba % 10;
        odwrocona = odwrocona * 10 + cyfra;
        liczba /= 10;
        }

    cout<<odwrocona;

    return 0;
}

// znajdowanie wszsytkich dzielników liczby:
#include<iostream>

using namespace std;

int main()
{
  int a;
  cin>>a;
  for(int i=1; i<=a; i++)
  {
      if(a%i==0)
       cout<<i<<" ";
  }
  
  return 0;  
}

// znajdowanie wszystkich dzielników liczby z tablicą dynamiczną:
#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Podaj liczbe: ";
    cin >> a;

    int* dzielniki = new int[a];
    int licznik = 0;

    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0)
        {
            dzielniki[licznik] = i;
            licznik++;
        }
    }
    
    for (int i = 0; i < licznik; i++)
        cout << dzielniki[i] << " ";
    cout << endl;

    delete[] dzielniki;

    return 0;
}

// ciąg arytmetyczny - liczenie sumy:

S=( a1 + an ) /2 * n;

// ciąg geometryczny - liczenie sumy:

S= a1 *  (1-q^n) / (1-q)

// sumowanie liczb parzystych i nieparzystych:
#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Podaj liczbe: ";
    cin >> a;
    int s_p=0, s_np=0;
    for(int i=1; i<=a; i++)
    {
        if(i%2==0)
          s_p+=i;
          
        else
          s_np+=i;
        
    }
    
    cout<<"Suma parzystych: "<<s_p<<endl;
    cout<<"Suma nieparzystych: "<<s_np;
    

    return 0;
}

// liczby parzyste/nieparzyste:
#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "N: ";
    cin >> a;
    int *tab= new int[a];
    for(int i=0; i<a; i++)
    {
        cin>>tab[i];
    }
    
    int s_p=0, s_np=0;
    for(int i=0; i<a; i++)
    {
        if(tab[i]%2==0)
          s_p+=tab[i];
          
        else
          s_np+=tab[i];
        
    }
    
    cout<<"Suma parzystych: "<<s_p<<endl;
    cout<<"Suma nieparzystych: "<<s_np;
    
    delete [] tab;
    return 0;
}

// liczby parzyste/nieparzyste - podział:
#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "N: ";
    cin >> a;
    int * tab= new int[a];
    int *parzyste= new int[a];
    int *nieparzyste= new int[a];
    for(int i=0; i<a; i++)
    {
        cin>>tab[i];
    }
    int licznik_p=0, licznik_np=0;
    for(int i=0; i<a; i++)
    {
        if(tab[i]%2==0)
        {
          parzyste[licznik_p]=tab[i];
        
          licznik_p++;  
        }  
        else
        {
          nieparzyste[licznik_np]=tab[i];
        
          licznik_np++;  
        }
        
    }
    
    cout<<"Liczby parzyste: ";
    for(int i=0; i<licznik_p; i++)
    {
        cout<<parzyste[i]<<" ";
    }
    
    cout<<endl;
    
    cout<<"Liczby nieparzyste: ";
    for(int i=0; i<licznik_np; i++)
    {
        cout<<nieparzyste[i]<<" ";
    }
    
    delete [] parzyste;
    delete [] nieparzyste;
    delete [] tab;
    return 0;
}

// suma kwadratów liczb od 1 do N:
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Podaj N: ";
    cin >> n;

    long long suma = 0;

    for (int i = 1; i <= n; i++)
    {
            suma += i * i; 
    }

    cout << "Suma = " << suma << endl;

    return 0;
}

// liczenie długości stringa:
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string napis;
    cout << "Podaj napis: ";
    getline(cin, napis);  // wczytuje całą linie ze spacjami!

    cout << "Dlugosc napisu: " << napis.length() << endl;

    return 0;
}

// odwracanie stringa:
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tekst;
    cout << "Podaj napis: ";
    getline(cin, tekst);

    cout << "Odwrocony napis: ";
    for (int i = tekst.length() - 1; i >= 0; i--)
    {
        cout << tekst[i];
    }

    cout << endl;
    return 0;
}

// konwersja na małe litery:
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string tekst;
    int wybor;
    cout<<"Tekst: ";
    getline(cin, tekst);
    
        for(char &nowy_tekst : tekst)
        {
          if(nowy_tekst>='A' && nowy_tekst<='Z')
          {
            nowy_tekst=nowy_tekst+('a'-'A');
          }
        }
        cout<<tekst;
        
        return 0;
}

// konwersja na duże litery:
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string tekst;
    int wybor;
    cout<<"Tekst: ";
    getline(cin, tekst);
    
        for(char &nowy_tekst : tekst)
        {
          if(nowy_tekst>='a' && nowy_tekst<='z')
          {
            nowy_tekst=nowy_tekst-('a'-'A');
          }
        }
        cout<<tekst;
        
        return 0;
}

// Liczenie samogłosek:
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string tekst;
    int suma=0;
    cout<<"Tekst: ";
    getline(cin, tekst);
    
        for(char &znak : tekst)
        {
          if(znak == 'a' || znak == 'e' || znak == 'i' || znak == 'o' || znak == 'u' ||
              znak == 'y' || znak == 'A' || znak == 'E' || znak == 'I' || znak == 'O' ||
               znak == 'U' || znak == 'Y')
          {
            suma+=1;
          }
          else
           suma+=0;
        }
        cout<<suma;
        
        return 0;
}

// wypisywanie samogłosek:
// tablica zwykła:
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tekst;
    cout << "Podaj tekst: ";
    getline(cin, tekst);

    char samogloski[] = {'a','e','i','o','u','y',
                         'A','E','I','O','U','Y'};

    char wynik[100]; 
    int licznik = 0;

    for (char znak : tekst)
    {
        for (char s : samogloski)
        {
            if (znak == s)
            {
                wynik[licznik++] = znak; 
                break;
            }
        }
    }

    wynik[licznik] = '\0';

    cout << "Znalezione samogloski: " << wynik << endl;

    return 0;
}

// tablica dynamiczna:
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tekst;
    cout << "Podaj tekst: ";
    getline(cin, tekst);
    int a=tekst.length();
    char samogloski[] = {'a','e','i','o','u','y',
                         'A','E','I','O','U','Y'};

    char *tab= new char[a]; 
    int licznik = 0;

    for (char znak : tekst)
    {
        for (char s : samogloski)
        {
            if (znak == s)
            {
                tab[licznik] = znak; 
                licznik++;
                break;
            }
        }
    }
    cout << "Znalezione samogloski: ";
    
    for(int i=0; i<licznik; i++)
    {
        cout<<tab[i]<<" ";
    }
    
    delete [] tab;
    return 0;
}

// znajdowanie konkretnego znaku w stringu:
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tekst;
    cout << "Podaj tekst: ";
    getline(cin, tekst);
    int a=tekst.length();
    char szukane;
    cout<<"Szukany znak: ";
    cin>>szukane;

    int licznik = 0;

    for (char znak : tekst)
    {
            if (znak == szukane)
            {
                licznik++;
            }
    }
    cout << "Znaleziony znak \'"<<szukane<<"\' znajduje się w podanym tekście "<<licznik<<" razy";
    
    return 0;
}

// zmiana danego znaku w stringu na inny:
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string tekst;
    cout<<"Podaj tekst: ";
    getline(cin, tekst);
    
    char znak;
    cout<<"Jaki znak chcesz zmienić: ";
    cin>>znak;
    
    char zmieniony;
    cout<<"Na jaki chcesz go zmienić: ";
    cin>>zmieniony;
    
    for(char &t : tekst)
    {
       if(t==znak)
       {
           t=zmieniony;
       }
       else
        continue;
    }
    
    cout<<"Zmieniony tekst: "<<endl<<tekst<<endl;
    return 0;
}









