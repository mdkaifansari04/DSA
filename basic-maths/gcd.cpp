#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
    int n1 = 12, n2= 19;
    int gcd = 0;
    int minVal = min(n1, n2);

    for (int i =0; i<= sqrt(minVal); i++){
        if(n1%i == 0 && n2%i==0){
            gcd = i;
        }
    }

    cout << "GCD : " << gcd; 
    return 0;
}