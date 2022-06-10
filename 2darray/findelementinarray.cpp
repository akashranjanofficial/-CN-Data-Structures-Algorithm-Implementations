#include <bits/stdc++.h>
using namespace std;

void findelement(int a[][100], int m, int n, int x)
{
    int i = 0; //row==i//column==j;
    int j = n - 1;
    while (j >= 0 && i < m)
    {
        if (x == a[i][j])
        {
            cout << "element found at index: "<< "a[" << i << "]"<< "[" << j << "]" << endl;
            return;
        }
        else if (x > a[i][j])
        {
            i++;
            
        }
        else
            j--;
    }
    cout<< "-1"<<endl;
}



int main()
{
    int a[100][100];
    int m;
    int n;
    cin >> m >> n;
    cout << "enter which no. you want to find";
    int x;
    cin >> x;
    //taking input
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "enter the a[" << i << "]"
                 << "[" << j << "]"
                 << "]element" << endl;
            cin >> a[i][j];
        }
    }
    findelement(a, m, n, x);

    return 0;
}
