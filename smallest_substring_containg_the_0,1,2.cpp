#include<iostream>
#include<limits.h>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1

int main()
{
    
    return 0;
}

// very easy approach but can also be solved using the sliding window technique.
    int smallestSubstring(string s) {
        int one = -1, two = -1, zero = -1;
        int len = INT_MAX;
        
        // Store the index of the one zero, and two . And calculate the length everytime.
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i]-'0' == 1)   one = i;
            else if(s[i]-'0' == 0)  zero = i;
            else if(s[i]-'0' == 2)   two = i;
            
            if(one != -1 && two != -1 && zero != -1){
                len = min(len, max(one, max(two, zero)) - min(one, min(two, zero)) + 1);
            }
        }
        
        if(len == INT_MAX)  return -1;
        return len;
    }