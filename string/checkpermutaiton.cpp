#include <bits/stdc++.h>
using namespace std;


bool checkPegs(int arry[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arry[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}

void checkpermutation(char str1[], char str2[])
{
    int i = 0, j = 0;
    if (strlen(str1) != strlen(str2))
    {
        cout << "false";
    }
    else
    {
        int arry[256] = {0};
        for (int i = 0; str1[i] != 0; i++)
        {
            arry[str1[i]] = arry[str1[i]] + 1;
        }
        for (int i = 0; str2[i] != 0; i++)
        {
            arry[str2[i]] = arry[str2[i]] - 1;
        }
       if( checkPegs(arry, 256)==0)
       {
           cout<<"false";

       }else
       cout<<"true";
    }

}

int main()
{
    char str1[100] = "abbde";
    char str2[100] = "bbbdc";

    checkpermutation(str1, str2);

    return 0;
}
