#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// problem link -> https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

class Solution {
    // bool checkPalindrome(string str){
    //     int n = str.size();
    //     int s = 0, e = n-1;
    //     while(s < e){
    //         if(str[s++] != str[e--])    return false;
    //     }
    //     return true;
    // }
public:
    string firstPalindrome(vector<string>& words) {
        for(auto inputString: words){
            // if(checkPalindrome(inputString)) return inputString; // METHOD 1 -> USING THE CUSTOM FUNCION TO CHECK
            string s = inputString;
            reverse(s.begin(),s.end()); // METHOD 2 -> USNIG THE REVERSE PROPERTY OF THE STRING
            if(s == inputString)    return inputString;
        }
        return "";
    }
};

int main()
{
    
    return 0;
}