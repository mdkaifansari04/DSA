#include<iostream>

using namespace std;

int fiboo (int N)
{   
    if(N <=1) return N;
    return fiboo(N-1) +  fiboo( N-2);
}

int main()
{
    int N=5;
    for (int i=0; i<=N; i++)
        cout << fiboo(i) << " ";
}