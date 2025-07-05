#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

// brute
// time complexity : O(n sq)
// space complexity : O(1)

bool exitsTwoSumBrute (vector<int> &nums, int k){
    int n=nums.size();
    int sum =0;
    // vector<int > temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            if(nums[i] != nums[j] && nums[i] + nums[j] == k){
                // if i need to send the index
                // temp.push_back(i);
                // temp.push_back(i);
                // return temp;
                return true;
                break;
            }
        }
    }
    return false;
    // return temp (with a null)
}
bool exitsTwoSumBetter (vector<int> &nums, int k){
    int n=nums.size();
    int sum =0;
    for(int i=0; i<n; i++){
        // why j = i+1 ?
        // [2,6,7,8,10]
        // because if we do 2+6 before then again doing 6+2 makes no sense and takes extra time.
        for(int j=i+1; j<n;j++){
            if(nums[i] + nums[j] == k){
                return true;
                break;
            }
        }
    }
    return false;
}

int maxElement (vector<int> &nums){
    int max = nums[0];
    for (int i=0; i<nums.size();i++){
        if(max < nums[i]){
            max = nums[i];
        }
    }
    return max;
}

//using hashArray in order to the element if this is present.
// implemented it by my own.
bool exitsTwoSumBetter2(vector<int> &nums, int k){
    int n = nums.size()+1;
    vector<int> hashArr(maxElement(nums)+1, 0);

    for (int i=0; i<n; i++){
        hashArr[nums[i]] ++;
    }

    for(int i=0; i<n; i++){
        int sub = k-nums[i];
        if(sub>=0 && sub < hashArr.size() && hashArr[sub]){
            return true;
            break;
        }
    }
    return false;
}

// implemented using hashmap, just checking if the subtraction of the k with nums[i] exits in map then we can have a two sum
// time complexity for unordered map we have : O(Nxlogn) and O(n sq) [for worst case]
// space complexity : O(n)
bool exitsTwoSumBetter3(vector<int> &nums, int k){
    int n= nums.size();
    unordered_map<long long, int>hashmap;

    for (int i=0; i<n; i++){
        if(hashmap.find(k-nums[i]) != hashmap.end()){
            return true;
        }else{
            hashmap.insert({nums[i], i});
        }
    }

    return false;
}

void sortArr(vector<int> &nums){

}

    // implemented greedy approach using two pointers : 
    // step 1: sort the array 
    // step 2: put i at first and j at last
    // step 3: check if the sum of element is equal then return true
    // step 4: if the element is greater then decrement the j
    // step 5: if the element is lesser then increment the i
    // step 6: if the none of the element has the sum as equal as k then return false;

    // time complexity : O(n log n) + O(n) == O(n log n) [as it dominates everything]
    // space complexity : O(1)

    bool existTwoSumOptimal (vector<int> &nums, int k){ 
        int n=nums.size();
        int i=0;
        int j=n-1;
        
        sort(nums.begin(), nums.end());
        while (i<j)
        {
            int sum = nums[i] + nums[j];
            if(sum == k) {
                return true;
            }else if(sum > k){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }


vector<int> twoSum(vector<int>& nums, int target) {
    int n=nums.size();  
    vector<int> temp;
    unordered_map<long long, int> hashmap;
    for(int i=0; i<n; i++){
        int sub = target-nums[i];
        if(hashmap.find(sub) != hashmap.end()){
            temp.push_back(hashmap[sub]);
            temp.push_back(i);
            break;
        }else{
            hashmap.insert({sub, i});
        }
    }
    return temp;
}


int main(){ 
    vector<int>arr={2,7,11,15};
    // bool result = exitsTwoSumBetter(arr, 22);
    vector<int> result = twoSum(arr, 9);
    for(auto i:result) cout << i << " ";
}