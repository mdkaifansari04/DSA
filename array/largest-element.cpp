#include<iostream>
using namespace std;

// time complexity : O(n)
// space complexity : O(1) as we are taking static size array
int getLargestElementOptimal (int arr[], int size)
{
    int largest =arr[0];
    for (int i=0; i<size; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
}

int getPartitionIndex (int arr[], int low, int high){
    int i=low;
    int j=high;
    int pivotIndex = low;


    while(i<j){
        while (arr[i] <= arr[pivotIndex] && i<=high-1) i++;
        while(arr[j] >= arr[pivotIndex] && j>= low+1) j--;
        if(i<j) swap(arr[i], arr[j]);
    }

    swap(arr[pivotIndex], arr[j]);
    return j; // pivot index
}


// brute force approach
// time complexity : O(n log n)
// space complexity : O(1)
void qs(int arr[], int low, int high){
    if(low<high){
        int partitionIndex = getPartitionIndex(arr, low, high);
        qs(arr, low,partitionIndex-1);
        qs(arr, partitionIndex+1, high);
    }
}

int getLargestElementBrute(int arr[], int size){
    qs(arr, 0, size-1);
    int lb = arr[size-1];
    return lb;
}

int main()
{
    int arr[] = {1,23,5,67,100};
    int size = sizeof(arr) / sizeof(arr[0]);

    // brute force approach 
    int lb = getLargestElementBrute(arr, size);
    cout << "Largest with brute force : " << lb << endl;

    // optimal approach
    int lo = getLargestElementOptimal(arr, size); // O(n)
    cout << "Largest element : " << lo << endl;
}