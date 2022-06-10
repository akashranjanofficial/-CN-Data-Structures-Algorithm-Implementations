#include <bits/stdc++.h>
#include <climits> //it is for using maximum int value infinity we can assign
using namespace std;
//function top down approach
int minsteps(int n, int dp[])
{
    //base case

    if (n == 1)
    {
        return 0;
    }
    //check id dp array is empty or not so that we can stop doing same thing
    //again and again
    if (dp[n] != 0)
    {
        return dp[n];
    }
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX; //INITILIZING THE OPTIONS TO MAX VALUE;

    if (n % 3 == 0)
    {
        op1 = minsteps(n / 3, dp);
    }
    if (n % 2 == 0)
    {
        op2 = minsteps(n / 2, dp);
    }
    op3 = minsteps(n - 1, dp);
    int ans = min(min(op1, op2), op3) + 1; //finding minimun of all the opion
    return dp[n] = ans;
}
//BOTTOM UP APPROCAH
int minsteps(int n)
{
    int dp[100] = {0};
    dp[1] = 0;
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    for (int i = 2; i <=n; i++)
    {
        
        if (n%3==0)
        {
            op1=dp[i/3];
        }
         if (n%2==0)
        {
            op1=dp[i/2];
        }
        op3=dp[i-1];
        dp[i]=min(min(op1,op2),op3)+1;
        
    }
    return dp[n];
    
}

int main()
{
    int n;
    cin >> n;
    int dp[100] = {0};

    //cout << minsteps(n, dp) << endl;
    cout<<minsteps(n)<<endl;
}