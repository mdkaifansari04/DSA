#include<iostream>
using namespace std;

void insertionSort(int arr[], int size){
    for (int i=0; i<size;i++){
        int j=i;
        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}
int main(){
    int arr [] = {12,34,4,6,1, 100,89, 23,4, 9};
    int size = 10;
    insertionSort(arr,size);
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}