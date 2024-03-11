#include<iostream>
#include<vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11

// code
class Solution {
public:
    string customSortString(string order, string s) {

// Optimal approach -> t.c = O(N)   ||  s.c = O(constant)
        int freq[26] = {0};
// storing the freq of given original string.
        for(auto it:s){
            freq[it-'a']++;
        }

// storing in 'ans' which character is coming first in the order string, to sort the given string.
        string ans;
        for(auto it:order){
            while( (freq[it-'a']--) > 0){
                ans.push_back(it);
            }
        }

// storing the left part of the original string.
        for(int i=0; i<26; i++){
            while(freq[i]-- > 0){
                ans.push_back(i+'a');
            }
        }

        return ans;
    }
};


int main()
{
    
    return 0;
}