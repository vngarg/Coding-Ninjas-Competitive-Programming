#include<bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPossible(int n, int row, int column) {
    for(int i=row-1;i>=0;--i) {
        if(board[i][column] == 1)
        return false;
    }

    for(int i=row-1, j=column -1;i>=0 && j>=0; --i, --j) {
        if(board[i][j] == 1)
        return false;
    }

    for(int i=row-1, j=column+1; i>=0 && j<n;--i, ++j) {
        if(board[i][j] == 1)
        return false;
    }

    return true;
}

void place(int n, int row) {
    if(row == n) {
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                cout<<board[i][j]<<" ";
        cout<<endl;
        return ;
    }

    for(int i=0;i<n;++i) {
        if(isPossible(n, row, i)) {
            board[row][i] = 1;
            place(n, row+1);
            board[row][i] = 0;
        }
    }
    return ;
}

void placeNQueens(int n) {
    memset(board, 0, 11*11*sizeof(int));

    place(n, 0);
    return ;
}

int main() {
    cout<<"Enter Number of Rows"<<endl;
    int n;
    cin>>n;
    placeNQueens(n);
    return 0;
}