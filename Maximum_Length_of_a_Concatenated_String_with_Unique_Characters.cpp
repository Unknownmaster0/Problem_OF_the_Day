#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// problem link -> https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/?envType=daily-question&envId=2024-01-23

    /*
    int solve(vector<string>&arr, int idx, string str){
        unordered_set<char>st (str.begin(), str.end());
        if(str.size() != st.size()) return 0;
        if(idx >= arr.size())  return str.size();

        int len = str.size();
        len = max(len,solve(arr, idx+1, str + arr[idx]));
        len = max(len,solve(arr, idx+1, str));

        return len;
    }*/

// just simple thing -> take and not take.
    int solve(vector<string>&arr, int idx, string& str){
        unordered_set<char>st (str.begin(), str.end());
        if(str.size() != st.size()) return 0;
        if(idx >= arr.size())  return str.size();
        int len = str.size();

        for(auto it:arr[idx]) str.push_back(it);
        len = max(len, solve(arr, idx+1, str));

        // backtracking step
        for(auto it:arr[idx]) str.pop_back();
        len = max(len, solve(arr, idx+1, str));

        return len;
    }

    int maxLength(vector<string>& arr) {
        string ans = "";
        return solve(arr,0,ans);
    }

int main()
{
    
    return 0;
}