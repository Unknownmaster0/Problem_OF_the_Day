#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem link -> https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/?envType=daily-question&envId=2024-02-15

int main()
{

    return 0;
}

// time complexity -> O(N log N) [for sorting] + O(N) [for traversing the array.]
// space complexity -> O(log N) [for sorting time]
long long largestPerimeter(vector<int> &nums)
{

    // Method 1 -> This is done using the ascending order , You can also do by using the descending order way.
    sort(nums.begin(), nums.end());

    long long int perimeter = 0, sum = 0;
    sum += nums[0] + nums[1];
    for (int i = 2; i < nums.size(); i++)
    {
        int currElement = nums[i];
        if (sum > currElement)
        {
            perimeter = sum + currElement;
        }
        sum += currElement;
    }
    if (perimeter == 0)
        return -1;
    return perimeter;
}