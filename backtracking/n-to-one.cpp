#include<iostream>
using namespace std;


void printBacktrack (int i, int n){
    if(i>n) return;
    printBacktrack(i+1, n);
    cout << i << endl;
}

int main(){
    printBacktrack(1,3);
}