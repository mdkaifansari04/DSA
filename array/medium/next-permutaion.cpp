#include<iostream>
using namespace std;


int fact(int n){
    if(n==1) return 1;
    return n * fact(n-1);
}
vector<int> getNextPermutation(vector<int> &nums){
    int n = nums.size();
    int f = fact(n);
    vector<int>temp;
    bool c;
    for(int i=0; i<f; i++){
        c=next_permutation(nums.begin(), nums.end());
        if(c) cout << "true" << endl;
        else cout << "false" << endl;
    }
    for(auto i:temp) cout << i << " ";
    return temp;
}

int main (){
    vector<int> arr = {3,1,2};
    getNextPermutation(arr);
}