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

    /*************** Method 2 -> using sliding window approach *******************/

        /* sliding window technique using the count of one,two, and zero.
    
        We increment the count of one, two, zero till we not get all three elements.
        
if we get all three elements then we calculate the length and then decrease the window size from the 
left and check everytime, if after decreasing the left index element count, if still all three elements
        are present then update the length and still decrease the window size from the left.
        
        when we not get all the three different elements then increase the window size from the right.
        */
    int smallestSubstring(string s)
    {
        int n = s.length();
        int one = 0, two = 0, zero = 0;
        int len = INT_MAX;
        int j = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '1') one++;
            else if(s[i] == '2') two ++;
            else    zero++;
            
            if(one != 0 && two != 0 && zero != 0)
            {
                len = min(len, i-j+1);
                while(one >= 1 && two >= 1 && zero >= 1 && j < i)
                {
                    if(s[j] == '1') one--;
                    else if(s[j] == '0') zero--;
                    else two--;
                    j++;
                    if(one != 0 && two != 0 && zero != 0)
                        len = min(len, i-j+1);
                }
            }
        }
        
        if(len == INT_MAX)  return -1;
        return len;
    }