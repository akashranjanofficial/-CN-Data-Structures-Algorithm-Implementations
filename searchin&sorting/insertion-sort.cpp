// binary search

#include <iostream>
using namespace std;

void insertionsort(int a[], int n)
{

    for (int i = 1; i < n; i++)
    {
       
        int current = a[i];
        int j; 
        for (j = i - 1; j >=0; j--)
        {
            if (current < a[j])
            {
                a[j + 1] = a[j];
            }
            else
                break;
        }
        a[j + 1] = current;

         
    }
}

int main()
{
    int a[] = {3, 1, 6, 9, 0, 4};
    // int n=6;
    insertionsort(a, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}