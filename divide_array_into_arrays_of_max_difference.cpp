#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// problem link -> https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/?envType=daily-question&envId=2024-02-01

// My approach -> simply but efficient.
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i<n; i+=3)
        {
            int first = nums[i];
            int second = nums[i+1];
            int third = nums[i+2];

            if(second - first <= k && third-second <= k && third-first <= k){
                vector<int> temp;
                temp.push_back(first);
                temp.push_back(second);
                temp.push_back(third);
                ans.push_back(temp);
            }
            else 
                return {};
        }
        return ans;
    }

// Another efficient approach -> 
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
    
        vector<int> vec;
        vector<vector<int>> empty;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        vec.push_back(nums[0]);

        for(int i = 1; i<nums.size(); i++)
        {
            // condition 1 -> if diff b/w the curr element of nums and vec[0] is greater then k, then simply return the empty array
            if(vec.size() < 3 && nums[i]-vec[0] > k)  return empty;

            // condition 2 -> if diff b/w the curr element of nums and vec[0] is less or equal to k, then push curr into vec
            else if(vec.size() < 3 && nums[i] - vec[0] <= k)    vec.push_back(nums[i]);

            
            // condition 3 -> if the vec.size() == 3 means we get 1 vec of our choice then push into the ans vector and clear the vec. and also insert the curr element for the future calculation
            else if(vec.size() == 3){
                ans.push_back(vec);
                vec.clear();
                vec.push_back(nums[i]);
            }
        }
        return ans;
    }

int main()
{
    
    return 0;
}