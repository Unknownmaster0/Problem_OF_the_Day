#include <iostream>
#include <unordered_map>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1

// t.c = O(n)
int firstElementKTime(int n, int k, int a[])
{
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
        if (freq[a[i]] == k)
            return a[i];
    }
    return -1;
}

int main()
{

    return 0;
}