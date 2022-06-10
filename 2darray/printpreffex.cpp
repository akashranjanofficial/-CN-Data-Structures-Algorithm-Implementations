#include <bits/stdc++.h>
using namespace std;
int main()
{
    char input[100] = "abcd";

    int k = strlen(input);
    for (int i = 0; input[i]!='\0'; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << input[j] << " ";
        }
        cout<<endl;
    }
   // o(n2) aproach tha
  
    

    return 0;
}
