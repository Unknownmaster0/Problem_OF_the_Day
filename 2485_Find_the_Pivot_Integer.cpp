#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/find-the-pivot-integer/?envType=daily-question&envId=2024-03-13

// code
class Solution
{
public:
    int pivotInteger(int n)
    {
        if (n == 1)
            return 1;
        // METHOD 1 -> USING PREFIX SUM ARRAY, THEN CALCULATE -> T.C = O(N) || S.C = O(N)
        // Having better RUNTIME.
        /*
                vector<int> prefixSum(n, 0);
                prefixSum[0] = 1;
                for(int i=1; i<n; i++){
                    prefixSum[i] = prefixSum[i-1] + i+1;
                }

                for(int i=1; i<n; i++){
                    if(prefixSum[i] == prefixSum[n-1] - prefixSum[i-1])
                        return i+1;
                }
        */

        // METHOD 2 -> USING MATHS APPROACH OF FINDING THE SUM OF N NATURAL NUMBER -> T.C = O(N) || S.C = O(1)
        /*
                int currsum, lastsum;
                for(int i=1; i<n; i++){
                    currsum = (i*(i+1)) / 2;
                    lastsum = (n * (n+1)) / 2 - currsum + i;

                    if(currsum == lastsum)  return i;
                }
        */
        return -1;
    }
};

int main()
{

    return 0;
}