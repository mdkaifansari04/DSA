#include<iostream>
#include<vector>

using namespace std;

vector<int> reversedArr;

void reverseArray(vector<int>& arr, int l, int r){
    if(l>=r) return;
    swap(arr[l], arr[r]);
    reverseArray(arr, l+1, r-1);
}

int main(){
    vector<int> arr ={1,2,3,4,5};
    reverseArray(arr, 0, arr.size()-1);   
    for(auto i : arr){
        cout << i<<" ";
    }
}