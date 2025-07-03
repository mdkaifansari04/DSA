#include<iostream>
using namespace std;

// brute
// time complexity : O(n sq)
// space complexity : O(1)

bool exitsTwoSumBrute (vector<int> &nums, int k){
    int n=nums.size();
    int sum =0;
    // vector<int > temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            if(nums[i] != nums[j] && nums[i] + nums[j] == k){
                // if i need to send the index
                // temp.push_back(i);
                // temp.push_back(i);
                // return temp;
                return true;
                break;
            }
        }
    }
    return false;
    // return temp (with a null)
}
bool exitsTwoSumBetter (vector<int> &nums, int k){
    int n=nums.size();
    int sum =0;
    for(int i=0; i<n; i++){
        // why j = i+1 ?
        // [2,6,7,8,10]
        // because if we do 2+6 before then again doing 6+2 makes no sense and takes extra time.
        for(int j=i+1; j<n;j++){
            if(nums[i] + nums[j] == k){
                return true;
                break;
            }
        }
    }
    return false;
}

bool exitsTwoSumBetter2(vector<int> &nums, int k)

int main(){ 
    vector<int>arr={2,7,11,15};
    bool result = exitsTwoSumBetter(arr, 22);
    cout << result;
}