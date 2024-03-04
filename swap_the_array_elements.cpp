#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/need-some-change/1

void swapElements(int arr[], int n)
{

    for (int i = 0; i < n - 2; i++)
    {
        if (i + 2 < n)
            swap(arr[i], arr[i + 2]);
    }
}

int main()
{

    return 0;
}