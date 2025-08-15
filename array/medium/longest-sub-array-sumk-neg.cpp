#include<iostream>
using namespace std;

// brute approach, implemented by me
// time complexity : O(n^2)
// space complexity : O(1)
int longestSumSubArray (vector<int> &nums, int k){
    int n=nums.size();
    int count =0;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum=0;
        for(int j=i; j<n; j++){
            sum+=nums[j];
            if(sum == k) count++;
        }
    }
    return count;
}
int main(){
    vector<int> arr = {1,2,3,-3,1,1,1,2,4,2,-3};
    int r = longestSumSubArray(arr, 3);
    cout << r << endl;
}