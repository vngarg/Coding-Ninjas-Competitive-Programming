#include <iostream>
#include<array>

using namespace std;

int *InsertionSort(int arr[] , int length) {
    int i , var , j ;
    for(i=1 ; i<length ; ++i) {
        var = arr[i];
        for(j=i-1 ; j>=0 ; --j) {
            if(arr[j] > var)
                arr[j+1] = arr[j];
            else 
                break;
        }
        arr[j+1] = var;
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
    
    p = InsertionSort(arr , size);

    cout<<"Sorted Array is :";

    for(i=0 ; i< size ; ++i)
        cout<<*( p+i )<<" ";

    cout<<endl;

    return 0;
}