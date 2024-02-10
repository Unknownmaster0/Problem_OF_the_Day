#include<iostream>
using namespace std;

int check(int l, int r, string s){

    int ans = 0;
    while(l >=0 && r <= s.size()){
        if(s[l--] == s[r++]) ans ++;
        else   break;
    }
    return ans;
}

int countSubstrings(string s){  // consider s = "saghbhgab"

    int n = s.size(), cnt = 0;
    for(int i=0; i<n; i++)
    {
        cnt += check(i,i,s); // for odd palindrome length
        cnt += check(i,i+1,s); // for even palindrome length.
    }
    return cnt;
}

int main()
{
    
    return 0;
}