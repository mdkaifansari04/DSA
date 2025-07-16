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

vector<int> reverseArray(vector<int> &nums){
    int n= nums.size();
    vector <int>temp;
    for(int i=0; i<nums.size(); i++){
        temp[i] = nums[n-i-1];
    }
    return temp;
}


vector<int> getNextPermutationOptimal (vector<int> &nums){
    int n = nums.size();
    //finding the break point
    int index = -1;
    for(int i=n-2; i>0; i--){
        if(nums[i] < nums[i+1]){
            index = i; break;
        }
    }
    if(index == -1) return reverseArray(nums);


    int closestGreatest = -1;
    for (int i=index; i<n; i++){
        if(nums[i] > nums[index]){
            if(closestGreatest = -1) closestGreatest = i;
            else if(nums[i] < nums[closestGreatest] ) {closestGreatest = i;}
        }
    }

    swap(nums[index], nums[closestGreatest]);

    sort(nums.begin()+index+1, nums.begin()+n);
    return nums;
}

int main (){
    vector<int> arr = {2,1,5,4,3,1,0,0};
    vector<int> permuteArr = getNextPermutationOptimal(arr);
    for(auto i:arr) cout << i << " ";
}