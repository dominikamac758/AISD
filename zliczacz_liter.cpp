#include <iostream>
#include<cstring>
#include<string>
using namespace std;

int main() {
    
    int N;
    cin>>N;
    cin.ignore();
    
    string napis, nowy="";
    
    for(int i=0; i<N; i++)
    {
     getline(cin, napis);
     nowy+=napis;
    }
    char litera[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0; i<sizeof(litera); i++)
    {
     int licznik=0;
     for(char c : nowy)
     {
        if(c==litera[i])
        licznik++;
     }
    if(licznik!=0)
    cout<<litera[i]<<" "<<licznik<<'\n';
    }
    return 0;
}
