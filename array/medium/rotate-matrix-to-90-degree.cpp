#include<iostream>
using namespace std;


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
            arr[j][(n-1)-i] = nums[i][j];
        }
    }
    nums = arr;
}
int main(){
    vector<vector<int>> arr = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int m = arr.size(), n=arr[0].size();
    rotateMatrixTo90DegreeBrute(arr);
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout<< endl;
    }
}