#include<iostream>
#include<set>
using namespace std;

vector<int> getUnion(vector<int>&arr1, vector<int>&arr2){
    set<int>s;
    for (int i=0; i<arr1.size(); i++){
        s.insert(arr1[i]);
    }

    for (int i=0; i<arr2.size(); i++){
        s.insert(arr2[i]);
    }

    vector<int> temp;
    for (auto i:s){
        temp.push_back(i);
    }
    return temp;
}

int main(){ 
    vector<int> arr1 = {1,2,3,5,6,7,8};
    vector<int> arr2 = {1,5,6,7,8, 10};
    vector<int>arr3 = getUnion(arr1, arr2);
    for (auto i:arr3){
        cout << i << " ";
    }
}