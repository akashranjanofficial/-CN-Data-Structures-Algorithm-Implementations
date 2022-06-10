#include<bits/stdc++.h>
using namespace std;

void duplicate(int arr[], int n)
{
   int sum=0;
   int newn=(n-2);
   int apsum=(newn*(1+newn))/2;
   for (int i = 0; i <=n-1; i++)
   {
       sum += arr[i];

   }
   cout<<sum<<" "<<endl;
//    cout<<apsum<<" ";

  int k=sum-apsum;
//    cout<<k<<" ";
cout<<"the duplicate element is :"<<k;

}





int main(){
    int n=9;
    int arr[]={0, 0 ,2 ,5, 4, 7, 1, 3, 6};
    duplicate(arr,n);
   // cout<<"the duplicate element is :"+k;

}