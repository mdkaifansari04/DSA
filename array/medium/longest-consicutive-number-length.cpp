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


int longestConsecutiveNumberLengthBetter(vector <int> &nums){
    int n=nums.size();
    int longest = 1;
    sort(nums.begin(), nums.end());

    int i = 0;
    int j=i+1;
    int count = 1;
    for(auto i:nums) cout<< i << " ";
    while(i<n){
        if(nums[j] > nums[i]) {
            if(nums[i]+1 == nums[j]) {
                count+=1;
            }else{
                count = 1;
            }
            longest = max(count, longest);
            i=j;
        }
        j++;
    }

    return longest;
}



int main(){
    vector<int>arr={100,102,100,101,101,4,3,2,3,2,1,1,1,2};

    int n = longestConsecutiveNumberLengthBetter(arr);
    cout<< endl;
    cout << n ;
}