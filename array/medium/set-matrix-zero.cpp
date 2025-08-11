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
                colToBeZero[i] = 1;
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


int main(){
    int rows=4, cols = 4;
    vector<vector<int>> arr = {
    {1, 1, 1,1},
    {1, 0, 0,1},
    {1, 1, 0,1},
    {1, 1, 1,1},
    };
    setMatrixToZeroBetter(arr, rows, cols);
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            cout << arr[i][j] << " " ;
        }
        cout<< endl;
    }
}
