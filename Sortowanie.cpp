#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

void wypisz(int *tab, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

void sort_babelkowe(int *tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++) 
        {
            if (tab[j] > tab[j + 1])
            {
                swap(tab[j], tab[j + 1]);
            }
        }
    }
}

void sort_przez_wstawianie(int *tab, int n) 
{
    for (int i = 1; i < n; i++)
    {   
        int temp = tab[i];         
        int j = i - 1;

        while (j >= 0 && tab[j] > temp)
        {
            tab[j + 1] = tab[j];     
            j--;
        }
        
        tab[j + 1] = temp;         
    }
}

void sort_przez_wybieranie(int *tab, int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        int min = i;  
        for (int j = i + 1; j < n; j++)
        {
            if (tab[j] < tab[min])
            {
                min = j;
            }
        }
            swap(tab[i], tab[min]); 
    }
}
void scal(int *tab, int lewy, int srodek, int prawy)
{
    int n1 = srodek - lewy + 1;
    int n2 = prawy - srodek;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = tab[lewy + i];
    for (int j = 0; j < n2; j++)
        R[j] = tab[srodek + 1 + j];

    int i = 0, j = 0, k = lewy;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) tab[k++] = L[i++];
        else tab[k++] = R[j++];
    }

    while (i < n1) tab[k++] = L[i++];
    while (j < n2) tab[k++] = R[j++];
}
void sort_przez_scalanie(int *tab, int lewy, int prawy)
{
    if (lewy < prawy) {
        int srodek = lewy + (prawy - lewy) / 2;
        sort_przez_scalanie(tab, lewy, srodek);
        sort_przez_scalanie(tab, srodek + 1, prawy);
        scal(tab, lewy, srodek, prawy);
    }
}

void kopcuj(int *tab, int n, int i) {
    int najwiekszy = i;       
    int lewy = 2 * i + 1;     
    int prawy = 2 * i + 2;    

    if (lewy < n && tab[lewy] > tab[najwiekszy])
        najwiekszy = lewy;
        
    if (prawy < n && tab[prawy] > tab[najwiekszy])
        najwiekszy = prawy;

    if (najwiekszy != i) 
    {
        swap(tab[i], tab[najwiekszy]);
        kopcuj(tab, n, najwiekszy);
    }
}

void sort_stogowe(int *tab, int n) 
{
    
    for (int i = n / 2 - 1; i >= 0; i--)
        kopcuj(tab, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(tab[0], tab[i]);   
        kopcuj(tab, i, 0);     
    }
}

void sort_szybkie(int *tab, int min, int max) {
    int i = min; //(i=lewo)
    int j = max; // (j=prawo)

    int srodek = tab[(min + max) / 2];

    while (i <= j) {
        while (tab[i] < srodek) i++;
        while (tab[j] > srodek) j--;

        if (i <= j) {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }

    if (min < j) sort_szybkie(tab, min, j);
    if (max > i) sort_szybkie(tab, i, max);
}

int main()
{
    int n=10;
    int tab[]={1, 6, 3, 8, 7, 2, 9, 0, 5, 4};
    string metoda;
    cin>>metoda;
    cout<<"Przed sortowaniem: "; 
    wypisz(tab, n);
    
    cout<<"Po sortowaniu: ";

    if(metoda=="babelkowe")
    {
       sort_babelkowe(tab, n);
       
    }else if (metoda=="wstawianie"){
        
        sort_przez_wstawianie(tab, n);
        
    }else if (metoda =="wybieranie"){
        
        sort_przez_wybieranie(tab, n);
        
    }else if(metoda =="scalanie"){
        
        sort_przez_scalanie(tab, 0, n-1);
        
    }else if(metoda=="stogowe"){
        
        sort_stogowe(tab, n);
        
    }else if(metoda=="szybkie"){
        
        sort_szybkie(tab, 0, n-1);
        
    }else
      cout<<"Nie ma takiej metody"<<endl;
    
    wypisz(tab, n);
    
  
    return 0;
}

