#include<iostream>
using namespace std;

void merge(int arr[], int low, int mid , int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;

    while(left <= mid && right<=high){
// only here the sign will be changed to "<" (smaller then) to ">" (greater then)
        if(arr[left]>arr[right]){
            temp.push_back(arr[left]);
            left++;   
        }
        else{
            temp.push_back(arr[right]);
            right++;   
        }
    }

    while (left<=mid)
    {
        temp.push_back(arr[left]);
        left++;   
    }

    while (right<=high)
    {
        temp.push_back(arr[right]);
        right++;   
    }
    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main() {
    int arr[] = {12, 3, 5, 6, 1, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    for (int i : arr) {
        cout << i << " ";
    }
}
