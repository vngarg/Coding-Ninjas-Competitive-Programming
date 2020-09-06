#include<bits/stdc++.h>
using namespace std;

void buildZ(int* z, string str) {
    int l = 0, r = 0;
    int n = str.length();

    for(int i=1;i<n;++i) {
        if(i > r) {
            l = i;
            r = i;
            while(r < n && str[r-l] == str[r])
                r++;
            z[i] = r - l;
            r--;
        } else {
            int k = i-l;
            if(z[k] <= r - i) {
                z[i] = z[k];
            } else {
                l = i;
                while(r < n && str[r-l] == str[r])
                    ++r;
                z[i] = r-l;
                r--;
            }
        }
    }
}

void searchString(string text, string pattern) {
    string str = pattern + "$" + text;
    int n = str.length();
    int* z = new int[n]();
    buildZ(z, str);
    cout<<"INDEXES ARE"<<endl;
    for(int i=0;i<n;++i) {
        if(z[i] == pattern.length()) {
            cout<<i - pattern.length() - 1 <<" ";
        }
    }
}

int main() {
    cout<<"ENTER THE STRING"<<endl;
    string pattern, text;
    cin>>text;
    cout<<"ENTER THE PATTERN"<<endl;
    cin>>pattern;
    searchString(text, pattern);
    return 0;
}