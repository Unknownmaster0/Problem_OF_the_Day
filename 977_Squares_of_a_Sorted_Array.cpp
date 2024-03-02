#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02

vector<int> sortedSquares(vector<int> &nums)
{
    /*  Method 1 -> using the sort function
            // t.c = O(n * log n)
            for(auto &it: nums){
                it *= it;
            }
            sort(nums.begin(), nums.end());
            return nums;
    */

    // Method 2 -> using two pointer // t.c = O(N)
    // in terms of absolute value of the number, the array is not sorted.
    int n = nums.size();
    int start = 0, end = n - 1;
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        if (abs(nums[start]) >= abs(nums[end]))
        {
            ans[i] = nums[start] * nums[start];
            start++;
        }
        else
        {
            ans[i] = nums[end] * nums[end];
            end--;
        }
    }

    return ans;
}

int main()
{

    return 0;
}