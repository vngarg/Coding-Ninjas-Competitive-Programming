#include<bits/stdc++.h>
using namespace std;

int lps(char str[]) {
    int n = strlen(str);
    int max = 1;
    int len = 0;

    for(int i=0;i<n;++i) {
        int l = i, r = i;

        while(l >= 0 && r < n && str[l] == str[r]) {
            int curr_len = r-l+1;
            ++len;
            if(curr_len > max) {
             	max = curr_len;
            }
            --l;
            ++r;
        }

        l = i;
        r = i+1;

        while(l >= 0 && r < n && str[l] == str[r]) {
            int curr_len = r-l+1;
            ++len;
            if(curr_len > max) {
             	max = curr_len;
            }
            --l;
            ++r;
        }
    }
    return len;
}

int main() {
    // cout<<"ENTER THE STRING"<<endl;
    string str;
    cin>>str;
    int n = str.length();
    char arr[n+1];
    strcpy(arr, str.c_str());
    // cout<<"THE LENGTH OF LONGEST STRING IS: "<<lps(str)<<endl;
    cout<<lps(arr);
    return 0;
}