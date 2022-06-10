#include <bits/stdc++.h>
using namespace std;
int main()
{
    string sw = "abcde";
    cout<<"printing normal string"<<sw<<endl;
    //dynamiclu creating array 
   string *sp=new string;
   *sp="def";
   cout<<sp<<"this is address of string created dynamicallyl"<<endl;
   cout<<*sp<<endl;
   //taking ip as string;
   string sip;
   getline(cin,sip);
   cout<<sip<<endl;
 cout<<"the size of string"<<sip.size()<<endl;
 string s = "abc";
	//getline(cin, s);
	cout << s << endl;
	
	s = "defdef";
	cout << s[0] << endl;
	s[0] = 'a';
	string s1;
	s1 = "def";

	string s2 = s + s1;
	cout << s2 << endl;

	s += s1;

	cout << s1 << endl;
	cout << s << endl;

	cout << s.size() << endl;
	cout << s.substr(3) << endl;	
	cout << s.substr(3, 3) << endl;	

	cout << s.find("def") << endl;

 


}