// binary search
//ye galat ha shad waps se dekhna hoga
#include <iostream>
using namespace std;

void mergesort(int a[], int b[],int sa,int sb)
{    int i=0;
     int j=0;
     int c[sa+sb];
    for (int k = 0; k < sa+sb; k++)
    {
       
        if (b[j]<a[i])
        {
            c[k]=b[j];
            j++;
        }else
        {
          c[k]=a[i];
            i++;
        }

        
         
    }
}

int main()
{
    int a[] = {3, 1, 6, 9, 0, 4};
     int b[] = {15, 2, 8};
    // int n=6;
    mergesort(a,b,6,3);
    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}