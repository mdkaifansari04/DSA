#include<iostream>
using namespace std;

// mine
// brute force approach
// time complexity : O(n)
// space complexity : O(n)

void sortArr(vector<int> &nums){
    int n =nums.size();
    vector<int> temp;

    for(int i=0; i<n;i++){
        if(nums[i] == 0) temp.push_back(nums[i]);
    }
    for(int i=0; i<n;i++){
        if(nums[i] == 1) temp.push_back(nums[i]);
    }
    for(int i=0; i<n;i++){
        if(nums[i] == 2) temp.push_back(nums[i]);
    }
    for(int i=0; i<n;i++){
        nums[i] = temp[i];
    }
}
// this is better then the above as it uses O(1) space complexity 
// time complexity : O(n)
// space complexity : O(1)

void sortArrBrute(vector<int> &nums){
    int zeros = 0, ones = 0, twos =0;
    int n=nums.size();

    for(int i=0; i<n; i++){
        if(nums[i] == 0) zeros ++;
        else if(nums[i] == 1) ones ++;
        else twos ++;
    }
    for(int i=0; i<zeros;i++){
        nums[i] = 0;
    }
    for(int i=zeros; i<zeros+ones;i++){
        nums[i] = 1;
    }
    for(int i=zeros+ones; i<n;i++){
        nums[i] = 2;
    }
}

// Dutch National Flag Algorithm : It has three pointers as low, mid and high 
// it is a type of a hypothetical array where we need to assume that the array from :

// 0 to low-1 : 000000
// low to mid-1 : 1111111
// mid to high : unsorted array 01012101
// high+1 to n-1 : 222222


// so we are just making a hypothetical array of unsorted part, where i need to have : 
// mid = 0
// high = n-1 [for me, to take my array and sort it using the algorithm] 
// as we dont have an actual array we need to make a low pointer as low =0;
// and we will be sorting the array based on swap technique and it will be done

// time complexity : O(n)
// space complexity : O(1)

void sortBetter (vector<int> &nums){
    int n = nums.size();
    int mid = 0, high=n-1, low=0;

    // if the mid crosses the high, means we are done with the sorting technique.
    while(mid <= high){
        // we check if the element is equal to 0, if yes then swap it wil low, 
        //which is pointing to the index 0 and mid is also having the same so same number get swapped by one another
        // and increment the mid++ (as we need to sort others as well) 
        // and increment the low++ (as the low is already at the sorted place and we need not to sort it anymore)
        if(nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        // if the element it equal to 1 then it is in middle and at the right position.
        // it can be understood in such a way that, if we sort the 0's at left and 2's at right (1's will auto be sorted)

        else if(nums[mid] == 1) mid++;
        // if there is 2's then swap it with the last element and decrement the high--,
        // and no change to mid as we are still sorting it
        // if we again got 2, the the high is decremented and the again we do swap
        // still wait at mid see if there is other elements
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main(){
    vector<int> arr={2,0,2,1,1,0};
    sortBetter(arr);

    for(auto i:arr){
        cout << i << " ";
    }
}
