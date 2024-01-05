#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// problem link -> https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/?envType=daily-question&envId=2024-01-04

/*There are two types of operations that you can apply on the array any number of times:

Choose two elements with equal values and delete them from the array.
Choose three elements with equal values and delete them from the array.
Return the minimum number of operations required to make the array empty, or -1 if it is not possible.*/

int main()
{
    
    return 0;
}

    /*just store the count of each element in the map, and then 
    if the count is divisible by 3 and leaving no remainder then increment ans by quotient times.
    else when the count/3 leaves remainder greater than 0, then increment the ans by quotient + 1 time , 1 for making the new pair with the other.
    */

    int minOperations(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto it:nums)
            freq[it]++;

        // now storing the quotient sum.
        int ans = 0;
        for(auto it:freq)
        {
            if(it.second <= 1)  return -1;
            int mod = it.second % 3;
            // leaves reaminder greater than 0
            if(mod > 0)
                ans += (it.second / 3) + 1;
            else 
                ans += (it.second) / 3;
        }
        return ans;
    }