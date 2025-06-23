#include<iostream>
using namespace std;

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
//       2 12 34 43 7 1 
    for (auto i:arr){
        cout << i << " ";
    }

}