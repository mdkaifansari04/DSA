#include<iostream>
using namespace std;

/*
Merge sort: it is the method where we divide the array and merge it in term of sorted order. 

step 1: first we call recursive to the same fn for dividing and having a base condition as (when low == high then return)
step 2: after both the arrays are splited and merge with checking the highest and lowest element after it. (this way a that splited part will get sorted and so on for others too)
step 3: the merge fn have a temp array which basically have the sorted array of two un-sorted array, 

TIME COMPLEXITY : O[ N x Log n (base 2) ] as N is divided mutiple times by 2. 
*/

void merge(int arr[], int low, int mid , int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;

    while(left <= mid && right<=high){
        if(arr[left]<arr[right]){
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
