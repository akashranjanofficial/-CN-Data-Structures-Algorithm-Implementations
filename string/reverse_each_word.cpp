#include <bits/stdc++.h>
using namespace std;

// void reverseeachword(char input[])
// {
//     int i = 0, j = 0, k = 1;
    

//     for (i = j; input[i]!=' '; i++)
    
//     {
//         // char output[strlen(input)] = {NULL};
//         // if (input[i] != ' ')
//         // {
//         //     strncpy(output, input, i);
//         //     return;
//         // }
//         // k = i - 1;
//         // cout<<i;
//         // while (k <= i)
//         // {
//         //     if (output[k] == ' ')
//         //     {
//         //         cout << output[k];

//         //         //break;
//         //     }
//         //     cout << output[k];
//         //     k--;
//         // }
//     }
    
//      while (1)
//     {
//        // cout << i;
//            j=i+1;
//     }
// }

int main()
{
    char input[] = {"welcome to"};
    int i=0;
    char output[7]={NULL};
     strncpy(output, input, 7);
    //int k= strlen(input);
    // cout<<k;
   // reverseeachword(input);
   
   while (output[i]!='\0')
    {
         cout<<i;
       cout<<output[i];
      
       i++;
    }
    cout<<i<<endl;
    cout<<output[i];

    return 0;
}