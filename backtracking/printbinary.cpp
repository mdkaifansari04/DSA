#include<iostream>
using namespace std;

void printBinary(int n, string binary){
    cout << "current: " << binary << endl;
    if(n == binary.length()){
        cout << binary <<endl;
        return;
    }
    printBinary(n, binary + "0");
    printBinary(n, binary + "1");
}


int main(){
    printBinary(2,"");
}