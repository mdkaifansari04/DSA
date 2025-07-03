#include<iostream>
using namespace std;

int maximumConsecutive(vector<int> &nums)
{   
    int n = nums.size();
    int count = 0;
    int max = 0;

    for (auto i:nums){
        if(i==1){
            count+=1;
            if(count>max)max=count;
        }else{
            count =0;
        }
    }
    return max;
}

int main(){
    vector<int> arr = {1,1,1,0,0,1,1,1,1,0,0};
    int max = maximumConsecutive(arr);
    cout << max;
}