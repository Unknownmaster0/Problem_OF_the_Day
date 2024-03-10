#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1

string removeDuplicates(string str)
{
    unordered_map<char, int> freq;
    string ans = "";
    for (auto it : str)
    {

        if (freq.find(it) == freq.end())
        {
            ans += it;
        }
        freq[it]++;
    }
    return ans;
}

int main()
{
    string str = "HaPpyNewYear";
    return 0;
}