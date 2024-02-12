#include <iostream>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/recursive-sequence1611/1

class Solution
{
    int mod = 1e9 + 7;

public:
    long long sequence(int n)
    {

        if (n == 1)
            return 1;

        long long ans = 1;
        int start = 2;
        for (int i = 2; i <= n; i++)
        {
            long long mul = 1;
            for (int j = 0; j < i; j++)
            { // it runs the number of time of i
                mul = (mul * start) % mod;
                start++;
            }

            ans = (ans + mul) % mod;
        }
        return ans % mod;
    }
};

int main()
{

    return 0;
}