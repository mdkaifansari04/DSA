#include<iostream>
using namespace std;

// BRUTE FORCE APPROACH 
// time complexity: O(n sq)
// space complexity: O(1)

vector<int> longestSubArrayBrute(vector<int> &nums, int k){
    int n=nums.size();
    int maxLength=0;
    int count = 0;
    int sum = 0;
    int start=0;
    int end=0;
    vector<int> longestArray;
   for(int i=0; i<n;i++){
    sum+=nums[i];
    for (int j=i+1; j<n;j++){
        sum+=nums[j];
        if(sum == k && count > maxLength){
            maxLength = count;
            start = i;
            end = j;
        }
        count++;
    }
    sum=0;
    count =0;
   }
   for(int i=start; i<=end; i++){
    longestArray.push_back(nums[i]);
   }
   return longestArray;
}   

vector<int> longestSubArrayBetter(vector<int> &nums, int k){
    int n = nums.size();
    int start =0;
    int end = 0;
    vector<int> longestSubArray;
    int sum = 0;
    for (int i=0; i<n; i++){
        sum +=nums[i];
    }
    int x = 0;
    // for(int i=0; i<n; i++){
    //     x+=nums[i];
    //     if(sum-x == k){
    //         start=ibr;
    //         end = n-1;
    //         break;
    //     }
    // }

    for (int i=start; i<=end; i++){
        longestSubArray.push_back(nums[i]);
        cout << nums[i] << " ";
    }
    return longestSubArray;
}   

// time complexity : O(2n)
// space complexity : O(1)

int longestSubArrayOptimal(vector<int> &nums, int k){
    int n=nums.size();
    int i=0;
    int j=0;

    int maxLength =0;
    int sum = 0;

    while (j<n)
    {
        sum+=nums[j];
        j++;

        if(sum==k){
            maxLength = max(maxLength , j-i);
        }
        while(sum>k && i<j){
            sum-=nums[i];
            i++;
        }
    }
    return maxLength;   
}


int main(){
    vector<int>arr={1,2,3,1,2,1,1,1,1,1,5,0};
    // vector<int> subArr = longestSubArrayBrute(arr, 5);
    // vector<int> subArr = longestSubArrayBetter(arr, 5);
    int length = longestSubArrayOptimal(arr, 5);
    cout<< length << endl;
}