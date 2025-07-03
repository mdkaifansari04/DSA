#include<iostream>
using namespace std;


// optimal solution
// time complexity : O(n)
// space complexity : O(1)

bool isArraySorted(int arr[], int size){
    int isSorted = true;
    for (int i=0; i<size-1; i++){
        if(arr[i]>arr[i+1]) isSorted = false;
    }
    return isSorted;
}

int main(){
    int arr[] = {1,2,3,4, 5,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    bool res = isArraySorted(arr,size);
    if(res) cout << "Array is sorted";
    else cout << "Array is not sorted";

}