#include<iostream>
using namespace std;

int partitionIndex(vector<int> &nums, int low, int high){  
    // [12,34,4,556,6,70]
    //.  ^
    //   |
    //   pivotIndex


    int i=low, j=high, pivotIndex=low;

    while (i<j)
    {
            while(nums[i] <= nums[pivotIndex] && i<=high-1 ) i++;
            while( nums[j] > nums[pivotIndex] && j>= low+1 ) j--;
            if(i<j)swap(nums[i], nums[j]);
    }
    swap(nums[low], nums[j]);
    return j;
}

void qs(vector<int> &nums, int low, int high){
    if(low < high){

        int pi = partitionIndex(nums, low, high);
        qs(nums, low, pi-1);
        qs(nums, pi+1, high);
    }
}


int getMaxElement(vector<int> &nums){
    int maxEle = nums[0];
    for(int i=0; i<nums.size(); i++) maxEle = max(maxEle, nums[i]);
    return maxEle;
}
// time complexity : O(n) + O(n) + O(hashLimit)
// space complexity : O(hashLimit) + O(1) (for the array)

vector<int> majorityElementBrute(vector<int>& nums) {
    vector<int> arr;

    int n = nums.size();
    int hashLimit = getMaxElement(nums) +1;
    int times = floor(n/3);
    int hashArr[hashLimit];


    memset(hashArr, 0, sizeof(hashArr));

    for(int i=0; i<n; i++){
        hashArr[nums[i]]+=1;
    }

    for(int i=0; i<hashLimit; i++){
        if(hashArr[i] > times) arr.push_back(i);
    }

    return arr;
}

// time complexity : O(n)
// space complexity : O(1) //as i have defined the size of vector as 2, as we know 
vector<int> majorityElementBetter (vector<int> &nums){
    int n = nums.size();
    int minTimes = floor(n/3);
    vector<int>arr(2);
    unordered_map<int, int> map;

    for(int i=0; i<n; i++){
        map[nums[i]]+=1;
        if(map[nums[i]] > minTimes && find(arr.begin(), arr.end(), nums[i]) == arr.end()) {
            arr.push_back(nums[i]);
        }
    }
    return arr;
}

// optimal approach was implemented by using the Moore's voting algorithm. 
//* In short we choose an element and check if there is similar element after it then increment the count 
// if there is element not similar decrement the count 
// if the count get zero select another ele
// At last check if you picked an element at last, if the count of that element is greater then floor(n/3); 
//* if this is the case then you got the element, Same true for this we just need to take two element and two count and check for both two as there will be only two element at max.

// time complexity : O(n)
// space complexity : O(1)
vector<int> getMajorityElementOptimal(vector<int> &nums){  
    int n=nums.size();
    int times = floor(n/3);
    int count1 =0, count2 =0;
    int ele1,ele2;
    vector<int> arr;

    for(int i=0; i<n; i++){
        

        // we check the first time and choose the element and increment count
        if(count1==0 && nums[i] != ele2){
            count1 = 1;
            ele1 = nums[i];

        // if the count1 was selected now select count2 and assign element two
        }else if(count2 == 0 && nums[i] != ele1){
            count2 = 1;
            ele2=nums[i];
        } 
        // if both was assigned now check if we have similar elements as ele1 (yes then increment the count)
        else if(ele1 == nums[i]) count1++;
        // if no then check is this similar to other element as well
        else if(ele2 == nums[i]) count2++;
        // if the element is unique then decrement both
        else count1 --, count2--;

        //* this algo allows only those element in ele1 and ele2 which are dominating in the array and thats what we need (we want those element which are more then n/3 times in array)
    }

    //? This is the another check if the element we choose in ele1 and ele2, is actually highest then then n/3 so for that lets count their counts
    count1=0; count2 =0;
    for(int i=0; i<n; i++){
        if(ele1 == nums[i]) count1++;
        else if (ele2 == nums[i])count2++;
    }
    //? now check for both if there are more then the times (n/3), if yes add them to arr and return
    if(count1 > times) arr.push_back(ele1);
    if(count2 > times) arr.push_back(ele2);
    return arr;
}
int main(){
    vector<int> arr = {3,2,3};
    // vector<int> ans = majorityElementBrute(arr);
    vector<int> ans = getMajorityElementOptimal(arr);
    for(auto it:ans)cout << it << " ";

}