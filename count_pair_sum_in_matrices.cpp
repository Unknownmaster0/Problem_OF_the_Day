#include<iostream>
#include<vector>
using namespace std;


class Solution{
    
    bool binarySearch(vector<vector<int>> &mat, int s, int e, int n, int target){
        
        // element in one row of the mat is -> 'n'
        
        while(s <= e){
            int mid = s + (e-s)/2;
            
            int row = mid/n, col = mid % n;
            int midVal = mat[row][col];
            
            if(midVal == target)    return true;
            else if(midVal < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        
        return false;
    }
    
public:	
/*approach -> traversing the first matrix and then find the corresponding newtarget value, in the second matrix.
                As, the matrix is in sorted order, then we can apply "binary search approach for searching."
*/

	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    int cntPair = 0;
	    for(auto itr:mat1){
	        for(auto val: itr){
	            
	            int newtarget = x - val;
	            
	            if(binarySearch(mat2, 0, n*n-1, n, newtarget)){
	                cntPair++;
	            }
	        }
	    }
	    
	    return cntPair;
	}
};


int main()
{
    
    return 0;
}