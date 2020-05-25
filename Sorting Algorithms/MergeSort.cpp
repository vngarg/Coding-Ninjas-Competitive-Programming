#include<iostream>

using namespace std;

void MergeFunction(int arr[] , int start1 , int end1 , int start2 , int end2 ) {
    int *p1 = &start1, *p2 = &start2 , finalarr[end1 + end2 + 2] , index = 0 ;

    while(p1 || p2) {
        if(p1 >= p2) {
            finalarr[index] = *p1;
            p1 = p1 + 1 ;
        } else {
            finalarr[index] = *p2;
            p2 = p2 + 1;
        }
        ++index;
    }

    for( index = 0 ; index < end1+end2+2 ; ++index)
        cout<<finalarr[index]<<" ";
}

void SplitFunction(int arr[] , int start , int end) {
    int mid;
    mid = (start + end) / 2 ;
    if(start != end) {
        SplitFunction(arr , start , mid ) ; 
        SplitFunction(arr , mid + 1 , end);
        MergeFunction(arr , start , mid , mid + 1 , end );
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

    SplitFunction(arr , 0 , size-1);

    return 0;
}