#include<iostream>
using namespace std;


// brute force approach 
// time complexity : O(n^2)
// space complexity : O(1)

void sortNumberBrute(vector<int> &nums){
    int n= nums.size();
    int i=0, j=i+1;

    while (j<n)
    {
        if(i%2!=0){
            if(nums[i] > 0){
                while (nums[j]>0) j++; //find the negative element
                swap(nums[i], nums[j]); // swap with that ith position, which is incorrect.
            }
        }else{
            if(nums[i] < 0) {
                while (nums[i] < 0) j++; // find the positive element
                swap(nums[i], nums[j]); // swap with that ith position, which is incorrect.
            }
        }
        i++; // incrementing i++
        j=i+1; // making sure that j is always one step after i, and following the condition j<n
    }
}

// better approach using extra array
// time complexity : O(n)
// space complexity : O(n)

// so the idea is creating another array and making sure that odd index contains negative number and vice versa for even index
// storing the number and incrementing 2 position for pon and neg index pointer and then storing the another element 
void sortNumberBetter(vector<int> &nums){
    int n= nums.size();
    vector<int> res(n);

    int pos =0; int neg=1;
    for (int i=0; i<n;i++){

        // if number is positive or zero
        if(nums[i] >=0){
            res[pos] = nums[i];
            pos+=2; // increment two position, as we are storing the element there
        }else{
            res[neg] = nums[i];
            neg+=2;
        }
    }
    // updating the actual array
    for(int i=0; i< n; i++){
           nums[i] = res[i];
    } 
}

void sortNumberOptimalForNonEqualNumber(vector<int> &nums)
{
    int n =nums.size();
    vector<int> pos, neg;

    // collecting all the positive and negative in another vector
    for(int i=0;i <n;i++){
        if(nums[i]>=0){
            pos.push_back(nums[i]);
        }else{
              neg.push_back(nums[i]);
        }
    }

    if(pos.size() > neg.size()){
        for(int i=0; i<neg.size(); i++){
            nums[i*2] = pos[i];
            nums[(i*2)+1] = neg[i];
        }

        int index = neg.size()+1;
        for(int i=pos.size() - neg.size(); i<pos.size(); i++){
            nums[index] = pos[i];
            index++;
        }
    }else{
        for(int i=0; i<pos.size(); i++){
            nums[i*2] = pos[i];
            nums[(i*2)+1] = neg[i];
        }

        int index = pos.size()+1;
        for(int i=neg.size() - pos.size(); i<neg.size(); i++){
            nums[index] = neg[i];
            index++;
        }
    }


}

int main()
{
    vector<int> arr ={3,1,-2,-5,2,-4, -6,-9,8, 100, 90, 80, 7};
    sortNumberOptimalForNonEqualNumber(arr);
    for(auto i:arr) cout<< i << " ";
}