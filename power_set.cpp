#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/power-set4302/1

// You can also do this problem using recursion, it will take extra auxillary stack space, but the 
// time will remain same.

// power set method.
void f(string s, int len, vector<string> &store)
{

    for (int i = 1; i < (1 << len); i++)
    {
        string temp = "";
        for (int bit = 0; bit < len; bit++)
        {
            if ((i & (1 << bit)) > 0)
            {
                temp.push_back(s[bit]);
            }
        }
        store.push_back(temp);
    }
    sort(store.begin(), store.end());
}

vector<string> AllPossibleStrings(string s)
{
    vector<string> store;
    f(s, s.size(), store);
    return store;
}

int main()
{

    return 0;
}