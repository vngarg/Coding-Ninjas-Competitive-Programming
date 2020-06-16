#include<bits/stdc++.h>
using namespace std;

int main() {
    cout<<"Enter the number"<<endl;
    int n;
    cin>>n;

    if( (n&(n-1)) == 0) 
        cout<<n<<" is a power of 2"<<endl;
    else 
        cout<<n<<" is not a power of 2"<<endl;
    return 0;
}