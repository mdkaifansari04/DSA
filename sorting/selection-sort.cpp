#include<iostream>
using namespace std;

// step 1: in selection sort we do select an element and at index 0 (let suppose ) and check if this is the minimum element in the entire array. 
// step 2: if this is the minimum (do anything)
// step 3: if it is greater then any element, then store that element index in the min. 
// step 4: after all the comparison done, we will just swap the current element from the minimum element. 
// step 5: if we select the current element {i} which is the actual minimum (then it will be swap to its own self and nothing happens)

void selection_sort(int arr[], int size){
 for (int i=0; i<size; i++){
    int min = i;
    int index = i+1;

    while(index<size)
    {
        if(arr[min] > arr[index]){
            min = index;
        }
        index++;
    }

    swap(arr[i], arr[min]);
 }

}
int main(){
    int arr[] = {12,34,43,1,2,7};
    selection_sort(arr, 6);
    for (auto i:arr){
        cout << i << " ";
    }

}