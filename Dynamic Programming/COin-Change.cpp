#include <bits/stdc++.h>
using namespace std;

int FindWays(int* arr, int n, int value, int** dp) {
    if(n == 0) {
        return 0;
    }
    if(value <= 0) {
        return 1;
    }
    if(dp[arr[0]][value] >= 0)
        return dp[arr[0]][value];

    int way1 = 0;
    if(value - arr[0] >= 0)
        way1 = FindWays(arr, n, value - arr[0], dp);
    int way2 = FindWays(arr + 1, n - 1, value, dp);

    dp[arr[0]][value] = way1 + way2;
    return (way1 + way2);
}

int main() {
    int n, value;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> value;

    int** dp= new int*[n+1];
    for(int i=0;i<=n;++i) {
        dp[i] = new int[value+1];
        for(int j=0;j<=value;++j)
            dp[i][j] = -1;
    }

    cout<<FindWays(arr, n, value, dp);

    return 0;
}