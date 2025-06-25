// this is perfect implementation

#include<iostream>
using namespace std;


int findPivot(int arr[], int low, int high){
        int i = low;
        int j = high;
        int pivotIndex =i;

        while(i<j){
            while(arr[i]<=arr[pivotIndex] && i<=high-1)i++;
            while(arr[j]>=arr[pivotIndex] && j>=low+1)j--;
            if(i<j) swap(arr[i], arr[j]);
        }
        swap(arr[pivotIndex], arr[j]);
        return j;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int partitionIndex = findPivot(arr, low, high);
        quickSort(arr, low, partitionIndex-1);
        quickSort(arr, partitionIndex+1, high);
    }
}
int main(){
    
    int arr[] = {4,5,2,3,1,7,9,8, 90, 7676, 7162, 90,1};
    int size = sizeof(arr) / sizeof(arr[0]) ;
    quickSort(arr, 0, size-1);

    for (auto i:arr){
        cout << i << " ";
    }

}

// Time complexity will be : - Best O(N log n)  - worst O(n sq)
// Space complexity : O(1) if not considered the recursion start space 
// if recursive approach, O(log n )