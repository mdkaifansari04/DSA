#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size){
    int pos=0;
    while(pos<size){
        for (int i=0; i<size-pos-1; i++){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
        pos++;
    }

}
int main(){

    int arr [] = {12,34,4,6,1, 100,89, 23,4, 9};
    int size = 10;
    bubbleSort(arr,size);
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
 }