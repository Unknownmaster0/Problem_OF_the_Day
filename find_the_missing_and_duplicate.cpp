#include<iostream>
#include<vector>
using namespace std;

// problem link -> https://leetcode.com/problems/set-mismatch/?envType=daily-question&envId=2024-01-22

vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = -1;
        int mis = -1;
        for (int i = 0; i < n; i++) {
            if (nums[abs(nums[i]) - 1] < 0) {
                dup = abs(nums[i]);
            } else
                nums[abs(nums[i]) - 1] *= (-1);
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                mis = i + 1;
                break;
            }
        }
        return {dup, mis};
    }


/*
    vector<int> findErrorNums(vector<int>& nums) {

    // method 1 -> 
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> ans(2,0);
        unordered_map<int,int> mp;

        for(int i = 0; i<n; i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] ++;
            }
            else if(mp.find(nums[i]) != mp.end()){
                ans[0] = nums[i];
            }
            if(mp.find(i+1) == mp.end()){
                cout<<"i+1-> "<<i+1<<endl;
                ans[1] = i+1;
            }
        }

        return ans;

// method 2 -> nice one.
        int dup = -1, miss = -1;
        vector<int>arr(n+1, 0);
        arr[0] = -1;
        for(auto it:nums){
            arr[it]++;
        }

        for(int i = 1; i<=n; i++){
            if(arr[i] > 1) dup = i;
            if(arr[i] == 0) miss = i;
        }

        return {dup, miss};

// method 3:
        for(int i = 1; i<n; i++){
            if(nums[i] == nums[i-1]){
                ans[0] = nums[i];
                break;
            }
        }
        for(int i = 0; i<n; i++){
            if(nums[i] != i+1){
                ans[1] = i+1;
                break;
            }
        }
        return ans;
    }
*/

int main()
{
    
    return 0;
}