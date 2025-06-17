
#include <iostream>
#include <math.h>
#include<vector>
using namespace std;


void getAllFactors(int n) {
    vector<int> divisor;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisor.push_back(i);
            if (n / i != i) {
                divisor.push_back(n / i);
            }
        }
    }

    sort(divisor.begin(), divisor.end());
    for (auto i:divisor){
        cout << i << "\t" ;
    }
}

int main (){
    int N = 100;
    getAllFactors(N);

}
