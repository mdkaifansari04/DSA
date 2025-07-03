#include<iostream>
using namespace std;

bool exists(vector<int> &a, int element){
    for (int i=0; i<a.size(); i++){
        if(a[i] == element){return true;}
    }
    return false;
}
// brute using loops
// time complexity : O(n sq)
// space complexity : O(1)

int missingNumberBrute(vector<int>& nums) {
    int missing = 0;
    for (int i=0; i<=nums.size(); i++){
        if(!exists(nums, i)){
            missing = i;
            break;
        }
    }
    return missing;
}

// better solution using hasing
// time complexity : O(2n) == O(n)
// space complexity : O(n)
int missingNumberBetter (vector<int> &arr){
    int n = arr.size()+1;
    int hashArr[n];
    int missing = 0;
    memset(hashArr, 0, sizeof(hashArr));

    for(int i=0; i<n; i++){ 
        hashArr[arr[i]] = 1;
    }

    for (int i=0; i<n; i++){
        if(hashArr[i] ==0){
            missing = i;
        }
    }
    return missing;
}

// using maths logic
// time complexity : O(2n) == O(n)
// space complexity : O(1)

int missingNumberOptimal(vector<int> &arr){
    int n = arr.size();
    int sum = (n*(n+1))/2;
    int s2=0;
    for(auto i:arr) s2+=i;
    return sum-s2;
}
// using XOR logic
// time complexity : O(2n)
// space complexity : O(1)
int missingOptimalAnother(vector<int> &arr){
    int n = arr.size();
    int xor1=0;
    int xor2=0;
    for(int i=0; i<n+1; i++){
        xor1 = xor1^i;
    }
    for(int j=0; j<n; j++){
        xor2 = xor2^arr[j];
    }
    return xor1 ^ xor2;

}
int main (){
    vector<int> arr ={9,6,4,2,3,5,7,0,1};
    // int missingBrute = missingNumberBrute(arr); s
    // cout << "Missing brute :" << missingBrute;

    // int missing = missingNumberBetter(arr);
    // cout << "Missing better :" << missing;

    // int missing = missingNumberOptimal(arr);
    // cout << "Missing optimal :" << missing;
    int missing = missingOptimalAnother(arr);
    cout << "Missing optimal :" << missing;

}