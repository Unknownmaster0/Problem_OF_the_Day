#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
    
    return 0;
}
    // Time complexity -> O(n)
    // space complexity -> O(n) [when all the elements are different.]
    vector<string> winner(string arr[],int n)
    {
// here we use the unordered_map because the time complexity to insert and search any element in it O(1) [constant itme.]
// here you can also use the map but it takes the time complexity to insert and search as O(Log n).
// normal map store the data in sorted order then we have no need to check for the condition when maxi == it.second.
        unordered_map<string,int> vote;
        vector<string> candidate;
        for(int i = 0; i<n; i++)
        {
            vote[arr[i]] ++;
        }
        
        int maxi = -1;
        string name = "";
        for(auto it:vote)
        {
            if(maxi < it.second)
            {
                maxi = it.second;
                name = it.first;
            }
            else if(maxi == it.second)
            {
                name = min(name, it.first);
            }
        }
        candidate.push_back(name);
        candidate.push_back(to_string(maxi));
        return candidate;
    }