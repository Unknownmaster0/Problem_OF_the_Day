#include<iostream>
#include<vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/first-missing-positive/description/?envType=daily-question&envId=2024-03-26


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
/*
// METHOD 1 -> USING SORTING.
        sort(nums.begin(), nums.end());
        int missing = 0;
        for(auto it:nums){
            if(it <= 0) continue;
            else if(it != missing){
                if(it == missing + 1)   missing = it;
                else return missing + 1;
            }
        }

        return missing+1;
*/

// Method 2 -> using the input array to mark the numbers.
    // THIS IS SIMILAR KIND OF PREVIOUS DAY POTD, WHERE WE USE THE SAME INPUT ARRAY TO MARK THE 
    // VISITED OF THE IDX WHICH COMES.

        int n = nums.size();

        // step1-> if there is any element less or equal to 0, then we need to avoid it.
        //          for avoiding we mark it with the value, n+1 which is out of the size of nums
        for(auto &it:nums){
            if(it <= 0){
                it = n+1;
            }
        }

        // step 2-> Now, whichever elements now (+)nt in array is only positive number greater than 0
        // if element is less or equal to n, then use it to mark the visited idx.
        for(auto &it:nums){
            int element = abs(it);
            if(element <= n){
                // mark the correspoding index visited.
                nums[element-1] = -abs(nums[element-1]);
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] > 0) // it means it is not visited by anyone.
                return i+1; // return 1-based, because (+)ve element are from 1..........
        }

        return n+1; // if every element is visited, menas all the first n (+)ve numbers are (+)nt.
        // thus return the next (+)ve number, which is n+1.
    }
};


int main()
{
    
    return 0;
}