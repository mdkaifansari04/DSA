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

vector<int> traverseMatrixSpiralStriver(vector<vector<int>> &matrix){
    int m= matrix.size(), n = matrix[0].size();
    int top = 0, bottom = m-1, right = n-1, left =0;
    vector<int> arr;
    if(n==1){   
        for(int i=0; i<m; i++) arr.push_back(matrix[i][0]);
        return arr;
    }
    while(left <=right && top <=bottom){

        // right direction
        for(int i=left; i<=right; i++){
            arr.push_back(matrix[top][i]);
        }   
        top ++;
        // bottom
        for (int i=top; i<=bottom; i++){
            arr.push_back(matrix[i][right]);
        }   
        right --;

        // left
        if(top <=bottom)
        {
            for(int i=right; i>=left; i--){
                arr.push_back(matrix[bottom][i]);
            }
            bottom --;
        }
        
        // top
        if(left<=right)
        {
            for(int i=bottom; i>=top; i--){
                arr.push_back(matrix[i][left]);
            }
            left ++;
        }
    }
    return arr;
}


// implemented by own after one day.
vector<int> spiralTraversal(vector<vector<int>> &matrix){
    int n=matrix.size(), m =matrix[0].size();
    vector<int> arr;

    // the edge case if the 
    // if(m == 1){ 
    //     for (int i=0; i<n; i++){
    //         arr.push_back(matrix[i][0]);
    //         return arr;
    //     }
    // }

    int top = 0, left=0, right=m-1, bottom =n-1;

    while(left <=right && top <=bottom){

        //right range 
        for(int i=left; i<=right; i++){
            arr.push_back(matrix[top][i]);
        }
        top ++;


        // bottom : this loop doesn't have any effect if the top is incremented and we have a one row, example 
        //                  left
        //                   |
        // --> top, bottom {{1,2,3,4}} <--- right
        // --> top   (if the top is incremented by the bottom after the first iteration, then we need not contraint or condition before running this below loop)

        for(int i =top; i<=bottom; i++){
            arr.push_back(matrix[i][right]);
        }
        right --;

        // left : side of operation where we use bottom pointer as reference and make sure that bottom was not incremented by top in previous operations. (though checking those values)
        if(top <= bottom){
            for(int i=right; i>=left; i--){
                arr.push_back(matrix[bottom][i]);
            }
            bottom --;
        }

        // top : operation needs left pointer so making sure if this is valid means left <= right then only do
        if(left<=right){
            for(int i=bottom; i>=top; i--){
                arr.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return arr;
}
int main(){
    vector<vector<int>> arr= {
    {  1,  2 },
    { 10,  3 },
    {  9,  4 },
    {  8,  5 },
    {  7,  6 }
    };
    vector<int> res = spiralTraversal(arr);
    for(auto i:res) cout << i << " ";
}