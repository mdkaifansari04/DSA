#include<iostream>
using namespace std;

int myCount = 0;
int n = 10;
void print(){
    if(myCount == n) return;
    cout << n-myCount <<endl;
    myCount++;
    print();
}


int main()

{   
    print();
}