#include<iostream>

using namespace std;

int *SelectionSort(int arr[] , int length) {
    int s , i , index , j , temp;

    for(i=0;i<length;++i) {
        s=arr[i];
        index = i;
        for(j=i+1;j<length;++j) 
            if(arr[j] < s) {
                s=arr[j];
                index = j;
            }
        
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;     
    }

    return arr;
}

int main() {
    int size , i , *p;
    cout<<"Enter the Size of Array"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array"<<endl;
    for(i=0;i<size;++i)
        cin>>arr[i];

    p = SelectionSort(arr , size);

    cout<<"Sorted Array is: "<<" ";
    for(i=0;i<size;++i)
        cout<<arr[i]<<" ";

    cout<<endl;

    return 0;
}