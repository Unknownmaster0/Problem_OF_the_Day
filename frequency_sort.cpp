#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

// problem link -> https://leetcode.com/problems/sort-characters-by-frequency/?envType=daily-question&envId=2024-02-07

// Time complexity ->   O(N) + O(N * log N) + O(N * log N)
    string frequencySort(string s) {

/*
you can also use the set method to solve this question. Most of the thing is same only 
use set in place of priority queue.

// set< pair<int, char> , greater<pair<int, char>> > st;

*/
        priority_queue< pair<int,char> > maxheap;
        unordered_map< char,int> freq;
        // O(N)
        for(char ch:s){
            freq[ch] ++;
        }
        // O(N) * O(log N)
        for(auto it:freq){
            // st.insert({it.second, it.first});
            // O(log N)
            maxheap.push({it.second,it.first});
        }
        string str = "";
        /*
        for(const auto& p:st){
            int count = p.first;
            while(count > 0){
                str += p.second;
                count--;
            }
        }*/

// O(N) * O(log N)
        while(!maxheap.empty()){
            auto it = maxheap.top();
            // O(log N)
            maxheap.pop();
            int count = it.first;
            char ch = it.second;
            while(count > 0){
                str += ch;
                count--;
            }
        }
        return str;
    }

int main()
{

    return 0;
}