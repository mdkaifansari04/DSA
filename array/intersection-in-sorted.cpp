#include<iostream>
using namespace std;

bool exists(vector<int> &arr, int e){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == e) return true;
    }
    return false;
}

vector<int> getIntersectionBrute(vector<int> a, vector<int> b){
    int n1=a.size();
    int n2= b.size();

    int i=0, j=0;
    vector<int> intersection;

    while (i<n1)
    {
        if(!exists(intersection,a[i]) && exists(b, a[i])){
            intersection.push_back(a[i]);
        }
        i++;
    }

    while (j<n2)
    {
        if(!exists(intersection, b[j]) && exists(a, b[j])){
            intersection.push_back(b[j]);
        }
        j++;
    }
    return intersection;
}


// time complexity : O(n1)
// space complexity : O()
vector<int>getIntersectionOptimal(vector<int>a, vector<int>b){
    int n1=a.size();
    int n2 = b.size();

    int i=0;
    int j=0;
    vector<int> intersection;
    while(i<n1 && j<n2){
        if(a[i]<b[j]) {
            i++;
        }else if (b[j]<a[i]){
            j++;
        }else {
            intersection.push_back(a[i]);
            i++;
            j++;
        }
    }
    return intersection;
}
int main(){
    vector<int> arr1 = {1,1,2,3,3,5,6,7,8};
    vector<int> arr2 = {1,3,3,5,6,7,8,10};
    // vector<int> arr3 = getIntersectionBrute(arr1, arr2);
    vector<int> arr3 = getIntersectionOptimal(arr1, arr2);

    for (auto i:arr3){
        cout << i << " ";
    }
}