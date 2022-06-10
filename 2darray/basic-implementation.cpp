
#include <iostream>
using namespace std;


int main()
{
    int a[100][100];
    // int n=6;
    int m;
    int n;
    cout<<"enter values of row and column"<<endl;
    cin>>m>>n;
    for (int i = 0; i < m; i++)
    {
       for (int j = 0; j < n; j++)
       {
           cout<<"enter the value:";
           cin>>a[i][j];
       }
       
    }
    for (int i = 0; i < m; i++)
    {
       for (int j = 0; j < n; j++)
       {
           
           cout<<a[i][j]<<" ";
       }
       cout << endl;
    }
    cout << endl;


    return 0;
}