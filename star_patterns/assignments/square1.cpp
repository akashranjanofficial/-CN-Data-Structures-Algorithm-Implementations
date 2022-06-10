/*Code : Square Pattern
Send Feedback
Print the following pattern for the given N number of rows.
Pattern for N = 4
4444
4444
4444
4444
*/

#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"enter the value of n";
    cin>>n;
    int i=1;
    int k=4;
    while(i<=n)
    {
        int j=1;
        while (j<=n)
        {
           cout<<k;
           j++;
           
        }
        i++;
        cout<<"\n";

        
    }
    
   // cout << "Hello World!";
    return 0;
}
