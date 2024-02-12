#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Problem link -> https://leetcode.com/problems/majority-element/?envType=daily-question&envId=2024-02-12

int main()
{
    
    return 0;
}

class Solution {

    int sorting(vector<int>&nums){
        sort(nums.begin(),nums.end());
        return (nums[nums.size()/2]);
    }

    int bitmask(vector<int>&nums){
        int majoritySize = nums.size()/2;
        int majorityElement = 0;
        
        // checking the setbit for all the 32 bits
        for(int i=0; i<32; i++){
            int countSetBit = 0;
            for(auto it:nums){
                if((it & (1<<i)) != 0)  countSetBit++;
            }
            if(countSetBit > majoritySize){
                majorityElement |= (1<<i);
            }
        }
        return majorityElement;
    }

    int voting(vector<int>&nums){
        int majorityElement = -1, voting =0;
        for(auto it:nums){
            if(voting == 0) majorityElement = it;
            else if(majorityElement != it) voting --; // when find differ element.
            else if(majorityElement == it)  voting++; // when find same element.
        }
        int count = 0;
        for(auto it:nums){
            if(it == majorityElement)   count++;
        }
        if(count > nums.size()/2)   return majorityElement;
        return -1;
    }


public:
    int majorityElement(vector<int>& nums) {
/* method 1 -> using the unordered map 
        Time complexity -> O(N)
        space complexity -> O(N)
        unordered_map<int,int>mp;
        int comp = nums.size() / 2;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int element = -1; // pointing to the maximum occurrence element.
        for(auto i:mp){
            if(i.second > comp){
                element = i.first;
                break;
            }
        }
        return element;
        */

/************ method 2 -> using the sorting algorithm
            Time complexity -> O(N*logN)
            Space complexity -> O(log N)
 *****************/
        // return sorting(nums);

/************* method3 -> using bit manipulation
            Time complexity -> O(N * log 10^9)
            Space complexity -> O(1)
 *************/
        // return bitmask(nums);

/*********** method 4 -> Bore moore voting algorithm
            Time complexity -> O(N)
            Space complexity -> O(1)
 *******************/
        return voting(nums);

    }
};