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


vector<int> longestSubArrayOptimal(vector<int> &nums, int k){
    
}   


int main(){
    vector<int>arr={1,2,3,1,2,1,1,1,1,1,5,0};
    vector<int> subArr = longestSubArrayBrute(arr, 5);
}