#include<iostream>
#include<vector>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/longest-repeating-and-non-overlapping-substring3421/1

// BASED ON LONGEST COMMON SUBSTRING finding question.
    string longestSubstring(string s, int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        
        int length = 0, idx = -1;
        
        // Base cases are not much important as it is pointing to the 0 only, which my contains earlier.
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                // to avoid overlapping we should start the jth idx with 1 after the ith idx always.
                if(s[i-1] == s[j-1]){
                    int len = dp[i-1][j-1] + 1;
                    if(len <= j-i){
                        dp[i][j] = len;
                        
                        if(length < dp[i][j]){
                            length = dp[i][j];
                            idx = i-1;
                        }
                    }
                }
            }
        }
        
        // now printing the string.
        string ans = "";
        if(length > 0){
            
            int startIdx = idx-length+1;
            for(int i=startIdx; i<= idx; i++){
                ans += s[i];
            }
        }
        else
            return "-1";
            
        return ans;
    }


int main()
{
    
    return 0;
}