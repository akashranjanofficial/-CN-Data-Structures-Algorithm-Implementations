#include <iostream>

using namespace std;
int main()
{
    int n;
    cout << "enter the value of n";
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        int k;
           k=i;
        
        while (j <= i)
        {
           
            cout<<" "<< k;
            k--;
            j++;
        }
        i++;
        cout << "\n";
    }

    // cout << "Hello World!";
    return 0;
}