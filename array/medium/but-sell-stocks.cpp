#include<iostream>
using namespace std;

// optimal approach : for buying and selling stocks
// The theory is we start with the start index of the array where we just take first number as the buying the stocks


int maximumProfit (vector<int> &nums){
    int n= nums.size();
    int profit=0, cost=0;

    cost=nums[0];
    for(int i=0;i<n;i++){
        cost = min(nums[i], cost);
        int r = nums[i] - cost;
        profit = max(r,profit);
    }
    return profit;
}
int main(){
    vector<int> arr ={7,6,4,3,1};
    int max = maximumProfit(arr);
    cout<< max ;
}