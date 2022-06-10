#include<bits/stdc++.h>
using namespace std;
int main()

{
    int a=50;
    int *ptr=&a;
    //cout<<a++<<" "; phele print kre ga fir badhye ga
    cout<<(*ptr)++<<" ";
    cout<<a<<endl;
    return 0;
}
