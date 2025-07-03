#include<iostream>
using namespace std;

void linearSearch(int arr[], int size, int k){
    bool flag =false;
    for (int i=0; i<size; i++){
        if(arr[i] == k){flag=true;break;}
    }

    if(flag)cout << "Element found";
    else cout<<"Element not found";
}

int main()
{
    int arr[] = {12,3,45,6};
    linearSearch(arr, 4, 6);
}