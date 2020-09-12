#include<bits/stdc++.h>
using namespace std;

class trieNode {
public:
    trieNode* left;
    trieNode* right;
};

void insert(int n, trieNode* head) {
    trieNode* curr = head;
    for(int i = 31;i>=0;--i) {
        int b = (n>>i)&1;
        if(b == 0) {
            if(!curr->left) {
                curr->left = new trieNode();
            }
            curr = curr->left;
        } else {
            if(!curr->right) {
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }
}

int FindMaxXOR(int* arr, trieNode* head, int n) {
    int max_XOR = INT_MIN;
    for(int i = 0;i<n;++i) {
        int value = arr[i];
        trieNode* curr = head;
        int curr_XOR = 0;
        for(int j = 31;j>=0;--j) {
            int b = (value>>j)&1;
            if(b == 0) {
                if(curr->right) {
                    curr_XOR = curr_XOR + pow(2, j);
                    curr = curr->right;
                } else {
                    curr = curr->left;
                }
            } else {
                if(curr->left) {
                    curr_XOR = curr_XOR + pow(2,j);
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }
        }
        if(curr_XOR > max_XOR)
            max_XOR = curr_XOR;
    }
    return max_XOR;
}

int main() {
    trieNode* head = new trieNode();

    cout<<"Enter size of Array"<<endl;
    int n;
    cin>>n;
    cout<<"Enter array elements"<<endl;
    int arr[n];
    for(int i=0;i<n;++i) {
        cin>>arr[i];
        insert(arr[i], head);
    }
    cout<<"Max XOR Value is:"<<endl<<FindMaxXOR(arr, head, n)<<endl;
    return 0;
}