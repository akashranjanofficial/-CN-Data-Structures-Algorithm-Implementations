//we are understanding dyanmic memory allocation
#include<bits/stdc++.h>
using namespace std;



//fibonaci using irrative apporach

int fib(int n)
{
    int *arr=new int[n+1];
    arr[0]=1;
    arr[1]=1;
    for (int i = 2; i <=n; i++)
    {
        arr[i]=arr[i-1]+arr[i-2];

    }
    int output=arr[n];
    delete [] arr;
    return output;
    

}
//understanding notes  link = https://ibb.co/RN0qdxQ
//using recursive approach
int fib(int n,int *arr)
{
    if(n==0||n==1)
    {
        return 1;
    }
    if (arr[n]>0)       
    {
        return arr[n];
    }
    int output=fib(n-1)+fib(n-2);
    arr[n]=output;
    return output;
    

}
//https://ibb.co/brVPsQZ

int main()
{
    int n;
    cin>>n;
   /// cout<<fib(n)<<endl;
   int *arr=new int[n+1];
   for (int i = 0; i <=n; i++)
    {
        arr[i]=0;

    }
   cout<<fib(n,arr)<<endl;


}