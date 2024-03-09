#include<iostream>
#include<vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/minimum-common-value/?envType=daily-question&envId=2024-03-09


class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
// method 1 -> Two pointer approach.
// method 2 -> linear search + binary search => t.c = O(n * log m) 
                // [n = length of nums1, m = length of nums2]

        int i = 0, j = 0;
// t.c = O(n + m)  ||  s.c = O(1)
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <  nums2[j])
                i++;
            else if(nums1[i] > nums2[j])    j++;
            else return nums1[i];
        }
        return -1;
    }
};


int main()
{
    
    return 0;
}