// https://www.geeksforgeeks.org/problems/largest-rectangular-sub-matrix-whose-sum-is-0/1/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
    int row = a.size();
    int col = a[0].size();
    
    // making a new prefixsum array
    vector<vector<int>> prefixSum(row+1, vector<int>(col+1, 0));
    for(int i = 1; i<=row; i++)
    {
        for(int j = 1; j<=col; j++)
        {
            prefixSum[i][j] += prefixSum[i][j-1] + a[i-1][j-1];
        }
    }
    
    /*
    // printing the prifix sum
    for(int i = 1; i<=row; i++)
    {
        for(int j = 1; j<=col; j++)
        {
            cout<<prefixSum[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    
    int maxArea = -1, scol = -1, ecol = -1, srow = -1, erow = -1;
    // fixing the start col
    for(int i = 1; i<=col; i++ )
    {
        // fixing the end col
        for(int j = i; j<= col; j++)
        {
            unordered_map<int,int>mp;
            mp[0] = 0;
            int currSum = 0;
            
            // row wise traversal
            for(int k = 1; k<=row; k++)
            {
                // yha pr jo minus kr rhe hai, taki i se j ke range ka hee sum mile, i-1 wala sum nhi.
                currSum += prefixSum[k][j] - prefixSum[k][i-1];
                // cout<<"currSum -> "<<currSum<<endl;
                if(mp.find(currSum) != mp.end())
                {
                    int area = (j-i+1) * (k-mp[currSum]);
                    if(area > maxArea)
                    {
                        maxArea = area;
                        srow = mp[currSum]; erow = k; scol = i; ecol = j;
                    }
                }
                else{
                    mp[currSum] = k;
                }
            }
        }
    }
    
    // cout<<"srow -> "<<srow<<endl<<"scol -> "<<scol<<endl<<"erow -> "<<erow<<endl<<"ecol -> "<<ecol<<endl;
    erow--;scol--;ecol--;
    vector<vector<int>> ans;
    for(int i = srow; i<=erow; i++)
    {
        vector<int>temp;
        for(int j = scol; j<=ecol; j++)
        {
            temp.push_back(a[i][j]);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    
    return 0;
}