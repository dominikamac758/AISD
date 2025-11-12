// Dzień tygodnia:
#include<iostream>

using namespace std;

int main()
{
    int dzien;
    cout<<"Podaj dzień: ";
    cin>>dzien;
    
    switch(dzien){
        case 1: cout<<"Poniedziałek";
        break;
        case 2: cout<<"Wtorek";
        break;
        case 3: cout<<"Środa";
        break;
        case 4: cout<<"Czwartek";
        break;
        case 5: cout<<"Piątek";
        break;
        case 6: cout<<"Sobota";
        break;
        case 7: cout<<"Niedziela";
        break;
        default:
         cout<<"Dzień musi być w zakresie od 1 do 7"<<endl;
    }
    return 0;
}

// Suma z przedziału dla podzielnych przez 6 i 7:
#include<iostream>

using namespace std;

int main()
{
    int a, b, suma=0;
    cout<<"Podaj a: "; cin>>a;
    if(a<0)
      cout<<"Liczba a musi być nieujemna"<<endl;
    else
    {
       cout<<"Podaj b: "; cin>>b;
         if(b<0)
           cout<<"Liczba b musi być nieujemna"<<endl;
         else
          {
            if(a>b)
             cout<<"Liczba a musi być mniejsza niż b"<<endl;
            else
            {
               for(int i=a; i<=b; i++)
               {
                 if(i%6==0 || i%7==0)
                  suma+=i;
                 else
                  suma+=0;
               }
               cout<<"Suma wynosi "<<suma<<endl;
           }
    }
    
    }
    return 0;
}

// Funkcja czy pierwsza:
#include<iostream>

using namespace std;

bool czy_pierwsza(int n)
{
  
  if(n<2) return false;
 
      for(int i=2; i*i<=n; i++)
      {
          if(n%i==0)
          return false;
      }
  return true;
}


int main()
{
    int n;
    cin>>n;
    if(czy_pierwsza(n))
     cout<<"Jest liczbą pierwszą"<<endl;
    else
     cout<<"Nie jest liczbą pierwszą"<<endl;
    return 0;
}


// Rysowanie ramki:
#include<iostream>

using namespace std;

int main()
{
    int N, M;
    cout<<"Podaj wysokość: "; cin>>N;
    if(N<3)
    {
        cout<<"Wysokość musi być większa lub równa 3"<<endl;
    }
    else
    {
        cout<<"Podaj szerokość: "; cin>>M;
        if(M<3)
        {
            cout<<"Szerokość musi być większa lub równa 3"<<endl;
        }
        else
        {
            for(int i=1; i<=N; i++)
            {
                for(int j=1; j<=M; j++)
                {
                    if(i==1 || i==N || j==1 || j==M)
                    {
                        cout<<"*";
                    }
                    else
                        cout<<" ";
                }
              cout<<endl;
            }
        }
        
    }
    
}
// Funkcja do wypisywania kolumnami od końca tablicy dynamicznej z miejscami co 3:



