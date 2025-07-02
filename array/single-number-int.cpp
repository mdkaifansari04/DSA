#include<iostream>
#include <vector>
#include <algorithm>
#include<map>

using namespace std;

int maxElement(vector<int> &nums){
    int max = nums[0];
    for(auto i : nums){
        if(i > max) max = i;
    }
    return max;
}

// brute force approach
// time complexity : O(n+n+n+n) = O(4n) = O(n)
// space complexity : O(n+1)

int singleNumber(vector<int>& nums) {
    int n = nums.size();
    int maxVal = maxElement(nums);
    vector<int> hashArr(maxVal+1, 0);

    for (int i=0; i<n; i++){
        hashArr[nums[i]]++;
    }

    int min = 0;
    for(auto i:hashArr) cout << i << " ";
    for (int i=0; i<maxVal+1; i++){
        if(hashArr[i]==1) min = i;
    }
    return min;
}

int singleNumberBetter(vector<int> &arr){
    unordered_map<int,int> pairs;
    for (int i=0;i<arr.size(); i++){
        pairs[arr[i]] +=1;
    }
    int single = 0;

    for (auto i:pairs) {
        if(i.second==1) single = i.first;
    }
    return single;
}

// time complexity : O(n)
// space complexity : O(1)

int singleNumberOptimal(vector<int> &nums){
    int xorResult =0;
    for (int i=0; i<nums.size();i++){
        xorResult = xorResult ^ nums[i];
    }
    return xorResult;
}
int main(){
    vector<int> a = {4,1,2,1,2};
    // int single = singleNumber(a);
    // cout<<"single : " << single;

    // int single = singleNumberBetter(a);
    // cout<<"single : " << single;
    int single = singleNumberOptimal(a);
    cout<<"single : " << single;
}