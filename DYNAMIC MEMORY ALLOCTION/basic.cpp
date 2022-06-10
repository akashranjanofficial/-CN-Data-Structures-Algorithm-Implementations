#include <bits/stdc++.h>
using namespace std;
int main()

{
    int *p = new int; //heap me memory allocate ho jaye ga then p me uska address save ho jaye ga
    *p = 10;
    cout << *p << "this will give value of p" << endl;
    double *pd = new double;
    *pd = 10.6;
    char *c = new char;
    *c = 'a';
    cout << *pd << endl;
    cout << pd << "address of pd" << endl;
    cout << *c << endl;
    //dynamic aray creation
    int n;
    cout << "enter the value of n;";
    cin >> n;
    int *arr = new int[n];
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout<<"maximum in array" << max << endl;

    return 0;
}