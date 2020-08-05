#include<bits/stdc++.h>
using namespace std;

void printChoices() {
    cout<<"SELECT YOUR CHOICE:"<<endl;
    cout<<"1. GENERTATE TREE"<<endl;
    cout<<"2. PRINT SEGMENT TREE"<<endl;
    cout<<"3. EXIT"<<endl;
}

void generateTree(int* arr, int* tree, int start, int end, int treeNode) {
    if(start == end) {
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    generateTree(arr, tree, start, mid, 2*treeNode);
    generateTree(arr, tree, mid + 1, end, 2*treeNode + 1 );
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode + 1];
    return ;
}

void printTree(int* tree, int n) {
    cout<<"TREE:"<<endl;
    for(int i=0;i<n;++i)
        cout<<tree[i]<<" ";
    cout<<endl;
}

int main() {
    cout<<"Enter the number of values"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the values"<<endl;
    int arr[n], tree[2*n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    int choice;
    while(choice!=0) {
        printChoices();
        cout<<"ENTER THE OPERATION"<<endl;
        cin>>choice;

        switch(choice) {
            case 1:
                generateTree(arr, tree, 0, n-1, 1);
                cout<<"TREE GENERATED"<<endl;
                break;
            case 2:
                printTree(tree, 2*n);
                break;
            case 3:
                return 0;
        }
    }
    return 0;
}