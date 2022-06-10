#include <iostream>
using namespace std;


int sum(int n)
{int sum;
sum=n/2*(2+(n-1));
 
return sum;
}
int product(int n){
    int d=1;
    while (n>=1)
    {
        d=d*n;
        n--;
    }
    return d;
    
}
int main() {
    int n,c;
    cout << "ENTER THE VALUE OF N";
    
    cin>>n;
    cout<<"choose below"<<"\n1-sum"<<"\n2-product"<<endl;
    cin>>c;
    if(c==1)
    {
        cout<<"the sum of 1 to n is :-"<<sum(n)<<endl;
        exit;
    }
    if (c==2)
    {
        cout<<"the product of 1 to n is :-"<<product(n);
    }
    if (c!=1&&c!=2)
    {
        cout<<"invalid no. "<<"-1";
    }
    
    
    
    return 0;
}
