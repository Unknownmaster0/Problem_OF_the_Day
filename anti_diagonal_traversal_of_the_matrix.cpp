#include<iostream>
#include<vector>
using namespace std;

int main()
{
    
    return 0;
}
vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
{
    int n = matrix.size();
    
    vector<int> ans;
    
    // printing the first half of the diagnoal elements.
    for(int i = 0; i<n; i++)
    {
        int col = i;
        for(int j = 0; j<n; j++)
        {
            ans.push_back(matrix[j][col--]);
            // cout<<matrix[j][col--]<< " ";
            if(i == j)
                break;
        }
    }
    
    // printing the rest half of the diagonal elements.
    for(int r = 1; r < n; r++)
    {
        int row = r;
        for(int c = n-1; c >=1; c--)
        {
            ans.push_back(matrix[row++][c]);
            // cout<<matrix[row++][c]<<" ";
            if(row >= n)
                break;
        }
    }
    
    return ans;
}