#include <bits/stdc++.h>
using namespace std;

long long MERGE(long long *arr, long long start, long long mid, long long end) {
    int temp[end - start + 1], i = start, j = mid, k = 0, count = 0;
    while (i < mid && j <= end)
    {
        if (arr[i] > arr[j])
        {
            count = count + mid - i;
            temp[k++] = arr[j++];
        }
        else
        {
            temp[k++] = arr[i++];
        }
    }

    while (i < mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    for (int i = start, k = 0; i <= end; ++k, ++i)
        arr[i] = temp[k];

    return count;
}

long long Merge(long long *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        long long countL, countR, count = 0;

        countL = Merge(arr, start, mid);
        countR = Merge(arr, mid + 1, end);
        count = MERGE(arr, start, mid + 1, end);

        return count + countL + countR;
    }
    else
    {
        return 0;
    }
}

long long getInversions(long long *arr, int n)
{
    return Merge(arr, 0, n - 1);
}

int main()
{
    int n;
    cin >> n;
    long long *arr = new long long[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << getInversions(arr, n);
    delete arr;
}