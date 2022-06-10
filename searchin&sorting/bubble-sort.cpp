
#include<iostream>
using namespace std;


void bublesort(int a[], int n)
{
    for (int j = 0; j < n - 1; j++)
    {

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                int temp;
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {3, 1, 6, 9, 0, 15,19};
    // int n=6;
    bublesort(a, 7);
    for (int i = 0; i < 7; i++)
    {
        cout<< a[i] << " ";
    }
    cout<<endl;

    return 0;
}