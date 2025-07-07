#include<iostream>
using namespace std;


// brute approach
// time complexity : O(n^3)
// space complexity : O(1)

int maximumSubArraySumBrute(vector<int> &nums){
    int n = nums.size();
    int sum=0;
    int maximumSum=INT_MIN;
    for (int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            sum=0;
            for (int k=i; k<j; k++) sum+=nums[k];
            maximumSum = max(maximumSum, sum);
        }
    }

    return maximumSum;
}


// optimal approach 
// time complexity: O(n^2)
// space complexity : O(1)

int maximumSubArraySumBetter(vector<int> &nums){
    int n = nums.size();
    int sum=0;
    int maximumSum=INT_MIN;

    // using two loops to check for the each subarray, adding up and if the 
    for (int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            sum+=nums[j];
            maximumSum = max(maximumSum, sum);
        }
        sum=0;
    }

    return maximumSum;
}


//* algorithm used : Kadane's algorithm
//* time complexity : O(n)
//* space complexity : O(1)
int maximumSubArraySumOptimal(vector<int>&nums){
    int n=nums.size();
    int maximumSum=0;
    int sum=0;

    // for each iteration we will add the sum with the number, we know we have negative as well, 
    // for each sum we check the condition of whether it is negative set it to zero
    // if the sum is greater then max, then add that up.
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum < 0)sum=0;
        if(sum > maximumSum) maximumSum = sum;
    }

    return maximumSum;
}

vector<int> maximumSubArraySumOptimalArray(vector<int>&nums){
    int n=nums.size();
    int maximumSum=0;
    int sum=0;
    int ansStart = 0;
    int ansEnd =0;
    int start;
    // for each iteration we will add the sum with the number, we know we have negative as well, 
    // for each sum we check the condition of whether it is negative set it to zero
    // if the sum is greater then max, then add that up.
    for(int i=0;i<n;i++){
        if(sum ==0) start = i;

        sum+=nums[i];
        if(sum < 0)sum=0;
        if(sum > maximumSum) {
            ansEnd = i;
            ansStart = start;
            maximumSum = sum;
        }
    }

    return {ansStart, ansEnd};
}


int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    // int res = maximumSubArraySumOptimal(arr);
    // cout << res << endl;

    vector<int> res = maximumSubArraySumOptimalArray(arr);
    cout << res[0] << " " << res[1]  << endl;
}