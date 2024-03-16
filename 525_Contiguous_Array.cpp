#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Problem link -> https://leetcode.com/problems/contiguous-array/description/?envType=daily-question&envId=2024-03-16

// code 
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, maxlength = 0;
        unordered_map<int,int> freq; // mapping of sum -> intial idx of occurrence of sum

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0)
                sum += 1;
            else{
                sum += -1;
            }

            if(sum == 0)    maxlength = i+1;
            else if(freq.find(sum) != freq.end()){
                maxlength = max(maxlength, i-freq[sum]);
            }
            else
    // not always update the index of the sum, if you get the new sum then only update its value.
                freq[sum] = i;  
        }

        return maxlength;
    }
};

int main()
{
    
    return 0;
}