#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// problem link -> https://leetcode.com/problems/count-elements-with-maximum-frequency/?envType=daily-question&envId=2024-03-08

class Solution {
public:

// t.c = O(N) || s.c = O(N)  [where 'N' is the number of elements in the nums.]
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = -1, total = 0;
        unordered_map<int,int> freq;
// storing the frequency of each element.
        for(auto it:nums){
            freq[it] ++;
            maxFreq = max(maxFreq, freq[it]);
        }
// now making the total of the elements having frequency equals to maximum frequency.
        for(auto it:freq){
            if(it.second == maxFreq)
                total += it.second;
        }

        return total;
    }
};

int main()
{

    return 0;
}