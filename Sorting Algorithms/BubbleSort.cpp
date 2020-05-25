#include<iostream>

using namespace std;

int *BubbleSort(int arr[] , int length) {
    int i , j , temp;
    for(i=length-1; i >=0;--i) {
        for(j=i-1;j>=0;--j) {
            if(arr[j] > arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int main () {
    int size , i , *p;
    cout<<"Enter the Size of Array"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array"<<endl;
    for(i=0;i<size;++i)
        cin>>arr[i];

    p = BubbleSort(arr , size);

    cout<<"Sorted Array is: "<<" ";
    for(i=0;i<size;++i)
    cout<<arr[i]<< " ";

    cout<<endl;
    return 0;
}