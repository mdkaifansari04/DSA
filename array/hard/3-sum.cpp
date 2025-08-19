#include <iostream>
#include<set>
#include<unordered_map>
using namespace std;

// brute force approach 
// time complexity : O(n ^3)
// space complexity : O(n x3)

//* so the concept was just to make sure all the elements three combination gives the sum as 0
vector<vector<int>> threeSumBrute(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> res;
    vector<vector<int>> ans;
    for (int i=0; i<n; i++){
        for(int j=i+1; j <n; j++){
            for (int k=j+1; k<n; k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    res.insert(triplet);
                }
            }
        }
    }


    for(auto &triple:res) ans.push_back(triple);
    return ans;
}


vector<vector<int>> threeSumBetter(vector<int>& nums) {   
    int n = nums.size();
    set<vector<int>> uniq;

    for (int i=0; i<n; i++) {
        set<int> hashSet;
        for(int j=i+1; j<n; j++) {

            int k = - (nums[i]+nums[j]);
            if(hashSet.find(k) != hashSet.end()) {
                vector<int> triplet = {nums[i], nums[j], k };
                sort(triplet.begin(), triplet.end());
                uniq.insert(triplet);
            }
            hashSet.insert(nums[j]);
        }
        hashSet.clear();
    }

    vector<vector<int>> ans(uniq.begin(), uniq.end());
    return ans;

}

int main() {
    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>>res = threeSumBetter(arr);
    for(auto it:res) {
        for(auto i:it) cout << i << " ";
        cout<<endl;
    }

    return 0;
}