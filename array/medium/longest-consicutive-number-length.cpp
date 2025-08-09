#include<iostream>
#include<algorithm>
#include<unordered_set>
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
// time complexity : O(n) + O(n log n). So O(n log n) + O(n) simplifies to O(n log n).
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

// optimal approach 
// time complexity : O(n) + O(n) == O(n)
// space complexity : closer to O(n) in worst case this is O(n)

int longestConsecutiveNumberLengthOptimal (vector<int> &nums){
    // if no element
    if(nums.empty()) return 0;
    
    int n = nums.size();
    unordered_set<int> s(nums.begin(), nums.end());
    int count = 0;
    int longest = 0;

    // looping the set
    for(auto i:s){

        // finding if there is no element before this element, then consider this as starting point and check for values after it
        if(s.find(i-1) == s.end()){
            count = 1;
            int upcomingValue = 1;
            while(s.find(i+upcomingValue) != s.end()){
                count+=1;
                upcomingValue +=1;
            }
            longest = max(count, longest);
        }
    }

    return longest;
}


int main(){
    vector<int>arr={100,102,100,101,101,4,3,2,3,2,1,1,1,2};

    int n = longestConsecutiveNumberLengthOptimal(arr);
    cout<< endl;
    cout << n ;
}