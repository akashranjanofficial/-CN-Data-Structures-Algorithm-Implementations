#include <bits/stdc++.h>
using namespace std;
#include <stack>
// include <stack> function
/* stack<int> s1;
kya kr rahe the------------equivalent kya use krna ha <stack>me
push(t element)             s1.push(element)
t pop()                     void pop() //cout will not work means ->cout<<pop()->this will not return the value you poped
t top()                     t top();
//                  -------------to view what element you have poped------first save that element from top then use pop
                            a=s1.top()
                              s1.pop() and then cout<<a;
size()                       same size()->return size of stack;
isEmpty()                      bool empty()
*/
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout << s.top() << " " << endl;
    s.pop();
    cout << s.top() << " " << endl;
    cout << s.size() << " " << endl;
    cout << s.empty() << " " << endl;
    cout << s.top() << " " << endl;
    int a = s.top();
    s.pop();
    cout << a << " " << endl;
    cout << s.top() << " " << endl;
}