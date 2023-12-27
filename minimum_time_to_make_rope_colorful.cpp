// question link -> https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/?envType=daily-question&envId=2023-12-27

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    
    return 0;
}


// Time complexity -> O(N^2) [as the size of colors and neededTime is same.]
// can be optimised to O(N) -> we need to remove the inner loop.
int minCost(string colors, vector<int>& neededTime) {
    int minTime = 0;

    int n = colors.length();
    int sum = 0, maxi = -1;
    for(int i = 0; i<n; i++)
    {
        int startIdx = i;
        sum += neededTime[i];
        maxi = max(maxi, neededTime[i]);
// checking if the other ballons are of same colors than the curr ballons
        while(i < n-1 && colors[i] == colors[i+1])
        {
            i++;
            sum += neededTime[i]; 
            maxi = max(maxi, neededTime[i]);
        }
        int endIdx = i;

// currently no ballons of same colors
        if(startIdx == endIdx)
        {
            sum = 0, maxi = -1;
            continue;
        } 
/*
        for(int j = startIdx; j<=endIdx; j++)
        {
            sum += neededTime[j];
            maxi = max(maxi, neededTime[j]);
        }
*/
        int removedValue = sum - maxi;
        minTime += removedValue;

        sum = 0; maxi = -1;

    }

    return minTime;
}