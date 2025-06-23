#include<iostream>
using namespace std;

// what is hashing : Hasing is the way of counting the elements an array contains. ( the number of elements does the )

int checkNumberOfChar(char c, string s){
    int hashLimit = 26;
    int hashArr[hashLimit];
    int offset = 97;

    memset(hashArr, 0, sizeof(hashArr));
    
    for(int i=0; i<s.length(); i++){
        hashArr[int(s[i])-offset]++;
    }
    return hashArr[int(c)-offset]; 
    
}

int main()
{
    char c = 'z';
    string s = "asjanskkaiasmlwmiixkkalaksz";
    cout << "Character present :" << checkNumberOfChar(c,s) << endl;;
}