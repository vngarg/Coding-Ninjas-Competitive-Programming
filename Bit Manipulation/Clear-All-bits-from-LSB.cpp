#include<bits/stdc++.h>
using namespace std;

int main() {
    cout<<"Enter the number and value of i"<<endl;
    int n,i;
    cin>>n>>i;
    int a = 1<<(i+1);
    a = a - 1;
    a = ~a;
    cout<<(n&a)<<endl;
    return 0;
}