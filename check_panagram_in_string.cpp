#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1

    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        
        //  method 1 -> using the extra space o(26) which is constant.
        // more efficent approach -> time = O(N) only.
        
        // space o(26) which is constant
        int alphabeat[26] = {0};
        
        for(auto it:s){
            alphabeat[tolower(it)-'a'] ++;
        }
        
        // time complexity -> O(26) [which is constant]
        for(int i = 0; i<26; i++){
            if(alphabeat[i] == 0)   return false;
        }
        return true;
        
        /*  Method 2 -> without using the extra space -> 
        
        // Time complexity -> O(N) [transform] + O(26 * N) [for searching the 26 characters into the string]
        // s.find -> O(N) time 
        
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i = 0; i<26; i++){
            char ch = i + 'a';
            if(s.find(ch) == string::npos)   return false;
        }
        return true;
        */
    }

int main()
{
    
    return 0;
}