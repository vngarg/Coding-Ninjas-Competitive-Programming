#include<bits/stdc++.h>
using namespace std;

int max_product(int *arr, int size) {
    int max_so_far=1;
    int max_ending_here=1;
    int min_ending_here=1;
    for(int i=0;i<size;++i) {
        if(arr[i] == 0) {
            max_ending_here = 1;
            min_ending_here = 1;
        } else if(arr[i] > 0) {
            max_ending_here = max_ending_here * arr[i];
            min_ending_here = min(1, (min_ending_here * arr[i]) );
        } else if(arr[i] < 0 ){
            int temp = max_ending_here;
            max_ending_here = max(1, (min_ending_here * arr[i]) );
            min_ending_here = temp * arr[i];
        }

        if(max_so_far < max_ending_here )
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

int main() {
    cout<<"Enter size of Array: ";
    int n;
    cin>>n;
    cout<<"Enter the array"<<endl;
    int a[n];
    for(int i=0;i<n;++i)
        cin>>a[i];

    cout<<"Maximum Product of subArray: "<<max_product(a,n)<<endl;
    return 0;
}