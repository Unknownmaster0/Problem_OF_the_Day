#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

// This question is only about writing the custiom "comparator" which help in sorting the concatenated string.

// sharing the string with '&' sign means no, new copy of the string has made.
static bool comparator(string &a, string &b)
{
    return a + b > b + a;
}

// The main function that returns the arrangement with the largest value as
// string.
// The function accepts a vector of strings
string printLargest(int n, vector<string> &arr)
{
    sort(arr.begin(), arr.end(), comparator);
    string res = "";
    for (auto it : arr)
    {
        res += it;
    }
    return res;
}

int main()
{

    return 0;
}