#include<bits/stdc++.h>
using namespace std;

int Kadane(int *arr, int size) {
    int current_max=0;
    int best_max = 0;
    for(int i=0;i<size;++i) {
        current_max += arr[i];
        if(best_max < current_max) 
            best_max = current_max;
        if(current_max < 0) 
            current_max =0;
    }
    return best_max;
}

int main() {
    int n;
    cout<<"Enter Size of Array"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter elements of Array"<<endl;
    for(int i=0;i<n;++i)
    cin>>a[i];
    cout<<"Maximun Sum of Sub Array is: "<<Kadane(a,n)<<endl;
    return 0;
}