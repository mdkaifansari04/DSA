#include<iostream>
#include<math.h>
using namespace std;

int countDigitOfNumber (int n){
    int digits = 0;
    int lastDigits;

    while (n>0){
        lastDigits = (int)log10(n);
        n = n/10;
        digits+=1;
    }
    return digits;
}

int main(){
    int N = 2345;
    int result = countDigitOfNumber(N);
    cout << "Result : " << result <<endl;    
}