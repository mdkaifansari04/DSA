#include<iostream>
using namespace std;

// brute force approach 
// time complexity : O(n)
// space complexity : O(n)
vector<int> getLeaderInArrayBrute(vector<int> &nums){
    int n = nums.size();
    vector<int> leader; 
    int isLeader = true;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if(nums[j] > nums[i]){
                isLeader = false;
                break;
            }
        }
        if(isLeader) leader.push_back(nums[i]);
        isLeader = true;
    }
    return leader;
}

int main(){
    vector<int> arr ={10,22,12,3,0,6};
    vector<int> res = getLeaderInArrayBrute(arr);
    for(auto i:res) cout << i << " ";
}