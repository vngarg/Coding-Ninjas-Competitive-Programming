#include<bits/stdc++.h>
using namespace std;

int magicGrid(int** input, int r, int c) {
    int** output = new int*[r];
    for(int i=0;i<r;++i)
        output[i] = new int[c];
    output[r-1][c-1] = 1 - input[r-1][c-1];

    for(int i=r-2; i>=0;--i)
        output[i][c-1] = output[i+1][c-1] - input[i][c-1];
    
    for(int i=c-2;i>=0;--i)
        output[r-1][i] = output[r-1][i+1] - input[r-1][i];
    
    for(int i=r-2;i>=0;--i) {
        for(int j=c-2;j>=0;--j) {
            int possible = min(output[i+1][j], output[i][j+1]) - input[i][j];
            if(possible > 0 )
                output[i][j] = possible;
            else 
                output[i][j] = 1;
        }
    }

    int ans = output[0][0];
    delete [] output;
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int r,c,ele;
        cin>>r>>c;
        int** input = new int*[r];
        for(int i=0;i<r;++i)
            input[i] = new int[c];

        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j) {
                cin>>ele;
                input[i][j] = ele;
            }

        cout<<magicGrid(input, r, c)<<endl;
    }
    return 0;
}