#include<iostream>
#include<vector>

using namespace std;

long long MaxProduct(vector<int>& arr) {
    int n = arr.size();
    int i , index1 = 0 , index2 , l1=arr[0] , l2;
    for(i=0;i<n;++i) {
        if(arr[i] > l1) {
            index1 = i;
            l1 = arr[i];
        }
    }

    if(index1 == 0) {
        index2 = 1;
        l2 = arr[1]; 
    }
    else {
        index2 = 0;
        l2 = arr[0];
    }

    for(int j=0;j<n;++j) {
        if( (j != index1) && (arr[j] > l2) ) {
            index2 = j;
            l2 = arr[j];
        }
    }
    return (long long)l1*l2;
}

int main() {
    int n;
    cin>>n;
    vector <int>a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];

    cout<<MaxProduct(a);
    return 0;
}