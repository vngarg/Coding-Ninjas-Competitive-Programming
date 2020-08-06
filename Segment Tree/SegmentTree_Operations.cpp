#include<bits/stdc++.h>
using namespace std;

void printChoices() {
    cout<<"SELECT YOUR CHOICE:"<<endl;
    cout<<"1. GENERTATE TREE"<<endl;
    cout<<"2. PRINT SEGMENT TREE"<<endl;
    cout<<"3. UPDATE TREE"<<endl;
    cout<<"4. QUERY ON TREE:"<<endl;
    cout<<"5. EXIT"<<endl;
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

void updateTree(int* arr, int* tree, int start, int end, int treeNode, int index, int value) {
    if(start == end) {
        arr[index] = value;
        tree[treeNode] = value;
        return;
    }

    int mid = (start + end) / 2;
    if(index <= mid) {
        updateTree(arr, tree, start, mid, 2*treeNode, index, value);
    }  else {
        updateTree(arr, tree, mid + 1, end, 2*treeNode + 1, index, value);
    }

    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode + 1];
}

int query(int* tree, int start, int end, int treeNode, int left, int right) {

    if(start > right || end < left )
        return 0;

    if(start >= left && end <= right)
        return tree[treeNode];

    int mid = (start + end) / 2;
    int ans1 = query(tree, start, mid, 2*treeNode, left, right);
    int ans2 = query(tree, mid + 1, end, 2*treeNode + 1, left, right);
    return ans1 + ans2;
}

void printTree(int* tree, int n) {
    cout<<"TREE:"<<endl;
    for(int i=1;i<n;++i)
        cout<<tree[i]<<" ";
    cout<<endl<<endl;
}

int main() {
    cout<<"Enter the number of values"<<endl;
    int n, index, value, left, right, ans;
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
                cout<<"TREE GENERATED"<<endl<<endl;
                break;
            case 2:
                printTree(tree, 2*n);
                break;
            case 3:
                cout<<"ENTER THE ARRAY INDEX TO BE UPDATED:"<<endl;
                cin>>index;
                cout<<"ENTER NEW VALUE:"<<endl;
                cin>>value;
                updateTree(arr, tree, 0, n-1, 1, index, value);
                printTree(tree, 2*n);
                break;
            case 4:
                cout<<"ENTER START AND END INDEX FOR QUERY"<<endl;
                cin>>left>>right;
                ans = query(tree, 0, n-1, 1, left, right);
                cout<<"ANSWER OF QUERY: "<<ans<<endl<<endl;
                break;
            case 5:
                return 0;
        }
    }
    return 0;
}