#include<iostream>
#include<map>
using namespace std;


//! NOTE: Whenever you think about the brute approach try to solve it using just simple loops and dont use any Data structure, and it is asked to optimize then go for other approaches

// better force approach (what you though would be the brute is a better one)
// time complexity :O(nlogn) + O(n)
// space complexity : average case- O(n log n), worst case - O(n)
int getMajorityElementBrute(vector<int> &nums){
    int n= nums.size();
    map<int, int> hashMap;
    int majorityElement = 0;

    // this will iterate through O(n) times
    for (int i=0; i<n;i++){
        hashMap[nums[i]] +=1;
    }
    
    // we are iterating for O(N log N) times so we need get 
    for(auto i :hashMap){
        if(i.second > (n/2)) {
            majorityElement = i.first;
        }
    }
    return majorityElement;
}
// optimal approach : using Moore's voting algorithm 
//* Def: The algorithm works on the principle of where we took the starting element and then checks the other element,
//* if the element is present after then increase the count : if ele = 3 and next we have 3342 (count ++ )
//* if the element is not present after that decrement the count if ele = 3 next we have 4321 (count -- )
//* if the count is 0 then we assign the element to ele (var)

// and checks for further condition.
// time complexity : O(n)
// space complexity : O(1)

int getMajorityElement(vector<int> &nums){
    int n = nums.size();
    int count=0;
    int ele;

    for(int i=0;i<n;i++){
        if(count == 0){
            ele = nums[i];
        }
        if(nums[i] == ele){
            count++;
        }else{
            count--;
        }
    }

    // also do an extra check of the number of count of that element we got is the highest and greater then n/2
    int count2=0;

    for(int i=0; i<n; i++){
        if(nums[i] == ele) count2++;
    }

    return (count2 > (n/2)) ? ele : -1;
}

int main(){ 
    vector<int> arr={1,2,2,3,2,2,2,5,6};
    int res = getMajorityElement(arr);
    cout << res << endl;
}
