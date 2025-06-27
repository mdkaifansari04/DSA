#include<iostream>
using namespace std;

// time complexity : O(n)
// space complexity : O(1)
void rotateArrayLeft (vector<int> &arr)
{
    int size = arr.size();
    int temp = arr[0];
    for (int i=0; i<size-1; i++){ 
        arr[i] = arr[i+1];
    }
    arr[size-1] = temp;
    for (auto i:arr) cout << i << " ";
}

int main(){
    vector<int> arr= {12,34,45,65,6,8};
    rotateArrayLeft(arr);
}