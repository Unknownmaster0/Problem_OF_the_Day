#include<iostream>
#include<vector>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

// Code ->

// t.c = O(2^n)    ||  s.c = O(2^n)
class Solution{
    
    void f(int i, int n, string temp, vector<string> &ans, int cnt1, int cnt0){
        
        if(i == n){
            ans.push_back(temp);
            return;
        }
        
        // take 1.
        f(i+1, n, temp + "1", ans, cnt1+1, cnt0);
        // take 0.
        if(cnt1 > cnt0)
            f(i+1, n, temp + "0", ans, cnt1, cnt0+1);
    }
    
public:	
	vector<string> NBitBinary(int n)
	{
	    vector<string> ans;
	    string temp = "";
	    f(0, n, temp, ans, 0, 0);
	    return ans;
	}
};


int main()
{
    
    return 0;
}