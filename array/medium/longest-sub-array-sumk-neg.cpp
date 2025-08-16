#include<iostream>
#include<unordered_map>
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
// optimal approach by me.
// time complexity : O(N) for the loop and for unordered_map we have average and best case would be O(1) and worst case it would be O(N) 
// *in conclusion the time complexity : O(N x log N)  
// *space complexity: O(n) (for worst case)

int longestSubArrayOptimal(vector<int> &nums, int k){
    int n=nums.size();  
    unordered_map<long, int> map;
    int prefixSum = 0;
    int count = 0;

    // pushing the first element with the 0 prefix sum which we will be needing for checking
    map.insert({0,1});
    for(int i=0; i<n; i++){
        prefixSum += nums[i];
        if(map.find(prefixSum-k) != map.end()){
            count+= map[prefixSum-k];
        }   
        if(map.find(prefixSum) != map.end()) map[prefixSum] +=1;
        else map.insert({prefixSum, 1});
    }
    return count;
}

int longestSubArrayOptimalStriver(vector<int> &nums, int k){
    int n=nums.size();  
    unordered_map<long, int> map;
    int prefixSum = 0;
    int count = 0;

    // pushing the first element with the 0 prefix sum which we will be needing for checking
    map.insert({0,1});
    for(int i=0; i<n; i++){
        prefixSum += nums[i];
        count+= map[prefixSum-k];
        map[prefixSum] +=1;
    }
    return count;
}

/* 
! Why Striver sols is more efficient
* count += map[prefixSum-k];
* map[prefixSum] += 1;

In C++, unordered_map’s operator[] will create a key with value 0 if it doesn’t exist.
So if prefixSum-k isn’t in the map, map[prefixSum-k] just gives 0 (no crash).
Same for map[prefixSum] += 1;. If the key doesn’t exist, it’s created with 0 and incremented to 1.
So Striver is leveraging default initialization. That’s why his code is shorter—he doesn’t bother checking because he knows the map handles it.
*/
int main(){
    vector<int> arr = {1,2,3,-3,1,1,1,2,4,2,-3};
    int r = longestSubArrayOptimalStriver(arr, 3);
    cout << r << endl;
}