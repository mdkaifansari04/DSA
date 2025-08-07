#include<iostream>
using namespace std;

// brute force approach 
// time complexity : near about O(n) sq
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

//optimal approach 
// time complexity: O(n)
// space complexity: near about O(n)
vector<int> getLeaderInArrayOptimal(vector<int> &nums){
    int n = nums.size();
    vector<int> leader;     
    int max = 0;
    for (int i=n; i>=0; i--){
        if(nums[i] > max) {
            max = nums[i];
            leader.push_back(nums[i]);
        }
    }
    return leader;
}

int main(){
    vector<int> arr ={10,22,12,3,0,6};
    vector<int> res = getLeaderInArrayOptimal(arr);
    for(auto i:res) cout << i << " ";
}