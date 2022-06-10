// binary search

#include <iostream>
using namespace std;

void selectionsort(int a[], int n)
{
    for (int i = 0; i < n-1; i++)
   {
    
    int min=a[i];
    int minindex=i;//asuming minimum is a[0]
    //comparing element of arays with minimum
    for (int j = i+1; j< n; j++)
    {
        if (a[j]<min)
        {
            min=a[j];
            minindex=j;
        }

        
    }
    //swaping 
    int temp=a[i];
    a[i]=a[minindex];
   a[minindex]=temp;
   }

    
}

int main()
{
    int a[]={3,1,6,9,0,4};
    // int n=6;
    selectionsort(a,6);
    for (int i = 0; i < 6; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}