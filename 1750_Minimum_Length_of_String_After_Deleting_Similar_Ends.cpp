#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/submissions/1194659458/?envType=daily-question&envId=2024-03-05

/*
// MY cheap code.
class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i=0, j = n-1;

        while( (i < j) && (s[i] == s[j]) ){
            i++, j--;
            while(i < n && s[i] == s[i-1])   i++;
            while(j>=i && s[j] == s[j+1])   j--;
        }

        if(i > j)  return 0;
        return j-i+1;
    }
};
*/

// t.c = O(n/2) || s.c = O(1)
// approach -> two pointer.
int minimumLength(string s)
{
    int n = s.length();
    int i = 0, j = n - 1;

    while ((i < j) && (s[i] == s[j]))
    {
        char ch = s[i];
        while (i < j && s[i] == ch)
            i++;
        while (j >= i && s[j] == ch)
            j--;
    }

    return j - i + 1;
}

int main()
{

    return 0;
}
