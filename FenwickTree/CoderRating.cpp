#include<bits/stdc++.h>
using namespace std;

class coder {
    public: 
        int x, y, index;
};

bool cmp(coder A, coder B) {
    if(A.x == B.x) {
        return A.y < B.y;
    } 
    else {
        return A.x < B.x;
    }
}

int query(int y, int* BIT) {
    int count = 0;
    for(;y>0;y-=y&(-y))
        count += BIT[y];
    return count;
}

void update(int y, int* BIT) {
    for(;y<=100000;y+=y&(-y))
        BIT[y]++;
}

int main() {
    int n;
    cin>>n;

    coder* arr = new coder[n];
    for(int i=0;i<n;++i)  {
        cin>>arr[i].x>>arr[i].y;
        arr[i].index = i;
    }

    sort(arr, arr + n, cmp);
    int* BIT = new int[100001];
    int* ans = new int[n];

    for(int i=0;i<n;) {
        int endIndex = i;
        while(endIndex < n && arr[endIndex].x == arr[i].x && arr[endIndex].y == arr[i].y) 
            ++endIndex;

        for(int j=i;j<endIndex;++j)
            ans[arr[j].index] = query(arr[j].y, BIT);

        for(int j=i;j<endIndex;++j)
            update(arr[j].y, BIT);

        i = endIndex;
    }

    for(int i=0;i<n;++i)
        cout<<ans[i]<<endl;
    return 0;
}