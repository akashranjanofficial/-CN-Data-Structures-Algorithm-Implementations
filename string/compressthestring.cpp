#include <bits/stdc++.h>
using namespace std;

void compressstring(char input[])
{
    int i=0,k=1;
    int j=i+1;
    

    for (i = 0; input[i] != '\0'; i++)
    {
        if(input[i]==input[j])
        {
          k++;
          
        }
        
         else{
            cout<<input[i];
            if(k!=1)
            {
                cout<<k;
              k=1;
            }
        }
        j++;
    }
    
}

int main()
{
    char input[] = {"aaabbcddeeeee"};

    compressstring(input);

    return 0;
}