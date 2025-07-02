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

int main (){
    vector<int> arr ={9,6,4,2,3,5,7,0,1};
    // int missingBrute = missingNumberBrute(arr);
    // cout << "Missing brute :" << missingBrute;

    int missing = missingNumberBetter(arr);
    cout << "Missing better :" << missing;

}