#include<bits/stdc++.h>
using namespace std;

int main() {
    cout<<"Enter the number"<<endl;
    int n;
    cin>>n;
    if((n&1) == 0)
        cout<<"The number "<<n<<" is even"<<endl;
    else 
        cout<<"The number "<<n<<" is odd"<<endl;
    return 0;
}