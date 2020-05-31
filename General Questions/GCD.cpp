#include<iostream>

using namespace std;

int GCD(long long a , long long b) {
    if(b==0) {
        return a;
    } else {
        a = a % b ;
        return GCD(b , a);
        
    } 
}

int main() {
    long long a,b;
    cout<<"Enter Two Numbers"<<endl;
    cin>>a>>b;

    cout<<"The GCD of "<<a<<" and "<<b<<" is: "<<GCD(a,b)<<endl;
    return 0;
}