#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// question link -> https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

int main()
{
    
    return 0;
}

    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto i:nums)
            freq[i] ++;

// minimum number of rows we required is the maximum of the second element of freq.
        int maxi = -1;
        for(auto it:freq){
            maxi = max(maxi, it.second);
        }

        // minimum number of rows = maxi
        vector<vector<int>> store(maxi);
        for(int i = 0; i<maxi; i++)
        {
            for(auto &it:freq)
            {
                if(it.second > 0)
                {
                    store[i].push_back(it.first);
                    it.second--;
                }
            }
        }
        return store;
    }