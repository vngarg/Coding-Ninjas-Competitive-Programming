#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, i;
    cout<<"Enter the number and the bit to be flipped"<<endl;
    cin>>n>>i;
    int result = n^(1<<i);
    cout<<result<<endl;
    return 0;
}