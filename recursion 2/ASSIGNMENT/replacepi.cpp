// Replace pi (recursive)
// Send Feedback
// Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
// Sample Input 1 :
// xpix
// Sample Output :
// x3.14x
// Sample Input 2 :
// pipi
// Sample Output :
// 3.143.14
// Sample Input 3 :
// pip
// Sample Output :
// 3.14p
#include <bits/stdc++.h>
using namespace std;
string replacepi(string s)
{
    string val="3.14";
    //base case
    if (s.length() == 1)
    {
        return s;
    }
    if (s.length() == 0)
    {
        return " ";
    }
    string temp=replacepi(s.substr(1));
    
    if(temp[0]=='i'&&s[0]=='p')
    {
      string newstr=temp.substr(1);
      return val+newstr;
    }
    else{
        return s[0]+temp;
    }
    
}


int main()
{
    string s;
    getline(cin, s);
  cout<<replacepi(s);
  
  
  
}