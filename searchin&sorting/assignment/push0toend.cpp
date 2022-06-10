
#include <iostream>
using namespace std;

void push(int a[], int n)
{
    int temp[n-1];
    int k=0;
    for (int i = 0; i < n; i++)
    {

        if (a[i] != 0)
        {
            temp[k] = a[i];
            k++;
            
        }
        

        
    }
    while(k<n)
    {
        temp[k]=0;
        k++;
    }
    for (int t = 0; t < n; t++)
    {
        cout << temp[t] << " ";
    }
    
   
}

int main()
{
    int a[] = {0, 15, 0, 9, 3, 8, 16};
    // int n=6;
    push(a, 7);
    // for (int i = 0; i < 7; i++)
    // {
    //    cout <<  << " ";
    // }
    cout << endl;

    return 0;
}