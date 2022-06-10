#include <bits/stdc++.h>
using namespace std;
void rotatematrix(int a[][100],int m)
{
    int b[m][m]={NULL};
   
    int k=0;
    int j=0;
    while (j<m&&k<m)
    {
        int l=0;
        for ( int i = m-1; i >=0&&l<m; i--)
        {
             b[i][j]=a[k][l];
            l++;
        }
        j++;
        k++;
        
        
        
    }
    for (int P = 0; P < m; P++)
    {
        for (int Q = 0; Q < m; Q++)
        {
           a[P][Q]=b[P][Q];
            cout<<" "<<b[P][Q]<<" ";
        }
        cout<<endl;
    }

    
    


}
int main()
{

    int m;
    cin >> m;
    int a[100][100];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    rotatematrix(a,m);
    return 0;
}