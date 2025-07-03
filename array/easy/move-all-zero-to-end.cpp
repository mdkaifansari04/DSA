#include<iostream>
using namespace std;

//optimal

// time complexity : O(2N) = O(n)
// space complexity : O(N) using temp of N size
void moveAllZeroToEnd(vector<int> &nums){
    int n=nums.size();
    int zeroCount=0;


    int i=1,j=-1;

    for(int i=0; i<n; i++){
        if(nums[i] == 0){
            j=i;
            break;
        }
    }
    i=j+1;
    if(j<0){
        cout << "The array doesnot have zero" ; 
        return;
    }
    while(i<n){
        cout<< nums[j] <<" ";
        if(nums[i]!=0) {
            swap(nums[i], nums[j]); 
            i++;
            j++;
        }
        if(nums[i] == 0)i++;
    }

    cout << "zeros" << zeroCount << endl;
}

int main(){
    vector<int> arr={12,34,21,4,5,0,4,0,0,34,65};
    moveAllZeroToEnd(arr);
    for (auto i:arr) cout<< i << " ";
}