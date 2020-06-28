#include<bits/stdc++.h>
using namespace std;

int lis(int* arr, int n) {
    int* output = new int[n];
    output[0] = 1;

    for(int i=1;i<n;++i) {
        output[i] = 1;
        for(int j = i-1;j>=0;--j) {
            if(arr[j] <= arr[i]) {
                int possibleAns = output[j] + 1;
                if(possibleAns > output[i])
                    output[i] = possibleAns;
            }
        }
    }

    int best = 0;
    for(int i=0;i<n;++i)
        if(output[i] > best)
            best = output[i];

    delete [] output;
    return best;
}

int main() {
    int n;
    cin>>n;
    int* input = new int[n];

    for(int i=0;i<n;++i)
        cin>>input[i];

    cout<<lis(input, n)<<endl;
    return 0;
}