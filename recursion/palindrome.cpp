#include<iostream>
using namespace std;

void palindrome (string s, string reverse, int size)
{
    if(reverse.length() == size){
        if(reverse == s) cout << "String is Palindrome";
        else cout << "String is not Palindrome";
        return;
    }

    palindrome(s, reverse + s[reverse.length()], size);
}

int main()
{   
    palindrome("Kaif", "", 3);
}