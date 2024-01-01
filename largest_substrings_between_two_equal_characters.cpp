#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// leetcode potd -> https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/?envType=daily-question&envId=2023-12-31

int main()
{
    
    return 0;
}
  
// Method 1 -> using the frequency array to store the starting and ending indexes of the characters. [Beats 100%  of the solution.]
    int maxLengthBetweenEqualCharacters(string s) {
        int maxLength = -10;
        vector<pair<int,int>> freq(26,{-1,-1});

        // storing the starting and ending index of the character.
        for(int i = 0; i<s.length(); i++)
        {
            int idx = s[i]-'a';
            if(freq[idx].first == -1 && freq[idx].second == -1)
            {
                freq[idx] = {i,i};
            }
            else{
                freq[idx].second = i;
            }
        }

        // printing the freq array
        // now finding the maximum difference between the starting and ending idx
        for(auto i:freq)
        {   
            if(i.first != -1 && i.second != -1)
            {
                int diffIdx = i.second - i.first - 1;
                maxLength = max(diffIdx, maxLength);
            }
        }
        return maxLength;
    }

/*********************Brutforce one ************************/
// Method 2 -> you can also use the two nested loop to iterate over the strings.
/*The outer loop will find the first occurrece of the character, and the inner loop will find the second occurrence of that character again, if it found again in nested loop , then calculate the distance between the left and right.*/

// Time complexity -> O(N) [N is the length of the string.]
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        for (int left = 0; left < s.size(); left++) {
            for (int right = left + 1; right < s.size(); right++) {
                if (s[left] == s[right]) {
                    ans = max(ans, right - left - 1);
                }
            }
        }
        
        return ans;
    }


// Method 3 -> using the unordered_map
/*map will keep the mapping of character to their starting index. when we encounter that element again, then we count the distance between the starting index and the current index and store in some variable maxLength.*/
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> firstIdx;
        int maxLength = -1;
        for(int i = 0; i<s.length(); i++)
        {
            if(firstIdx.find(s[i]) != firstIdx.end())
            {
                // if found earlier then calculate the distance.
                int dist = i-firstIdx[s[i]] -1;
                maxLength = max(maxLength , dist);
            }
            else
                firstIdx[s[i]] = i;
        }
        return maxLength;
    }
