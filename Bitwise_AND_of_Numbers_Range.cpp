#include <iostream>
using namespace std;

// Problem link -> https://leetcode.com/problems/bitwise-and-of-numbers-range/?envType=daily-question&envId=2024-02-21

int rangeBitwiseAnd(int left, int right)
{
    // what is said by question is do
    // right & right-1 & right-2 & right-3 & ................. & left
    /*as when we see right & right-1 then we think of removing the last setbit., thus everytime
    we are just removing the last set bit of the right number.*/
    while (right > left)
        right &= right - 1;
    return right;
}

int main()
{

    return 0;
}