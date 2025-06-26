#include<iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int i = low;
    int j = mid+1;
    vector<int> temp;

    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid) temp.push_back(arr[i++]);
    while(j<=high) temp.push_back(arr[j++]);

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}

void ms(int arr[], int low,int high ){
    if(low==high) return;
    int mid = (low+high)/2;
    ms(arr, low, mid);
    ms(arr, mid+1, high);
    merge(arr, low, mid, high);
}

// time complexity : O(N log N)
void secondLargestBrute (int arr[], int size){
    // pass 1: sorting the element and finding the largest number
    ms(arr, 0, size-1);
    int largest = arr[size-1];
    // pass 2: looping the array and the getting the second largest from the largest element
    int secondLargest = arr[0];

    for (int i=size-1; i>=0; i--){
        if(arr[i] != largest && secondLargest <arr[i]){
            secondLargest = arr[i];
        }
    }
    cout<<"Largest : "<<largest << endl;
    cout<<"Second Largest :" << secondLargest << endl;

}

// time complexity : O(2N)
void secondLargestBetter (int arr[], int size){
    int largest = arr[0];

    //getting the real largest
    for (int i=0; i<size; i++)
        if(arr[i]>largest) largest = arr[i];

    int secondLargest = arr[0];
    for (int i=0; i<size; i++)
        if(arr[i]<largest && arr[i]>secondLargest) secondLargest = arr[i];

    cout<<"Largest : "<<largest << endl;
    cout<<"Second Largest :" << secondLargest << endl;
}
// time complexity : O(N)
void secondLargestOptimal (int arr[], int size){

    int largest = arr[0];
    int secondLargest = -1;

    for(int i=0; i<size; i++){
        if(arr[i]>largest){
            secondLargest = largest;
            largest = arr[i];
        }
        if(arr[i]<largest && arr[i]>secondLargest){
            secondLargest = arr[i];
        }
    }

    cout<<"Largest : "<<largest << endl;
    cout<<"Second Largest :" << secondLargest << endl;
}
int main(){
    int arr[] = {10000,23,5,67,100};
    int size = sizeof(arr) / sizeof(arr[0]);

    // secondLargestBrute(arr, size);s
    // secondLargestBetter(arr, size);
        secondLargestOptimal(arr, size);

}


