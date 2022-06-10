#include <bits/stdc++.h>
using namespace std;

void interleaving(string s1, string s2, string s3)
{
    //base case
    if (s1.length() == 0 && s2.length() == 0)
    {
        cout << s3 << endl;
        return;
    }
    //recursive call
    if (s1.length() != 0)
    {
        interleaving(s1.substr(1), s2, s3 + s1[0]);
    }
    if (s2.length()!=0)
    {
         interleaving(s1, s2.substr(1), s3 + s2[0]);
    }
    
   
}

int main()
{
    string s1;
    getline(cin, s1);
    string s2;
    getline(cin, s2);
    string s3 = "";
    interleaving(s1, s2, s3);

    return 0;
}