#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    if(b == 0)
        return a;
    return GCD(b, a%b);
}

int main() {
    cout<<"Enter two numbers to get GCD"<<endl;
    int a, b;
    cin>>a>>b;

    int x = min(a, b);
    int y = max(a, b);
    cout<<"GCD of "<<a<<" and "<<b<<" is: "<<GCD(x, y)<<endl;
    return 0;
}