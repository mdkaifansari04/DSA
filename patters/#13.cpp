#include <iostream>
using namespace std;

// pattern printing program

void print1(int n)
{
    // alphabet triangle

    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch;
        }
        cout << endl;
    }
}


void print2(int n){
    // reverse alphabet triangle
    for (int i=n; i>0;i--){
        for (char ch = 'A'; ch<='A'+i; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}
int main()
{
    print2(5);
}
