#include<iostream>
#include<string>
using namespace std;

void permute(string &s, int l, int r){
    if(l == r){
        cout << s << endl;
        return;
    }

    for(int i = l; i <= r; i++){
        swap(s[l], s[i]);                 // choose
        permute(s, l + 1, r);             // explore
        swap(s[l], s[i]);                 // backtrack
    }
}

int main(){
    string s = "abc";
    permute(s, 0, s.length() - 1);
}
