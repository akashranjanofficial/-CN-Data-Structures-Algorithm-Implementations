#include <bits/stdc++.h>
using namespace std;
//
int stringtointeger(string s)
{
    int size = s.size();
    int len = s.length();
    // base case
    if (s.length() == 1)
    {

        return (s[0] - '0');
    }

    double a = stringtointeger(s.substr(1));
    // First digit of the number
    double x = s[0] - '0';
    x = x * pow(10,s.length()-1) + a;
    return x;
}

int main()
{

    string s; //we can also crea

    getline(cin, s);

    int m = stringtointeger(s);
    cout << m;
   // cout << stringtointeger(s);
}
