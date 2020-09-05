#include<bits/stdc++.h>
using namespace std;

int main() {
    cout<<"Enter the number"<<endl;
    int n;
    cin>>n;
    int count  = 0;
    bool arr[n+1];
    arr[0] = arr[1] = false;
    for(int i=2;i<=n;++i)
        arr[i] = true;

    for(int j=2;j<=sqrt(n);++j) {
        if(!arr[j])
            continue;
        int k = j * j;
        for(;k<=n;k+=j)
            if(k % j == 0)
                arr[k] = false;
    }

    for(int i=0;i<=n;++i)
        if(arr[i])
            ++count;

    cout<<"Total Prime Numbers from 1 to "<<n<<" are "<<count<<endl;
    return 0;
}