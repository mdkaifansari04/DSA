#include<iostream>

using namespace std;
int c=0;

void calSumUptoN(int n, int sum){
    if(c==n){
        cout << "Sum: " << sum << endl;
        return;
    }
    c++;
    calSumUptoN(n, sum+c);
}

int main()
{
    calSumUptoN(5,0);

}