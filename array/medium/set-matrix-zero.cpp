#include<iostream>
using namespace std;


void setRowsColsToZero (vector<vector<int>> &nums, int rows, int cols, int desiredRow, int desiredCol)
{
    for (int i=0; i<rows; i++){
        nums[i][desiredCol] = -1;
    }  
    for (int j=0; j<cols; j++){
        nums[desiredRow][j] = -1;
    }         
}

// brute force solution
// time complexity : O(n*m) * O(n+m) * O(n*m)
// space complexity : O(n)

void setMatrixToZeroBrute(vector<vector<int>> &nums, int rows, int cols){
    // I was using this temp array to make the rows and cols as zero so that we dont get confused with the original zero and changes zeros
    // vector<vector<int>> arr = nums;
    for (int i=0; i<rows; i++){ // n*m
        for (int j=0; j<cols; j++){
            if(nums[i][j] == 0){
                 setRowsColsToZero(nums, rows, cols, i, j); // n+m
            }
        }
    }

    // making every element as 0 which I have marked as -1 before I was using another array to track this but now its just to remove extra space
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            if(nums[i][j] == -1){
                nums[i][j] = 0;
            }
        }
    }
}

// better solution 
// time complexity : O(n x m) + O(n x m) = O(n x m)
// space complexity : O(m) + O(n)
void setMatrixToZeroBetter(vector<vector<int>> &nums, int rows, int cols){
    vector<int>rowsToBeZero(rows, 0),colToBeZero(cols, 0);

    for (int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(nums[i][j] == 0) {
                rowsToBeZero[i] = 1;
                colToBeZero[j] = 1;
            }
        }
    }

    for (int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(rowsToBeZero[i] == 1 || colToBeZero[j] == 1) {
                nums[i][j] = 0;
            }
        }
    }

}

void setMatrixToZeroOptimal(vector<vector<int>> &matrix, int m, int n){
    //  vector<int>rowsToBeZero(rows, 0),colToBeZero(cols, 0); --> rowTO
    // row = matrix[0][...]
    // cols = matrix[...][0]
    // int col0 = 1;
    int col0 = 1;

    // checking and marking the 0th row and 0th col
    for (int i=0; i<m; i++){
        for (int j=0; j<n;j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                if(j!=0)matrix[0][j] = 0;
                else col0=0;
            }
         }
    }

    // conversion of the element. 
    for (int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][j] != 0){
                if( matrix[0][j] ==0 || matrix[i][0] ==0){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // checking for the 0th row
    if(matrix[0][0] == 0){
        for (int j=0; j<m; j++) matrix[0][j] = 0;
    }

    if(col0 == 0){
         for (int i=0; i<m; i++) matrix[i][0] =0;
    }

}


int main(){
    int rows=3, cols = 4;
    vector<vector<int>> arr = {
    {0,1,2,0},
    {3,4,5,2},
    {1,3,1,5},
    };
    setMatrixToZeroOptimal(arr, rows, cols);
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            cout << arr[i][j] << " " ;
        }
        cout<< endl;
    }
}
