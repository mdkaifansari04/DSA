#include<iostream>
using namespace std;


int fact(int n){
    if(n==1) return 1;
    return n * fact(n-1);
}

vector<int> getNextPermutation(vector<int> &nums){
    next_permutation(nums.begin(), nums.end());
    return nums;
}

int main (){
    vector<int> arr = {1,2,3};
    vector<int> permuteArr = getNextPermutation(arr);
    for(auto i:arr) cout << i << " ";
}