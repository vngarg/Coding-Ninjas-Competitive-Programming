#include<bits/stdc++.h>
using namespace std;

void generateTree(int* arr, int* tree, int start, int end, int treeNode) {
    if(start == end) {
        tree[treeNode] = arr[start];
        return ;
    }

    int mid = (start + end) / 2;
    generateTree(arr, tree, start, mid, 2*treeNode);
    generateTree(arr, tree, mid + 1, end, 2*treeNode + 1);
    tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode + 1]);
    return ;
}

void LazyLoad(int* tree, int* lazy, int low, int high, int start, int end, int currPos, int inc) {
    if(low > high)  
        return ;

    if(lazy[currPos] != 0) {
        tree[currPos] = tree[currPos] + lazy[currPos];

        if(low != high) {
            lazy[2*currPos] = lazy[2*currPos] + lazy[currPos];
            lazy[2*currPos+1] = lazy[2*currPos+1] + lazy[currPos];
        }
        lazy[currPos] = 0;
    }

    if(start > high || end < low) 
        return ;

    if(start <= low && high <= end) {
        tree[currPos] = tree[currPos] + inc;
        if(low != high) {
            lazy[2*currPos] = lazy[2*currPos] + inc;
            lazy[2*currPos + 1] = lazy[2*currPos + 1] + inc;
        }
        return ;
    }

    int mid = (low + high) / 2;
    LazyLoad(tree,lazy,low, mid, start, end, 2*currPos, inc);
    LazyLoad(tree,lazy,mid + 1, high, start, end, 2*currPos + 1, inc);
    tree[currPos] = min(tree[2*currPos], tree[2*currPos + 1]);

    return ;
}

void print(int* tree, int n) {
    cout<<endl<<"THE TREE VALUES ARE: "<<endl;
    for(int i=0;i<n;++i)
        cout<<tree[i]<<" ";

    cout<<endl;
    return ;
}

int main() {
    cout<<"ENTER THE NUMBER OF VALUES IN THE ARRAY:"<<endl;
    int n;
    cin>>n;
    int arr[n];

    cout<<"ENTER THE VALUES OF THE ARRAY: "<<endl;
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    int tree[3*n], lazy[3*n];

    for(int i=1;i<3*n;++i) {
        lazy[i] = tree[i] = 0;
    }

    generateTree(arr, tree, 0, n-1, 1);

    int start, end, value;
    cout<<endl<<"ENTER THE STARTING AND ENDING INDEX TO UPDATE AND THE INCREMENT VALUE: "<<endl;
    cin>>start>>end>>value;
    LazyLoad(tree, lazy, 0, n-1, start, end, 1, value);
    print(tree, 3*n);


    cout<<endl<<"ENTER THE STARTING AND ENDING INDEX TO UPDATE AND THE INCREMENT VALUE: "<<endl;
    cin>>start>>end>>value;
    LazyLoad(tree, lazy, 0, n-1, start, end, 1, value);
    print(tree, 3*n);

    return 0;
}