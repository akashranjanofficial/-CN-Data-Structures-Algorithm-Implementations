#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{   //vector<int> *vp=new vector<int>();
    vector <int> v;
   v.push_back(10);
   v.push_back(50);
   v.push_back(60);
   cout<<v[0]<<endl;
   cout<<v[1]<<endl;
   cout<<v[2]<<endl;
   
   //we can change the value of vector particular valuwe but wo size increase nahi kare ga wo problem kre ga baad me not recomended to use;

   v[1]=1000;  //dont use this for insert element use it for update values and get value;

   cout<<v[1]<<endl;
   //size
   cout<<"size: "<<v.size()<<endl;
   //find out the element at index
   cout<<v.at(2)<<endl;
   v.pop_back(); //removes the last element from the vector;
   for(int i=0;i<v.size();i++)
   {
       cout<<v.at(i)<<endl;
   }
}