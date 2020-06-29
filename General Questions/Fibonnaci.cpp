#include<iostream>
using namespace std;

int main() {
    long long a=0,b=1,n;
    cin>>n;
    cout<<a<<' '<<b<<' ';
    if(n==0) 
    cout<<'0';
    else if(n==1) 
    cout<<'0';
    else {
        for(long long i=0;i < (n/2-1) ;++i) {
        a=a+b;
        b=a+b;
        cout<<a<<' '<<b<<' ';
    }
    if(n%2!=0) 
        cout<<a+b;
    }
    return 0;
}