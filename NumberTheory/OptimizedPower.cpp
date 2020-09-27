#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int GetPow(int n, int p) {
    if(n == 0)
        return 0;
    if(p == 0)
        return 1;

    if(p % 2 == 0) {
        long smallAns = GetPow(n, p/2);
        long ans = (smallAns*smallAns)%MOD;
        return int(ans);
    } else {
        long smallAns = GetPow(n, p-1);
        long ans = (n%MOD);
        ans = (ans * smallAns) % MOD;
        return int(ans);
    }
}

int main() {
    cout<<"Enter the number and the power"<<endl;
    int n, p;
    cin>>n>>p;
    cout<<GetPow(n, p)<<endl;
    return 0;
}