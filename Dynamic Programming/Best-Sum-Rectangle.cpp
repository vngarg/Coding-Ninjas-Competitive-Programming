#include<bits/stdc++.h>
using namespace std;    

int Kadane(int* arr, int n) {
    int bestSum = INT_MIN, currentBest = 0;

    for(int i=0;i<n;++i) {
        currentBest = currentBest + arr[i];
        if(currentBest > bestSum)
            bestSum = currentBest;

        if(currentBest < 0 )
            currentBest = 0;
    }
    return bestSum;
}

int RectangleSum(int** input, int m, int n) {
    int sum[m], bestSum = INT_MIN, currentBest = 0;
    for(int i=0;i<n;++i) {
        for(int k=0;k<m;++k)
            sum[k] = 0;

        for(int j=i;j<n;++j) {

            for(int k=0;k<m;++k) {
                sum[k] = sum[k] + input[k][j]; 
            }

            currentBest = Kadane(sum, m);
            if(currentBest > bestSum)
                bestSum = currentBest;
        }
    }
    return bestSum;
}

int main() {
    int n,m;
    cin>>m>>n;
    int** input = new int*[m];
    for(int i=0;i<m;++i)
        input[i] = new int[n];

    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j) 
            cin>>input[i][j];

    cout<<RectangleSum(input, m, n);
    return 0;
}