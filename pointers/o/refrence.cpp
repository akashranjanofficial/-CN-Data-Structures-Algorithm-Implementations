#include<bits/stdc++.h>
using namespace std;

void increment(int &n)
{
    n++;
}
int &increment(int &o)
{
    o++;
    return o;
}


int main()
{
    int i=10;
    int &k=i;//creating a refrence variable k for i;
    
      cout<<k<<"this is the refrence to i"<<endl;
      //if i increase k here it will affect on i;
      k++;
      cout<<k<<"this shows that if i increase the k it affect i because i am incereasing in refrence"<<endl;

      //how to pass the value to a function such that if i do any changes it will affect on main fuction varible
      increment(i);
      cout<<i<<"this is showing that this will give affect on i"<<endl;

  //ye blunder mistake ha  { //   //now how to return as refrence;
    //   int& l=increment(i);
    //   cout<<l<<"return the value of i as refrence";
   }


}