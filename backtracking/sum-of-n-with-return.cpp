#include<iostream>

using namespace std;
int c=0;

int calSumUptoN(int n){
    if(n==0){
        return 0;
    }
    return n + calSumUptoN(n-1);
}

int main()
{
    int res = calSumUptoN(5);
    cout << res;

}