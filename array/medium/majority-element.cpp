
#include<iostream>
#include<map>
using namespace std;


//! NOTE: Whenever you think about the brute approach try to solve it using just simple loops and dont use any Data structure, and it is asked to optimize then go for other approaches

// better force approach (what you though would be the brute is a better one)
// time complexity : O(2n) == O(n)
// space complexity : average case- O(n log n), worst case - O(n)
int getMajorityElement(vector<int> &nums){
    int n= nums.size();
    map<int, int> hashMap;
    int majorityElement = 0;
    for (int i=0; i<n;i++){
        hashMap[nums[i]] +=1;
    }

     for(auto i :hashMap){
        if(i.second > (n/2)) {
            majorityElement = i.first;
        }
    }
    return majorityElement;
}

int main(){ 
    vector<int> arr={1,2,2,3,2,2,2,5,6};
    int res = getMajorityElement(arr);
    cout << res << endl;
}