#include <iostream>
using namespace std;
int main()
{
    int i=1;
   
    int n;
    cout<<"enter the value of n";
    cin>>n;
    while(i<=n)
    {
         int k=1;
        while (k<=n-i+1)
        {
           
            cout<<" "<<"*";
            
            
            k++;
            
            
        }
        cout<<endl;

        

        i++;
        
    }
}