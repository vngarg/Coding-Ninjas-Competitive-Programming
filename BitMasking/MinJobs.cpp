#include<bits/stdc++.h>
using namespace std;

int minJobs(int p, int** jobs, int mask, int* dp, int n) {
    int minnimum = INT_MAX;
    if(p >= n) {
        return 0;
    }
    if(dp[mask] != INT_MAX) {
        return dp[mask];
    }

    for(int i=0;i<n;++i) {
        if(!(mask&(1<<i))) {
            int ans = minJobs(p + 1, jobs, mask|(1<<i), dp, n) + jobs[p][i];
            if(ans < minnimum)
                minnimum = ans;
        }
    }

    dp[mask] = minnimum;
    return minnimum;
}

int main() {
    cout<<"Enter the Size"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the Matrix"<<endl;
    int** jobs = new int*[n];
    for(int i=0;i<n;++i) {
        jobs[i] = new int[n];
        for(int j=0;j<n;++j)
            cin>>jobs[i][j];
    }

    int size = (1<<n);
    int* dp = new int[size];
    for(int i=0;i<size;++i)
        dp[i] = INT_MAX;

    cout<<"Minimum cost for the jobs to be done is"<<endl<<minJobs(0, jobs, 0, dp, n)<<endl;
    return 0;
}