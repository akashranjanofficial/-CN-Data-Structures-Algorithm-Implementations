#include <iostream>
using namespace std;
int main()
{
    int i = 1;

    int n;
    cout << "enter the value of n";
    cin >> n;
    while (i <= n)
    {
        int k = 1;
        while (k <= n - i)
        {
            cout << " ";
            cout << " ";

            k++;
        }
        int j = 1;
        // int m=1;
        while (j <= i)
        {

            cout << "*";
            cout << " ";
            j++;
        }
        j=i-1;
        while (j >=1)
        {

            cout << "*";
            cout << " ";
            j--;
        }
        cout << endl;

        i++;
    }
}