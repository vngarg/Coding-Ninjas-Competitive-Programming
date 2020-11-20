/* Problem Statement

Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Merge(int* arr, int start, int mid, int end) {
    int i = start, j = mid, k = 0;
    ll count = 0;
    int temp[end - start + 1];

    while(i < mid && j <= end) {
        if(arr[i] < arr[j]) {
            count = count + arr[i]*(end - j + 1);
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }   
    }

    while(i < mid)
        temp[k++] = arr[i++];

    while(j <= end)
        temp[k++] = arr[j++];

    for(int i=start, k = 0;i<=end;i++, k++)
        arr[i] = temp[k];
    
    return count;
}

ll Total(int* arr, int start, int end) {
    ll count = 0;
    while(start < end) {
        int mid = (start + end)/2;
        ll countL = Total(arr, start, mid);
        ll countR = Total(arr, mid + 1, end);
        count = Merge(arr, start, mid+1, end);

        return count + countL + countR; 
    }
    return count;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;++i)
            cin>>arr[i];

        cout<<Total(arr, 0, n-1)<<endl;
    }
    return 0;
}