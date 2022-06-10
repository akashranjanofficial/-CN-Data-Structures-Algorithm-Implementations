#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"enter the value of n";
    cin>>n;
    int i=1;
    while(i<=n)
    {
        int j=1;
        char start ='A'+i-1;
        while (j<=n)
        {
            char ch = start + j-1;
           cout<<ch;
           
           
           j++;
           
        }
        i++;
        cout<<"\n";

        
    }
    
   // cout << "Hello World!";
    return 0;
}
