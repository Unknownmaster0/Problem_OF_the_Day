// gfg potd.
// problem link -> https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    
    return 0;
}

bool canPair(vector<int> nums, int k) {
        int freq[k] = {0};
        
        // reduce the original array to the nums[i] % k;
        for(int i = 0; i<nums.size(); i++)
        {
            nums[i] = nums[i] % k;
        }
        
        // print the original array after reducing.
        // for(auto it:nums)
        //     cout<<it<<" ";
        // cout<<endl;
        
        // now in the original array there will the elements from [0, k-1] which is the remainder when nums[i] % k
        // store the occurrece of each remainder, and check if they occur in the pair or not.
        for(int i = 0; i<nums.size(); i++)
        {
            freq[nums[i]] ++;
        }
        
        // printing the frequency array.
        // for(int i = 0; i<k; i++)
        //     cout<<freq[i]<<" ";
        // cout<<endl;
        
        // now iterate over the freq array and check whether the pair exist or not.
        // check the 0th element alone.
        if(freq[0] % 2 != 0) return false;
        int i = 1, j = k-1;
        while(i < j)
        {
            if(freq[i] != freq[j])  return false;
            i++;j--;
        }
        return true;
    }