
#include <bits/stdc++.h>
using namespace std;

void mergetwosortedarray(int arr1[], int n1, int arr2[], int n2)
{
    int j = 0;
    int i = 0;
    int maxsum = 0;
    int s1 = 0;
    int s2 = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            s1 = s1 + arr1[i];
            i++;
        }
        else
        {
            s2 = s2 + arr2[j];
            j++;
        }

        if (arr1[i] == arr2[j])
        {
            s1 = s1 + arr1[i];
            //cout<<"the maximum sum is s1 "<<s1<<" "<<endl;
            s2 = s2 + arr2[j];
            //cout<<"the maximum sum is s2 "<<s2<<" "<<endl;
            i++;
            j++;
            

            if (s1 > s2)
            {    
                maxsum = maxsum+s1;
               // cout<<"the maximum sum is s1 "<<maxsum<<" "<<endl;
                s1 = 0;
                s2=0;
            }
            else
            {
                
                maxsum = maxsum+s2;
                //cout<<"the maximum sum is s2 "<<maxsum<<" "<<endl;
                s2 = 0;
                s1 = 0;
            }
            
        }
        // cout<<"the s22 sum is s2222 "<<s2<<" "<<endl;
        // cout<<"the s1 sum is s11111 "<<s1<<" "<<endl;
        // cout<<"the maximum sum is s1 "<<maxsum<<" "<<endl;
    }
    // cout<<i;
    // cout<<j;
    while (i < n1)
    {
        s1 = s1 + arr1[i];
        i++;
        
    }

    while (j < n2-1)
    {
        s2 = s2+ arr2[j];
        j++;
      
    }
    
    if (s1 > s2)
    {

        maxsum = maxsum+s1;
    }
    else
    {

        maxsum = maxsum+s2;
    }
    cout<<"the maximum sum is "<<maxsum<<" "<<endl;
}

int main()
{
    int n1 = 6;
    int n2 = 5;
    int a[] = {1, 5, 10, 15, 20, 25};
    int b[] = {2, 4, 5, 9, 15};
    mergetwosortedarray(a, n1, b, n2);

    // cout<<"the duplicate element is :"+k;
}