#include<bits/stdc++.h>
using namespace std;

class Triplet {
    public:
        int x, y, gcd;
};

Triplet Extendedeuclid(int a, int b) {
    if(b == 0) {
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    
    Triplet smallAns = Extendedeuclid(b, a%b);
    Triplet ans;
    ans.x = smallAns.y;
    ans.gcd = smallAns.gcd;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}

int main() {
    cout<<"Enter two numbers"<<endl;
    int a, b;
    cin>>a>>b;
    Triplet ans = Extendedeuclid(a, b);
    cout<<endl<<"Below value solve the equation ax + by = GCD(a,b)"<<endl;
    cout<<"GCD: "<<ans.gcd<<endl;
    cout<<"Value of x: "<<ans.x<<endl;
    cout<<"Value of y: "<<ans.y<<endl;
    return 0;
}