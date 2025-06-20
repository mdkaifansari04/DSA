#include<iostream>
using namespace std;

int N=5;

void reverse(int i,int arr[],int n){
    if(i>= n/2) return;
    swap(arr[i], arr[n-i-1]);
    reverse(i+1,arr, n-1);
}
int main()
{
    int arr[] = {1,2,3,4,5};
    reverse(0,arr, N);
    for(int i=0; i<N; i++)cout << arr[i] << " ";
}