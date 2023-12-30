#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
    
    return 0;
}

    bool makeEqual(vector<string>& words) {
// simply count the number of the characters in the vector if they are equal then, it is possible to make strings equal else not.

        unordered_map<char,int>freq;
        for(int i = 0; i<words.size(); i++)
        {
            for(int j = 0; j<words[i].length(); j++)
            {
                freq[words[i][j]]++;
            }
        }

        for(auto it:freq)
        {
            // if the count of the each character is completely divided by the size of words, it means we can make it equal .
            // but when the (count % n) becomes not equal to zero then return false, as we can't able to make it equal.
            if(it.second % words.size() != 0) return false;
        }
        return true;
    }