#include<iostream>
#include<vector>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        int n = mat.size();
        vector<int> ans;
        ans.push_back(mat[0][0]);
        
        if(n == 1)  return ans;
        bool flag = true;
        
        // upper triangle traversal of the matrix.
        for(int i=1; i<n; i++){
            
            int row, col;
            if(flag){
                row = 0, col = i;
                while(row <= i && col >= 0){
                    ans.push_back(mat[row][col]);
                    row++, col--;
                }
                flag = false;
            }
            else{
                row = i, col = 0;
                while(row >= 0 && col <= i){
                    ans.push_back(mat[row][col]);
                    row--, col++;
                }
                flag = !flag;
            }
        }
        
        // Lower triangle traversal of the matrix.
        for(int i=1; i<n; i++){
            
            int row, col;
            if(flag){
                row = i, col = n-1;
                while(row <= n-1 && col >= i){
                    ans.push_back(mat[row][col]);
                    row++, col--;
                }
                flag = false;
            }
            else{
                row = n-1, col = i;
                while(row >= i && col <= n-1){
                    ans.push_back(mat[row][col]);
                    row--, col++;
                }
                flag = !flag;
            }
        }
        
        return ans;
    }
};


int main()
{
    
    return 0;
}