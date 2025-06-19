#include<iostream>
using namespace std;

int myCount = 1;
int n = 10;
void print(){
    cout << myCount <<endl;
    if(myCount == n) return;
    myCount++;
    print();
}


int main()
{   
    print();
}