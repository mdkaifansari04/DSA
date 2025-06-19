#include<iostream>

using namespace std;

void print(int i,int n){
    if(i<1) return;
    print(i-1, n);
    cout <<i<<endl;
}

int main (){
print(3,3);

}

// 3
// 2
// 1