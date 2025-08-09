#include<iostream>
using namespace std;

bool linearSearch (vector <int> &arr, int num){
    int n = arr.size();
    bool isFound = false;
    for (int i=0; i<n; i++){
        if(arr[i] ==num) isFound = true;
    }
    return isFound;
}

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

int main(){
    vector<int>arr={102,4,100,1,101,3,2,1,1};
    int n = longestConsecutiveNumberLengthBrute(arr);
    cout << n ;
}