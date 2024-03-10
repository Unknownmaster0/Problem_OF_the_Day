#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


//Problem link -> https://leetcode.com/problems/intersection-of-two-arrays/?envType=daily-question&envId=2024-03-10


class Solution
{
    bool binarySearch(vector<int> &nums2, int num, int n2)
    {
        int s = 0, e = n2 - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (nums2[mid] == num)
            {
                return true;
            }
            else if (nums2[mid] < num)
                s++;
            else
                e--;
        }
        return false;
    }

public:
    /* 3 Approaches to solve this question ->
        Approach 1 -> using unordered_map or hashmap.
                        t.c = O(n1 + n2)    [n1 -> size of nums1, n2 -> size of nums2]
                        s.c = O(n1 + n2)

        Approach 2 -> using sorting and Two pointer and unordered_map [for stoping the addition of same element]
                        t.c = O(n1 log(n1) + n2 log(n2))[for sorting]  + O(n1 + n2)[for traversing]
                        s.c = O(log(n1) + log(n2)) [for sorting recursion stack space.]

        Approach 3 -> using sorting and binary search and unordered_map [for stoping the addition of same element]
                        t.c = O(n1 log(n1) + n2 log(n2))[for sorting]  + O(n1 log(n2))[for traversing and applying
                                                                                        binary search on nums2]
                        s.c = O(log(n1) + log(n2)) [for sorting recursion stack space.]
    */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;
        unordered_map<int, int> freq;

        /*
                // Approach 1 ->
                for(auto it:nums1){
                    freq[it]++;
                }

                for(auto it:nums2){
                    if(freq.find(it) != freq.end()){
                        ans.push_back(it);

            // as we store the curr intersection value, thus, we don't want again to come into answer, so remove this from
            // freq map.
                        freq.erase(it);
                    }
                }
        */
        /*
                // Approach 2 ->
                int i=0, j=0;
                while(i < n1 && j < n2){
                    if(nums1[i] == nums2[j] && !freq[nums1[i]]){
                        freq[nums1[i]]++;
                        ans.push_back(nums1[i]);
                        i++, j++;
                    }
                    else if(nums1[i] > nums2[j]) j++;
                    else i++;
                }
        */

        // Approach 3 -> using binary search
        for (auto it : nums1)
        {
            freq[it]++;
        }
        for (auto it : freq)
        {
            // find it.first in the nums2

            int num = it.first;
            if (binarySearch(nums2, num, n2))
            {
                ans.push_back(num);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}