#include<iostream>
#include<algorithm>

using namespace std;
//* https://leetcode.com/problems/rotate-image/

// brute force approach
// time complexity :O(mxn)
// space complexity : O(mxn)
void rotateMatrixTo90DegreeBrute(vector<vector<int>> &nums)
{   
    if(nums.size() == 0) return;
    int m = nums.size(), n=nums[0].size();
    vector<vector<int>> arr(m, vector<int>(n));

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            // this formula which i have written came after the observation in pen and copy, like which inputs are changing and how can i get those in replacement of that value.
            arr[j][(n-1)-i] = nums[i][j];
        }
    }
    nums = arr;
}

void rotateMatrixTo90DegreeOptimal (vector<vector<int>> &nums){

    if(nums.size() == 0) return;
    int m = nums.size(), n=nums[0].size();

    for(int i=0; i<m; i++){
        for(int j=i+1; j<n; j++){
            swap(nums[j][i], nums[i][j]);
        }
    }
    for (int i=0; i<m; i++){
        //reverse each element to get the 90 deg rotation clock wise
        reverse(nums[i].begin(), nums[i].end());
        cout<< endl;
    }
}

int main(){
    vector<vector<int>> arr = {
        {1,2,3,4},
    //   00,01,02,03
        {5,6,7,8},
    //   10,11,12,13
        {9,10,11,12},
    //   20,21,22,23
        {13,14,15,16}
    //   30,31,32,33
    };

    rotateMatrixTo90DegreeOptimal(arr);
    int m = arr.size(), n=arr[0].size();
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<< arr[i][j] <<" ";
        }
        cout<< endl;
    }
}