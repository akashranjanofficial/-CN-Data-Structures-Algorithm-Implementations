/*
 1
12
123
1234 
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
        while (j <= i)
        {
            cout<< j;
            j++;
        }
        i++;
        cout << "\n";
    }

    // cout << "Hello World!";
    return 0;
}