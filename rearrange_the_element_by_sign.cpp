#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/rearrange-array-elements-by-sign/description/?envType=daily-question&envId=2024-02-14

int main()
{

    return 0;
}

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        int pos = 0, neg = 1;
/*      
// METHOD 1 -> THIS IS ALSO RUNNING GOOD, BUT HAVING SOME BIT OF MORE TIME. O(POS + NEG)
        while(pos < n && neg < n){
            while(nums[pos] < 0 && pos < n)    pos++;
            while(nums[neg] > 0 && neg < n)    neg ++;

            ans.push_back(nums[pos]);
            ans.push_back(nums[neg]);

            pos++, neg++;
        }
        return ans; */

// METHOD 2 -> HAVING LESS TIME = O(N)
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                ans[pos] = nums[i];
                pos += 2;
            }
            else{
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }
};