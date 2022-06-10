
#include <bits/stdc++.h>
using namespace std;

void mergetwosortedarray(int arr1[], int n1, int arr2[], int n2)
{
    int n3 = n1 + n2;
    int c[n3];
    int j = 0;
    int i = 0;
    int k = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            c[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            c[k] = arr2[j];
            k++;
            j++;
        }
    }
    
    while (i < n1)
    {
        c[k] = arr1[i];
        i++;
        k++;
    }

       while(j < n2)
       {
           c[k]=arr2[j];
           j++;
           k++;
       }
    for (int l = 0; l < n3; l++)
    {
        cout << c[l] << " ";
    }
}

int main()
{
    int n1 = 3;
    int n2 = 7;
    int a[] = {10, 100, 500};
    int b[] = {4, 7, 9, 25, 30, 300, 450};
    mergetwosortedarray(a, n1, b, n2);

    // cout<<"the duplicate element is :"+k;
}