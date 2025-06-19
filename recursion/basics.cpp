#include<iostream>
using namespace std;


void print(string name, int count){
    if(count == 3) return;
    cout <<name;
    count++;
    print(name, count);
}


int main()
{   int count=0;
    print("kaif", count);
}