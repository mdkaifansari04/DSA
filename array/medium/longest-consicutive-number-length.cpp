#include<iostream>
#include<algorithm>

using namespace std;

bool linearSearch (vector <int> &arr, int num){
    int n = arr.size();
    bool isFound = false;
    for (int i=0; i<n; i++){
        if(arr[i] ==num) isFound = true;
    }
    return isFound;
}

// brute approach 
// time complexity : near about O(n) sq
// space complexity : O(1)
int longestConsecutiveNumberLengthBrute(vector <int> &nums){
    int n=nums.size();
    int longest = 1;

    for (int i=0; i<n; i++){
        int x = nums[i];
        int count = 1;

        while(linearSearch(nums, x+1) == true){
            x+=1;
            count+=1;
            if(count > longest) longest = count;
        }
    }
    return longest;
}

//better approach 
// time complexity : O(n) + O(n log n)
// space complexity : O(1)

int longestConsecutiveNumberLengthBetter(vector <int> &nums){
    if(nums.empty()) return 0;
    sort(nums.begin(), nums.end());

    int longest = 1;
    int count = 1;

    for(int i=1; i<nums.size(); i++){
        if(nums[i] == nums[i-1]) continue;
        if(nums[i] == nums[i-1] +1) {
            count ++;
        }else{
            count = 1;
        }
        longest = max(count, longest);
    }

    return longest;
}



int main(){
    vector<int>arr={100,102,100,101,101,4,3,2,3,2,1,1,1,2};

    int n = longestConsecutiveNumberLengthBetter(arr);
    cout<< endl;
    cout << n ;
}