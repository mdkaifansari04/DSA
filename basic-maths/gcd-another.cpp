#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){ 
    int a = 12, b = 19;

    // keep running until any one of them becomes zero
    while(a > 0 && b > 0){
        // Euclidean algorithm logic
        // basically, gcd(a, b) = gcd(a % b, b) when a > b
        // we just reduce the bigger number with modulo of smaller
        if(a > b) 
            a = a % b;  // make a smaller
        else 
            b = b % a;  // make b smaller
    }

    // if a is 0, then b will be the GCD
    if(a == 0) 
        cout << "GCD : " << b;
    else 
        cout << "GCD : " << a;

    return 0;
}
