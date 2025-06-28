#include<iostream>
#include<algorithm>
using namespace std;

//brute force approach
//time complexity : O(3n) ~ O(n)
// space complexity: O(n) using temp vector of size n

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k=k%n;

    //making a temp vector for storing elements
    vector<int> temp;

    for(int i=0; i<n-k;i++){
        temp.push_back(nums[i]);
    }

    for (int i=0; i<n-k; i++){
        nums[i] = nums[n-k+i];
    }

    for(int i=0; i<temp.size(); i++){
        nums[k+i] = temp[i];
    }

}

void leftRotateByD(vector<int> &arr, int d){
    vector<int> temp;
    int n = arr.size();

    //edge case handled
    if(n==0)return;
    d= d%n;

    //store the element in temp
    for (int i=0; i<d; i++){
        temp.push_back(arr[i]);
    }

    //shift the element 
    for (int i=0; i<n; i++){
        arr[i] = arr[i+d];
    }

    //copy the element back
    for (int i=0; i<d; i++){
        arr[n-d+i] = temp[i];
    }

}

void reverseArr (vector<int>&nums, int start, int end){
    while (start<end)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

void rotateUsingReverse (vector<int> &nums, int k){
    int n = nums.size();
    k=k%n;
    reverseArr(nums, 0, k-1);
    reverseArr(nums, k,n-1);
    reverseArr(nums, 0,n-1);
}
int main(){
    vector<int> arr= {-1,-100,3,99};
    // leftRotateByD(arr, 9);
    // rotate(arr, 3);
    rotateUsingReverse(arr, 2);
    for (auto i:arr) cout << i << " ";
}