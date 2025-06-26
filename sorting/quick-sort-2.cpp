// this is perfect implementation

#include<iostream>
using namespace std;

// quick sort : it is the sorting where we pick a pivot element and place that in its correct position, so that all the elemnet lesser is at the left and greater at the right.
// and then do the same for other, sub array as well, 
// the base condition would be when the low == hight [means only one element will be there.]


int findPivot(int arr[], int low, int high){
        int i = low;
        int j = high;
        int pivotIndex =i;

        // do until i < j [means i doesnot cross j]
        while(i<j){
            // if the ith element is lesser we dont do any thing, go on [as we want that the element lesser should be at left]
            while(arr[i]<=arr[pivotIndex] && i<=high-1)i++;
            // if the jth elemnet is bigger no issue, go on to left side, if not then come out
            while(arr[j]>=arr[pivotIndex] && j>=low+1)j--;

            // the element which is at the position where [i does not cross each other, we need to swap bo the elements and place it in its correct position]
            if(i<j) swap(arr[i], arr[j]);
        }
        // if j cross i [while loop will be break, and the position will be swap with the pivot element, with the j]
        swap(arr[pivotIndex], arr[j]);
        return j; // return the pivot position now, which will be partition index.
}

void quickSort(int arr[], int low, int high){
    // no need for base condition or return, if condition will act as the base condition here.
    if(low<high){
        int partitionIndex = findPivot(arr, low, high);
        // do the same for others half as well
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