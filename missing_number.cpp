#include<iostream>
#include<vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/missing-number/?envType=daily-question&envId=2024-02-20

    int missingNumber(vector<int>& nums) {
/*  METHOD 1 -> USING XOR OPERATOR.
        int x = 0;
        for(int i=1; i<=nums.size(); i++){
            x = x ^ i ^ nums[i-1];
        }
        return x;
*/
// METHOD 2 -> USING THE MATHS TECHNIQUE 
// [FIND THE SUM OF 1-N NUMBERS AND SUBSTRACT THE SUM OF ENTIRE ARRAY = TO GET EXACT MISSING ELEMENT]
        int n = nums.size();
        int sumTillN = (n * (n+1)) / 2;
        // calculate the sum of whole array element.
        int sumElement = 0;
        for(int i=0; i<n; i++)  sumElement += nums[i];

        // finally substract them to get exact missing element.
        return sumTillN - sumElement;
    }

int main()
{
    int n;
    cin>>n; 
    vector<int>nums(n,0);
    for(int i=0; i<n; i++)  cin>>nums[i];

    cout<<"missing number -> "<<missingNumber(nums)<<endl;
    return 0;
}