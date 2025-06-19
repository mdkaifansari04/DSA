#include<iostream>
using namespace std;

void generateBinary (int n, string current){
    if(n == current.length()){
        cout << current << endl;
        return;
    }
    generateBinary(n,current+ "0");
    generateBinary(n,current + "1");
}

int main(){
    generateBinary(3, "");
}