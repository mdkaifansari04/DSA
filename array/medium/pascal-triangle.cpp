#include<iostream>
using namespace std;

vector<vector<int>> generatePascalTriangleBrute(int numRows) {
    vector<vector<int>> arr;
    vector<int> temp;
    int m=0, n=1;

    for(int i=0; i<numRows; i++){
        arr.push_back(vector<int>(i, 1));
        for(int j=0; j<i; j++){
                if(j==0) arr[i][j] = 1;
                else if(j==i) arr[i][j] = 1;
                else {
                    arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
                }
        }
    }
    return arr;
}   
int main(){
    int numRow=5;
    vector<vector<int>> arr = generatePascalTriangleBrute(numRow);

    for(int i=0; i<numRow; i++){
        for(int j=0; j<i; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}