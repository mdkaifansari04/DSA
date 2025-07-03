#include<iostream>
#include<set>
using namespace std;

int removeDuplicates(vector<int> &arr){
    set<int> s;
    for (int i=0; i<arr.size(); i++){
        s.insert(arr[i]);
    }
    int index = 0;
    for (auto i:s) {
        arr[index] = i;
        index++;
    }
    return index;
}

int removeDuplicatesOptimal(vector<int> arr){
    int i=0;
    int j=i+1;
    vector<int> nonDup;
    nonDup.push_back(arr[i]);
    while (j<arr.size()-1)
    {   
        if(arr[i] == arr[j]) j++;

        if(arr[j] !=arr[i]) {
            nonDup.push_back(arr[j]);
            i=j;
            j++;
        }
    }
}

int main(){
    vector<int>arr = {1,2,3,1,2,3,4,4,5,};
    int uniqueElements = removeDuplicates(arr);
    cout << uniqueElements;
 }