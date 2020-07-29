#include<bits/stdc++.h>
using namespace std;

int lcsHelper(char* s1, char* s2, int m, int n, int** arr) {
    if(m == 0 || n == 0)
        return 0;

    if(arr[m][n] > -1)
        return arr[m][n];    

    int ans;
    if(s1[0] == s2[0]) {
        ans = 1 + lcsHelper(s1+1, s2+1, m-1, n-1, arr);
    } else {
        int option1 = lcsHelper(s1, s2+1, m, n-1, arr);
        int option2 = lcsHelper(s1+1, s2, m-1, n, arr);
        ans = max(option1, option2);
    }
    arr[m][n] = ans;
    return ans;
}

int lcs(char* s1, char* s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int** arr = new int*[m+1];
    for(int i=0;i<=m;++i)
        arr[i] = new int[n+1];

    for(int i=0;i<=m;++i)
        for(int j=0;j<=n;++j)
            arr[i][j] = -1;

    int ans = lcsHelper(s1, s2, m, n, arr);
    return ans;
}

int main() {
    cout<<"Enter two strings"<<endl;
    char a[100];
    char b[100];

    cin>>a;
    cin>>b;
    cout<<lcs(a, b);
    return 0;
}