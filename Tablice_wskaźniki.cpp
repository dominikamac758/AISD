// Inicjalizacja tablicy dynamicznej jedowymiarowej i wypełnienie jej kolejnymi liczbami:
#include<iostream>

using namespace std;

int main()
{
    int N;
    cout<<"N: ";
    cin>>N;
    int licznik=1;
    int *tab=new int[N];
    
    for(int i=0; i<N; i++)
    {
        tab[i]=licznik;
        licznik++;

    }
    
    for(int i=0; i<N; i++)
    {
       cout<<tab[i]<<" ";
    }
    
       delete [] tab;
    return 0;
}

//Inicjalizacja tablicy dynamicznej dwuwymiarowej i wypełnienie jej kolejnymi liczbami:
#include<iostream>

using namespace std;

int main()
{
    int W, K;
    cout<<"W: ";
    cin>>W;
    cout<<"K: ";
    cin>>K;
    int licznik=1;
    int **tab=new int*[W];
    for(int i=0; i<W; i++)
    {
        tab[i]=new int[K];
    }
    
    for(int i=0; i<W; i++)
    {
        for(int j=0; j<K; j++)
        {
            tab[i][j]=licznik;
            licznik++;
        }
    }
    
    for(int i=0; i<W; i++)
    {
        for(int j=0; j<K; j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for(int i=0; i<W; i++)
      delete [] tab[i];
       delete [] tab;
    return 0;
}




