
/* enter the value of n8
 1
 2 3
 3 4 5
 4 5 6 7
 5 6 7 8 9
 6 7 8 9 10 11
 7 8 9 10 11 12 13
 8 9 10 11 12 13 14 15
*/ 
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
        int p=i;
        while (j <= i)
        {
           
            cout<<" "<< p;
            p++;
            j++;
        }
        i++;
        cout << "\n";
    }

    // cout << "Hello World!";
    return 0;
}