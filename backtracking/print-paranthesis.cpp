#include<iostream>

using namespace std;

void generate(int n, int open, int close, string s){

    if(open == n && close == n){
        cout<< s<<endl;
    }
    if(open < n) generate(n, open+1, close, s + "(");
    if(close<open) generate(n, open, close+1, s+")");
}

int main()
{

generate(2, 0, 0, "");
}