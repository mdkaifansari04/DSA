#include<iostream>
using namespace std;



void checkNumberExits (int arr[],int size, int number, int hashLimit){
    int hash[hashLimit];

    //initialize the hash`
    memset(hash, 0, sizeof(hash));

    //populate teh hash
    for(int i=0; i<size; i++){
            hash[arr[i]] ++;
    }
    cout << number<<" Appears : " << hash[number]<<endl;
}
int main(){
    int sizeOfArray = 5;
    int arr[] ={1,2,3,1,2};
    int num[]={1,2,4,5,0};

    for(auto i :num) checkNumberExits(arr, 5,i, 5);

}