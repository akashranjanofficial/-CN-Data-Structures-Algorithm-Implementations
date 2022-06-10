// binary search

#include <iostream>
using namespace std;

int binarysearch(int a[], int e, int n)

{
    int start = 0;
    int end = e - 1;
    while (start <= end)
    {
        int middle = (start + end) / 2;

        if (a[middle] == n)
        {
            return middle;
        }
        else if (n < a[middle])
        {

            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }

    return -1;
}

int main()
{
    int e;
    int n;

    cout << "enter how many elements you want to enter " << endl;
    cin >> e;
    int a[e];
    cout << "enter the sorted array  ";

    for (int i = 0; i < e; i++)
    {
        
        cin >> a[i];
    }
    cout << "enter which no. you want to find in the array" << endl;

    cin >> n;
    cout << "index is "<<binarysearch(a, e, n);

    return 0;
}