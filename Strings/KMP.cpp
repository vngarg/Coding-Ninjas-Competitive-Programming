/* KMP algorithm is the advanced and optimized version of Pattern Match algorithm */

#include<bits/stdc++.h>
using namespace std;

int* getLPS(string s) {
    int n = s.length();
    int* lps = new int[n];

    lps[0] = 0;
    int i = 1, j = 0;

    while(i<n) {
        if(s[i] == s[j]) {
            lps[i] = j + 1;
            ++i;
            ++j;
        } else {
            if(j == 0) {
                lps[i] = 0;
                ++i;
            } else {
                j = lps[j-1];
            }
        }
    }

    return lps;
}

bool KMP(string s, string p) {
    int n = s.length(), m = p.length();
    int* lps = getLPS(p);

    int i = 0, j = 0;
    while(i < n && j < m ) {
        if(s[i] == p[j]) {
            ++i;
            ++j;
        } else {
            if(j == 0) {
                ++i;
            } else {
                j = lps[j - 1];
            }
        }
    }
    if(j == m)
        return true;
    return false;
}

int main() {
    cout<<"Enter the main String"<<endl;
    string s;
    cin>>s;
    cout<<"Enter the pattern to Search"<<endl;
    string p;
    cin>>p;
    cout<<KMP(s, p)<<endl;
    return 0;
}