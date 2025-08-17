#include<iostream>
using namespace std;

// ! this wont work as expected.
// brute approach
// time complexity : O(n)
// space complexity : approx O(n) 
vector<vector<int>> generatePascalTriangleBrute(int numRows) {
    vector<vector<int>> arr;
    int m=0, n=1;

    for(int i=0; i<numRows; i++){
        arr.push_back(vector<int>(i, 1));
        for(int j=0; j<i; j++){
              cout << "ith :" << i << endl;
                if(j==0) arr[i][j] = 1;
                else if(j==i) arr[i][j] = 1;
                else {
                    arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
                }
        }
    }
    return arr;
}   

//* Given R and C find the element at that position
// time complexity : O(c)
// space complexity : O(1)
// optimal approach for finding the factorial or the combination problem
long findElementAtPosition (int r, int c){
    long res =1;
    c=c-1;
    r=r-1;
    for(int i=0; i<c; i++){
        res *= r-i;
        res/= i+1;
    }
    return res;
}

//* given the row number, find the entire row of pascal triangle
// this is the optimal approach
// time complexity : O(n) or O(rowNumber)
// space complexity : O(n) // as we are returning the entire array after storing the element
vector<int> getPascalTriangleRow(int rowNumber){
    vector<int> arr;
    int res = 1;
    arr.push_back(res);
    for(int i=1; i<rowNumber; i++){
        res*=(rowNumber-i);
        res/=(i);
        arr.push_back(res);
    }
    return arr;
}

//* given the number of rows, create the entire pascal triangle
vector<vector<int>> generatePascalTriangleOptimal(int numOfRows){
    vector<vector<int>> arr;
    vector<int>temp;
    int res=1;
        for(int i=0; i<numOfRows; i++)
        {   
            arr.push_back(vector<int>(i+1, res));
            for(int j=1; j<i; j++){
                res*=(i-j);
                res/=(j);
                temp.push_back(res);
            }
            arr[i] = temp;
    }
    return arr;
}
int main(){
    // int numRow=6;
    // vector<vector<int>> arr = generatePascalTriangleBrute(numRow);

    // for(int i=0; i<numRow; i++){
    //     for(int j=0; j<i; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // int res = findElementAtPosition(5,3);
    // cout << res;

    vector<vector<int>> res = generatePascalTriangleOptimal(5);
    for(int i=0; i<5; i++){
        for(int j=0; j<i; j++){
            cout << res[i][j] << " ";
        }
        cout<< endl;
    }
}