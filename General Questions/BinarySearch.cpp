#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;

int binary(int arr[], int start, int end, int ele)
{
    if (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == ele)
            return mid;

        if (arr[mid] > ele) 
            return binary(arr, start, mid - 1, ele);
        
        return binary(arr, mid+1, end, ele);
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, ele;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; ++i)
            cin >> arr[i];
        cin >> ele;

        cout << binary(arr, 0, n - 1, ele);
    }
    return 0;
}