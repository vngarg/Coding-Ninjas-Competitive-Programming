#include<bits/stdc++.h>
using namespace std;

int* lisFront(int* arr, int n, int* output) {
    output[0] = 1;

    for(int i=1;i<n;++i) {
        output[i] = 1;
        for(int j = i-1;j>=0;--j) {
            if(arr[j] < arr[i]) {
                int possibleAns = output[j] + 1;
                if(possibleAns > output[i])
                    output[i] = possibleAns;
            }
        }
    }

    return output;
}

int* lisBack(int* arr, int n, int* output) {
    output[n-1] = 1;

    for(int i=n-2;i>=0;--i) {
        output[i] = 1;
        for(int j = i+1;j<n;++j) {
            if(arr[j] < arr[i]) {
                int possibleAns = output[j] + 1;
                if(possibleAns > output[i])
                    output[i] = possibleAns;
            }
        }
    }

    return output;
}

int main() {
    int n;
    cin>>n;
    int* input = new int[n];
    int* output = new int[n];
    int* output1 = new int[n];
    int result[n], max = 0;

    for(int i=0;i<n;++i)
        cin>>input[i];

    int* front = lisFront(input, n, output);
    int* back = lisBack(input, n, output1);

    for(int i=0;i<n;++i) {
        result[i] = front[i] + back[i] - 1;
        if(max < result[i])
            max = result[i];
    }

    cout<<max;
    return 0;
}