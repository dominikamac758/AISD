// Rysowanie:

// choinka v1:
#include<iostream>
using namespace std;

int main()
{
    int w;
    cin>>w;
    for(int i=0; i<w; i++)
    {
        for(int j=0; j<i+1; j++)
        {
            cout<<"*";
        }
        cout<<" "<<endl;
    }
    
    return 0;
}

// Wynik dla 5:
* 
** 
*** 
**** 
***** 

// choinka v2:
#include<iostream>
using namespace std;

int main()
{
    int w;
    cin>>w;
    for(int i=0; i<w; i++)
    {
        for(int j=w; j>i; j--)
        {
            cout<<"*";
        }
        cout<<" "<<endl;
    }
    
    return 0;
}

// Wynik dla 5:
***** 
**** 
*** 
** 
*

// choinka v3:
#include<iostream>
using namespace std;

int main()
{
    int w;
    cin>>w;
    for(int i=1; i<=w; i++)
    {
        for(int k=0; k<w-i; k++)
        {
            cout<<" ";
        }
        for(int j=0; j<i; j++)
        {
          cout<<"*";
        }
      cout<<endl;
    }
    
    return 0;
}

// Wynik dla 5:
    *
   **
  ***
 ****
*****

// choinka v4:
#include<iostream>
using namespace std;

int main()
{
    int w;
    cin>>w;
    for(int i=1; i<=w; i++)
    {
        for(int k=0; k<i-1; k++)
        {
            cout<<" ";
        }
        for(int j=w; j>=i; j--)
        {
          cout<<"*";
        }
      cout<<endl;
    }
    
    return 0;
}
// Wynik dla 5:
*****
 ****
  ***
   **
    *
// choinka v5:
#include<iostream>
using namespace std;

int main()
{
    int w;
    cin>>w;
    for(int i=1; i<=w; i++)
    {
        for(int k=0; k<w-i; k++)
        {
            cout<<" ";
        }
        for(int j=0; j<i*2-1; j++)
        {
          cout<<"*";
        }
      cout<<endl;
    }
    
    return 0;
}
// Wynik dla 5:
    *
   ***
  *****
 *******
*********
// choinka v6:
#include<iostream>
using namespace std;

int main()
{
    int w;
    cin>>w;
    for(int i=1; i<=w; i++)
    {
        for(int k=0; k<w-i; k++)
        {
            cout<<" ";
        }
        for(int j=0; j<i*2-1; j++)
        {
          if(i%2==0)
           cout<<"=";
          else
           cout<<"*";
        }
      cout<<endl;
    }
    
    return 0;
}
// Wynik dla 5:
    *
   ===
  *****
 =======
*********

// choinka v7:
#include<iostream>
using namespace std;

int main()
{
    int w;
    cin>>w;
    for(int i=0; i<w; i++)
    {
        for(int k=0; k<i; k++)
        {
            cout<<" ";
        }
        for(int j=2*w-1; j>2*i; j--)
        {
           cout<<"*";
        }
      cout<<endl;
    }
    
    return 0;
}
// Wynik dla 5:
*********
 *******
  *****
   ***
    *
// x dla w-nieparzystych, dla w-parzystych nie da się narysować:
#include<iostream>
using namespace std;

int main()
{
    int w;
    cin>>w;
    for(int i=1; i<=w; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(i==j || j+i==w+1)
            cout<<"*";
            else
            cout<<" ";
        }
       cout<<endl; 
    }  
    
    return 0;
}
// Wynik dla 5:
*   *
 * * 
  *  
 * * 
*   *

//  +:
#include<iostream>
using namespace std;

int main()
{
    int w;
    cin>>w;
    for(int i=1; i<=w; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(i==w/2+1 || j==w/2+1)
            cout<<"* ";
            else
            cout<<"  ";
        }
       cout<<endl; 
    }  
    
    return 0;
}
// Wynik dla 5:
    *     
    *     
* * * * * 
    *     
    *     
// Ramka:
#include<iostream>
using namespace std;

int main()
{
    int w,k;
    cin>>w>>k;
    for(int i=1; i<=w; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if(i==1 || j==1 || i==w || j==k)
            cout<<"* ";
            else
            cout<<"  ";
        }
       cout<<endl; 
    }  
    
    return 0;
}
// Wynik dla 5X7:
* * * * * * * 
*           * 
*           * 
*           * 
* * * * * * * 
// Środki boków ramki:
#include<iostream>
using namespace std;

int main()
{
    int w;
    cin>>w;
    for(int i=1; i<=w; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(((j==1 || j==w) && i==w/2+1) || ((i==1 || i==w) && j==w/2+1))
            cout<<"* ";
            else
            cout<<"  ";
        }
       cout<<endl; 
    }  
    
    return 0;
}
// Wynik dla 3:
  *   
*   * 
  * 
// Ramka ze środkiem i bez rogów:
#include<iostream>
using namespace std;

int main()
{
    int w, k;
    cin>>w>>k;
    for(int i=1; i<=w; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if((j==k || j==1) && (i==1 || i==w) )
            cout<<" ";
            else
            cout<<"*";
        }
       cout<<endl; 
    }  
    
    return 0;
}
// Wynik dla 5x7;
 ***** 
*******
*******
*******
 ***** 
// Ramka ze środkiem i samymi rogami:
#include<iostream>
using namespace std;

int main()
{
    int w, k;
    cin>>w>>k;
    for(int i=1; i<=w; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if((j<k && j>1) && (i>1 && i<w) || ((i==1 || i==w) && (j==1 || j==k)))
            cout<<"*";
            else
            cout<<" ";
        }
       cout<<endl; 
    }  
    
    return 0;
}
// Wynik dla 5x7:
*     *
 ***** 
 ***** 
 ***** 
*     *
// literka V:
#include<iostream>
using namespace std;

int main()
{
    int w, k;
    cin>>w;
    for(int i=1; i<=w; i++)
    {
        for(int j=1; j<=2*w-1; j++)
        {
            if(i==j || ((i+j)/2==w && (i+j)%2==0))
            cout<<"*";
            else
            cout<<" ";
        }
       cout<<endl; 
    }  
    
    return 0;
}
// Wynik dla 4:
*     *
 *   * 
  * *  
   *  
// Litera V odwrócona:
#include<iostream>
using namespace std;

int main()
{
    int w, k;
    cin>>w;
    for(int i=1; i<=w; i++)
    {
        for(int j=1; j<=2*w-1; j++)
        {
            if(i+j==w+1 || j-i==w-1)
            cout<<"*";
            else
            cout<<" ";
        }
       cout<<endl; 
    }  
    
    return 0;
}
// Wynik dla 4:
   *   
  * *  
 *   * 
*     *
// Zmiana iteracji wierszy dla zwykłej V też da odwróconą:
#include<iostream>
using namespace std;

int main()
{
    int w, k;
    cin>>w;
    for(int i=w; i>=1; i--)
    {
        for(int j=1; j<=2*w-1; j++)
        {
            if(i==j || ((i+j)/2==w && (i+j)%2==0))
            cout<<"*";
            else
            cout<<" ";
        }
       cout<<endl; 
    }  
    
    return 0;
}


