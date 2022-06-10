#include <iostream>
/* n=9;
987654321
987654321
987654321
987654321
987654321
987654321
987654321
987654321
987654321             */

using namespace std;
int main() {
    int n;
    cout<<"enter the value of n";
    cin>>n;
    int i=1;
    while (i<=n)
    {
        int j=1;
        while (j<=n)
        {
           cout<<n-j+1;
           j++;
           
        }
        i++;
        cout<<"\n";

        
    }
    
   // cout << "Hello World!";
    return 0;
}