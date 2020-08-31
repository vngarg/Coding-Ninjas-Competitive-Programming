#include<bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {
    int n = s.length(), m = p.length();

    for(int i=0;i<=(n-m);++i) {
        bool matchFound = true;
        for(int j=0;j<m;++j) {
            if(s[i+j] != p[j]) {
                matchFound = false;
                break;
            }
        }

        if(matchFound)
            return true;
    }
    return false;
}

int main() {
    cout<<"Enter the main String"<<endl;
    string s;
    cin>>s;
    cout<<"Enter the String to Search"<<endl;
    string p;
    cin>>p;

    cout<<isMatch(s, p)<<endl;   

    return 0;
}