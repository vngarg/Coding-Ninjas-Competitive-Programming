// Enter the position for the Fibonacci Number. 

#include<bits/stdc++.h>
using namespace std;

void multiply(int A[2][2], int B[2][2]) {
    int a = A[0][0]*B[0][0] + A[0][1]*B[0][1];
    int b = A[0][0]*B[1][0] + A[0][1]*B[1][1];
    int c = A[1][0]*B[0][0] + A[1][1]*B[0][1];
    int d = A[1][0]*B[1][0] + A[1][1]*B[1][1];

    A[0][0] = a;
    A[0][1] = b;
    A[1][0] = c;
    A[1][1] = d;
}

void power(int A[2][2], int n) {
    if(n == 0 || n == 1)
        return;

    power(A, n/2);
    multiply(A,A);

    if(n%2 != 0) {
        int M[2][2] = {{1, 1}, {1, 0}};
        multiply(A,M);
    }
}

int Fib(int n) {
    int A[2][2] = {{1, 1}, {1, 0}};
    if(n == 0)  
        return 0;
    power(A,n-1);

    return A[0][0];
}

int main() {
    cout<<"Enter the Fibonacci place"<<endl;
    int n;
    cin>>n;
    cout<<Fib(n)<<endl;
    return 0;
}