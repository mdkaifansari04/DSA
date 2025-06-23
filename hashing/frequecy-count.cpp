#include<iostream>
#include<map>
using namespace std;


void checkFrequency (int arr[], int size){
    map<int,int> mpp;
    for(int i=0; i<size; i++){
        mpp[arr[i]]++;
    }

    for (auto i:mpp) cout << i.first << " -->" << i.second << endl;

    int low= mpp.begin()->first;
    int high = mpp.begin()->second;

    for (auto i:mpp){
        if(mpp[low] > i.second) {
            low = i.first;
        }
        if(mpp[high] < i.second){
            high = i.first;
        }
    }

    cout << "Lowest frequency " << low  <<  " --->" << mpp[low]<<endl;;
    cout << "Highest frequency " << high << "---> "<< mpp[high]<<endl;

}
int main(){
    int a[]= {12,23,34,56,34,23, 12,34,56, 2};
     checkFrequency(a, 10);
}