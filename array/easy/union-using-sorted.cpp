#include<iostream>
#include<vector>
using namespace std;

//brute force approach
bool exists(vector<int> &arr, int e){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == e) return true;
    }
    return false;
}

vector<int> getUnionBrute (vector<int>&arr1, vector<int> arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

    int i=0;
    int j=0;
    vector<int> temp;   

    while (i<n1 && j<n2)
    {
        if(arr1[i] <= arr2[j] && !exists(temp, arr1[i])){
            temp.push_back(arr1[i]);
            i++;
        }
        else if(!exists(temp, arr2[j])){
            temp.push_back(arr2[j]);
            j++;
        }else{
            if(!exists(temp, arr1[i]))
                temp.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    while(i<n1){
        if(!exists(temp, arr1[i])){
            temp.push_back(arr1[i]);
        }
        i++;
    }

    while(j<n2){
        if(!exists(temp, arr2[j])){
            temp.push_back(arr2[j]);
        }
        j++;
    }
    return temp;
}


// time complexity : O(n1 + n2)
// space complexity : O(n1+n2)

vector<int> getUnionOptimal (vector<int>&arr1, vector<int> arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

    int i=0;
    int j=0;
    vector<int> temp;   

    while (i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j]){
            if(temp.size() == 0 || temp.back() != arr1[i]){
                temp.push_back(arr1[i]);
            }
            i++;
        }else{
            if(temp.size() == 0 || temp.back() != arr2[j]){
                temp.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(i<n1){
        if(temp.size() == 0 || temp.back() != arr1[i]){
            temp.push_back(arr1[i]);
        }
        i++;
    }

    while (j<n2)
    {
        if(temp.size() == 0 || temp.back() != arr2[j]){
            temp.push_back(arr2[j]);
        }
        j++;
    }
    
    return temp;
}
int main(){ 
    vector<int> arr1 = {1,2,3,5,6,7,8};
    vector<int> arr2 = {1,5,6,7,8, 10};
    vector<int> arr3 = getUnionOptimal(arr1, arr2);

    for (auto i:arr3){
        cout << i << " ";
    }
}
