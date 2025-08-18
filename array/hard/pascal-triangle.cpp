#include<iostream>
using namespace std;

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

// optimal approach: by using the get row element
// time complexity : O(n) sq
// space complexity : approx O(n sq) if we return array if we print then O(1)
vector<vector<int>> generatePascalTriangleOptimal(int numRows) {
    vector<vector<int>> ans;

    for(int i=1; i<=numRows; i++){
        ans.push_back(getPascalTriangleRow(i));
    }
    return ans;
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
    int numRow=6;
    vector<vector<int>> arr = generatePascalTriangleOptimal(numRow);

    for(auto it:arr){
        for(auto ele:it){
            cout << ele << " ";
        }
        cout << endl;
    }

    // int res = findElementAtPosition(3,2);
    // cout << res;

    // optimal pascal triangle
    // vector<vector<int>> res = generatePascalTriangleOptimal(5);
    // for(int i=0; i<5; i++){
    //     for(int j=0; j<i; j++){
    //         cout << res[i][j] << " ";
    //     }
    //     cout<< endl;
    // }
}