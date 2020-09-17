#include<bits/stdc++.h>
using namespace std;

void update(int index, int value, int* BIT, int n) {
    for(;index<=n;index += index&(-index))
        BIT[index] += value;
}

int query(int index, int* BIT) {
    int sum = 0;
    for(;index>0;index-=index&(-index))
        sum = sum + BIT[index];

    return sum;
}

int main() {
    cout<<"ENTER THE NUMBRV OF VALUES IN THE ARRAY"<<endl;
    int n;
    cin>>n;

    cout<<"ENTER THE VALUES"<<endl;
    int* arr = new int[n+1]();
    int* BIT = new int[n+1]();

    for(int i=1;i<=n;++i) {
        cin>>arr[i];
        update(i, arr[i], BIT, n);
    }

    cout<<"SUM OF FIRST 5 ELEMENTS IS: "<<query(5, BIT)<<endl;
    cout<<"SUM OF ELEMENTS FROM 2 INDEX TO 6 INDEX: "<<query(6, BIT) - query(1, BIT)<<endl;
    return 0;
}