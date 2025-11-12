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



