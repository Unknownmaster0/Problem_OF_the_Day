#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1

    // memoization -> t.c = O(n) s.c = O(n) [for auxillary recursion stack space.] + O(n) [for ]
    int f(int idx, vector<int>& dp){
        if(idx == 0 || idx == 1)    return 0;
        
        if(dp[idx] != -1)   return dp[idx];
        
        int half = max(idx/2, f(idx/2, dp));
        int onethird = max(idx/3, f(idx/3, dp));
        int onefourth = max(idx/4, f(idx/4, dp));
        
        return dp[idx] = (half + onethird + onefourth);
    }
    
    
    // tabulation -> t.c = O(n) | s.c = O(n)
    int f(int n){
        vector<int> dp(n+1, -1);
        dp[0] = dp[1] = 0;

        for(int i=2; i<=n; i++){
            /*
            int half = max(i/2, dp[i/2]);
            int onethird = max(i/3, dp[i/3]);
            int onefourth = max(i/4, dp[i/4]);
            
            dp[i] = half + onethird + onefourth;
            */
           // above line can also be written like
           dp[i] = max(dp[i/2] + dp[i/3] + dp[i/4] , i);
        }
        
        return dp[n];
    }

    
    int maxSum(int n)
    {
        // for memoization
        // vector<int> dp(n+1, -1);
        // return max( n, f(n, dp) );

        // for tabulation
        // return max(n, f(n)); // for commented tabulation part method.
        return f(n);
    }

int main()
{

    return 0;
}