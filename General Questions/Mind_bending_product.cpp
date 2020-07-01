#include<bits/stdc++.h>
using namespace std;

void product(int *arr, int size) {
    int a[size];
    int rp, lp;
    for(int i=0;i<size;++i) {
        rp=1;
        for(int j=i+1;j<size;++j)
            rp = rp*arr[j];
        a[i] = rp;
    }
    cout<<"New array is: ";
    for(int i=0;i<size;++i) {
        rp = 1;
        for(int j=i-1;j>=0;--j) 
            rp = rp*arr[j];

        a[i] = a[i]*rp;
        cout<<a[i]<<" ";
    }  
    cout<<endl;
}

int main() {
    cout<<"Enter SIze of Array:"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter eements of array:"<<endl;
    for(int i=0;i<n;++i)
        cin>>a[i];
    product(a,n);
    return 0;
}