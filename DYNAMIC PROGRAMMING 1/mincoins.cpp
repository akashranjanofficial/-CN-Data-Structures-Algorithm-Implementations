#include <bits/stdc++.h>
#include <climits> //it is for using maximum int value infinity we can assign
using namespace std;
//function top down approach

// minofcoins(int n, int coins[], int t, int dp[])
// {
//     //base case
//     if (n == 0)
//     {
//         return 0;
//     }
//     //lookup
//     if (dp[n] != 0)
//     {
//         return dp[n];
//     }
//     int ans = INT_MAX;
//     for (int i = 0; i < t; i++)
//     {
//         if (n - coins[i] >= 0)
//         {
//             int subprob = minofcoins(n - coins[i], coins, t, dp);
//             ans = min(ans, subprob + 1);
//         }
//     }
//     dp[n] = ans;
//     return dp[n];
// }

//BOTOM UP APPROACH
int minofcoins(int n, int coins[], int t)
{ //here t is no of coins
    int dp[n+1] = {0};
    dp[0]=0;
    for (int i=1; i<=n; i++)
        dp[i] = INT_MAX;

    for (int i = 1; i <= n; i++)
    //we are iterate over all the states like if n=10 then i=1 to 10
    {
         //we are initizlize the current answwer
        //so for every states we have to call t times here t is no of coins
        for (int k = 0; k < t; k++)
        {
            if (coins[k] <= i)
            {

                int subproblem = dp[i - coins[k]];
                if (subproblem != INT_MAX && subproblem + 1 < dp[i])
                {
                    dp[i] = subproblem + 1;
                }
            }
        }
    }
    if (dp[n] == INT_MAX)
        return -1;

    return dp[n];
}

int main()
{
    int n = 15;
    //cin n;
    int coins[] = {1, 7, 10};
    int dp[100] = {0};
    int t = sizeof(coins) /sizeof(coins[0]);
    cout << minofcoins(n, coins, t) << endl;
    return 0;
}