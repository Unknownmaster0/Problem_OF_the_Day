#include <iostream>
#include <vector>
using namespace std;

// Asked in DShaw
// Problem link -> https://www.geeksforgeeks.org/problems/largest-subsquare-surrounded-by-x0558/1

// code ->
class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        // making the prefix sum vector for horizontal as well as vertical 
        vector<vector<int>> rowPrefix(n, vector<int>(n, 0));
        vector<vector<int>> colPrefix(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++){
            
            if(a[i][0] == 'X')  rowPrefix[i][0] = 1;
            if(a[0][i] == 'X')  colPrefix[0][i] = 1;
            
            for(int col = 1; col<n; col++){
                    
                if(a[i][col] == 'X'){
                    
                    int prev = rowPrefix[i][col-1];
                    if(prev == 0)
                        rowPrefix[i][col] += 1;
                    else
                        rowPrefix[i][col] = 1 + prev;
                }
            }
                
            for(int row = 1; row<n; row++){
                
                if(a[row][i] == 'X'){
                    
                    int prev = colPrefix[row-1][i];
                    if(prev == 0)
                        colPrefix[row][i] += 1;
                    else
                        colPrefix[row][i] = 1 + prev;
                }
            }
        }
        

        
        int maxsize = 0;
        for(int row = n-1; row >=0; row--){
            for(int col = n-1; col>=0; col--){
                
                int size = min( colPrefix[row][col], rowPrefix[row][col] );
                while(size > 0){
                    
                    if(colPrefix[row][col-size+1] >= size && rowPrefix[row-size+1][col] >= size)    break;
                    else
                        size--;
                }
                
                maxsize = max(maxsize, size);
            }
        }
        
        return maxsize;
    }
};

int main()
{

    return 0;
}