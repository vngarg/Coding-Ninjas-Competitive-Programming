#include<bits/stdc++.h>
using namespace std;

int subSequence(string str, string output[]) {
    if(str.empty()) {
        output[0] = "";
        return 1;
    }

    string subArray = str.substr(1);
    int length = subSequence(subArray, output);
    for(int i=0;i<length; ++i) {
        output[i+length] = str[0] + output[i];
    }
    return 2*length;
}

int main() {
    cout<<"Enter The String"<<endl;
    string str;
    cin>>str;
    int length = pow(2, str.length());
    string* output = new string[length];

    subSequence(str, output);
    for(int i=0;i<length; ++i)
        cout<<output[i]<<endl;
    
    return 0;
}