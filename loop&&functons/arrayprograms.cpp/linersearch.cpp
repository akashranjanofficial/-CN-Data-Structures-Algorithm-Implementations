
#include <iostream>
using namespace std;


void linearsearch(int x[], int l, int n)
{ int k=0;
 for (int i = 0; i <= l; i++)
 {
     if (x[i]==n)
     {
         cout<<i<<endl;
         k++;
     }
     
     
 }
 if(k==0)
     {
         cout<<"-1"<<endl;
     }
 
 
 
}
int main()
{
    int l,n;
    cout << "ENTER THE SIZE OF ARRAY l";
    cin>>l;
    cout << "ENTER no in ARRAY ";
    int x[l];
    for (int i = 0; i <=l; i++)
    {
       cin>>x[i];

    }
    cout << "ENTER THE NUMBER YOU WANT TO SEARCH IN  ARRAY N";
    cin>>n;

    linearsearch(x,l,n);

    return 0;
}