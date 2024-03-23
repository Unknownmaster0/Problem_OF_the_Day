#include<iostream>
#include<vector>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/fibonacci-series-up-to-nth-term/1


// Code =>
// t.c = O(n)   ||  s.c = O(n)
class Solution {
  public:
    vector<int> Series(int n) {
        int mod = 1e9+7;
        vector<int> fib;
        int prev_prev = 0, prev = 1;
        
        fib.push_back(prev_prev);
        fib.push_back(prev);
        
        for(int i=2; i<=n; i++){
            int next = (prev + prev_prev) % mod;
            prev_prev = prev;
            prev = next;
            fib.push_back(prev);
        }
        
        return fib;
    }
};


int main()
{
    
    return 0;
}