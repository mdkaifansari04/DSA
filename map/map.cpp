#include<iostream>
#include<map>
using namespace std;


void checkChar(char c, string s){
    map<char,int>mpp;

    for (int i =0; i<s.length(); i++){
        if(c==s[i]){
            mpp[c]++;
        }
    }
    cout  << c << " char available : " << mpp[c];

}

int main(){
    checkChar('k', "asasasasasaskjasiauskakskasiaus");
}