#include<iostream>
using namespace std;


void quickSort(int arr[],int low, int high){
    int i=low;
    int j=high;
    int pivot = low;
    int partitionIndex = pivot;

    if(low >= high) return;
    // doing the comparison until the low < high, the point is to srt the array in such position that the elements at the left should be lesser and element at right should be greater then pivot.
    while(i<=j){
        // if the elemets are smaller then okay go ahead
        while(arr[i] <= arr[pivot]) i++;
        // if the elemets are greater then okay go ahead
        while(arr[j]>= arr[pivot]) j--;
        if (i <= j)swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[pivot]);
    partitionIndex = j;
    quickSort(arr, low, partitionIndex-1);
    quickSort(arr, partitionIndex+1, high);
}

int main(){

    int arr[] = {4,5,2,3,1,7,9,8};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size-1);
    for (auto i:arr){
        cout << i << " ";
    }
}