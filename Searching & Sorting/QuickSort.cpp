#include<iostream>

using namespace std;

int Partition(int *arr , int start , int end) {
    int pivot = arr[end] , pIndex = start , i;
    for(i=start;i<end;++i) {
        if(arr[i] <= pivot) {
            swap(arr[i] , arr[pIndex]);
            ++pIndex;
        }
    }
    swap(arr[pIndex] , arr[end]);
    return pIndex;
}

void QuickSort(int *arr , int start , int end) {
    int index,i;
    if(start < end) {
        index = Partition(arr , start , end );
        QuickSort(arr , start , index - 1 );
        QuickSort(arr , index + 1 , end);
        for(i=start;i<end;++i)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
}

int main() {
    int size;
    cout<<"Enter the number of elements"<<endl;
    cin>>size;
    int arr[size] , i ;
    cout<<"Enter the elements to be Sorted"<<endl;
    for(i=0 ; i< size ; ++i )
        cin>>arr[i];

    QuickSort(arr , 0 , size-1);

    cout<<"Sorted Array is: ";

    for(i=0;i<size;++i)
        cout<<arr[i]<<" ";

    cout<<endl;
    return 0;
}