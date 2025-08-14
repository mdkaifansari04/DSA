#include<iostream>
using namespace std;

// implemented by myself where i just try to hack the way tring to loop through the rows and cols value and when it all get printed one by one
// eventually the approach i took works fine but it breaks in the bottom and when it got fixed the left break.
// conclusion is if we have a better pointer then th loop and handling the last state will be easier.
// so implemented the approach given by striver
void traverseMatrixSpiral (vector<vector<int>> &matrix){
    if(matrix.size() == 0) return ;
    int m= matrix.size(), n = matrix[0].size();
    vector<int> arr;
    int spiralLoop = 1;       

    
    while (spiralLoop < m)
    {
        int col = 0, row = 0;
        int right =n-spiralLoop, bottom = m;

        // right side loop
        for(int i=spiralLoop-1; i<=right; i++){
            cout << "pushing-right: " <<  matrix[spiralLoop-1][i] << " ";
            arr.push_back(matrix[spiralLoop-1][i]);
            col++;
        }
        cout << endl;

        //bottom   
        for(int i=spiralLoop; i<bottom-(spiralLoop-1); i++){
            cout << "pushing-bottom: " <<  matrix[i][col-1] << " ";
            arr.push_back(matrix[i][n-spiralLoop]);
            row++;
        }
        col-=1;
        cout << endl;

        //left 
        for(int i=col-1; i>=spiralLoop -1; i--){    
            cout << "pushing-left: " <<  matrix[row][i] << " ";
            arr.push_back(matrix[row][i]);
        }
        cout << endl;
        row-=1;

        //top 
        for(int i=row; i>=spiralLoop; i--){
              cout << "pushing-top: " <<  matrix[i][spiralLoop-1] << " ";
            arr.push_back(matrix[i][spiralLoop-1]);
        }
        cout << endl;

        spiralLoop ++;
    }

    for(auto i:arr){
        cout<< i << " ";
    }
    
}



int main(){
    vector<vector<int>> arr= {
    {  1,  2,  3,  4,  5,  6 },// 0
    { 20, 21, 22, 23, 24,  7 },// 1
    { 19, 32, 33, 34, 25,  8 },// 2
    { 18, 31, 36, 35, 26,  9 },// 3
    { 17, 30, 29, 28, 27, 10 },// 4`
    { 16, 15, 14, 13, 12, 11 }//  5
    };

    traverseMatrixSpiral(arr);


}