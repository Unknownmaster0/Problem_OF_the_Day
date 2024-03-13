#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/generalised-fibonacci-numbers1820/1

// code
class Solution {
    
    // matrix multiplication function.
    vector<vector<long long>> multiply(vector<vector<long long>> &first, vector<vector<long long>> &second, long long &m)
    {

        int n = first.size();
        int r = second.size();
        int c = second[0].size();
        vector<vector<long long>> ans(n, vector<long long>(c, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < c; j++)
            {
                for (int k = 0; k < r; k++)
                {
                    // need to take the modulo in each step every time.
                    ans[i][j] += (first[i][k] * second[k][j]) % m;
                }
            }
        }

        return ans;
    }
    
    // fast power exponentiation calculation function -> t.c = O(log n)
    // this is recursive code 
/*
    vector<vector<long long>> fastPower(vector<vector<long long>> &mat, long long n, long long &m)
    {

        if (n == 1)
            return mat;

        long long half = n / 2;

        vector<vector<long long>> ans = fastPower(mat, half, m);

        ans = multiply(ans, ans, m);

        if (n % 2 == 1)
        {
            ans = multiply(ans, mat, m);
        }

        return ans;
    }
*/
    
    // this is iterative approach of fast power 
    vector<vector<long long>> fastPower(vector<vector<long long>> &mat, long long n, long long m){

        int size = mat.size();
        vector<vector<long long>> res(size, vector<long long>(size, 0));
        // making identity matrix.
        for(int i=0; i<size; i++){
            res[i][i] = 1;
        }

        while(n > 0){
            // odd
            if(n % 2 != 0){
                res = multiply(res, mat, m);
            }
            mat = multiply(mat, mat, m);
            n >>= 1;
        }

        return res;
    }
    
  public:
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        
        if(n == 1 || n == 2)    return (1 % m);
        
        vector<vector<long long>> second(3, vector<long long>(3, 0));
        
        second[0][2] = second[1][0] = second[2][2] = 1;
        second[0][0] = a, second[0][1] = b;
        
        vector<vector<long long>> ans = fastPower(second, n-2, m);

        vector<vector<long long>> third (3, vector<long long>(1, 0));
        third[0][0] = third[1][0] = 1;
        third[2][0] = c;
        
        ans = multiply(ans, third, m);
        
        return ans[0][0] % m;
    }
};


int main()
{

    return 0;
}