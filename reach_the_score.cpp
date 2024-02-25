#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1


// for count distinct in the memoization we need to use the set or string or vector more thing which increases our space and not more optimal then tabulation.

    // t.c = O(n + n + n)  ||  s.c = O(n)
    long long int count(long long int n)
    {
        // tabulation code.
        vector<long long int> dp(n+1, 0);
    	dp[0] = 1;  // base case of recurion.
    	
    	//earn points 3.
    	for(int i=3; i<=n; i++){
    	    dp[i] += dp[i-3];
    	}
    	
    	for(int i=5; i<=n; i++){
    	    dp[i] += dp[i-5];
    	}
    	
    	for(int i=10; i<=n; i++){
    	    dp[i] += dp[i-10];
    	}
    	
    	return dp[n];
    }

int main()
{

    return 0;
}