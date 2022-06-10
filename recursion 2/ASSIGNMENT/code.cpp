#include <bits/stdc++.h>
using namespace std;
int returnminimum(int n)
{
    int count = 0;
    //base case
    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    //recursive call;
  
    for (int i = 1; i <= n; i++)
    {
        if (i * i <= n)
        {
            count =1+ returnminimum(n - i * i);
             
        }
       
       

        
           
    }
    return count;
   
}
int main()
{
    int n;
    cout<<"enter the no."<<endl;
    cin >> n;
    //  int op = 0;
   int k= returnminimum(n);
   cout<<k+1;
}