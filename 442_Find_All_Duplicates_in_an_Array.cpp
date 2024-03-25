#include<iostream>
#include<vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/find-all-duplicates-in-an-array/description/?envType=daily-question&envId=2024-03-25


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
/*  MY APPROACH -> T.C = O(N * log N) || s.c = O(1)
        int i,j;
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size()-1;)
        {
            int count = 1;

            if(nums.at(i) == nums.at(i+1)){
                count++;
                ans.push_back(nums.at(i));
            }

            i += count;

        }
*/

    // Approach 2 -> modify the input array.

        for(auto it:nums){
            int idx = abs(it)-1;

            if(nums[idx] < 0){
                ans.push_back(abs(it));
            }else{
                nums[idx] *= -1;
            }
        }

        // revert back the changes that we done while calculating answer in input array.
        for(auto &it: nums){
            it = abs(it);
        }

        return ans;
    }
};

int main()
{
    
    return 0;
}