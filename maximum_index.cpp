#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/maximum-index-1587115620/1

int maxIndexDiff(int arr[], int n)
{
    int ans = -1;
    /*
            // bruforce -> t.c = O(n ^ 2)
            for(int i=0; i<n; i++){
                for(int j=n-1; j>=i; j--){
                    if(arr[j] >= arr[i]){
                        ans = max(ans, j-i);
                    }
                }
            }
            return ans;
    */

    // Optimal Approach -> Using the Prefix and suffix array.
    // find the suffix maximum array and prefix minimum array.
    // suffix maximum array -> contains the maximum elements from [i, n-1]
    // prefix minimum array -> contains the minimum elements from [0,i]

    // building the array
    int suffixMax[n] = {0}, prefixMin[n] = {0};

    suffixMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], arr[i]);
    }

    prefixMin[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixMin[i] = min(prefixMin[i - 1], arr[i]);
    }

    // now traverse over the prefixMin and suffixMax array and two condition to notice.
    // if prefixMin[i] > suffixMax[j] -> only increment i.
    // if suffixMax[j] >= prefixMin[i] -> increment j as well as also update your answer as(j-i);

    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (prefixMin[i] > suffixMax[j])
            i++;

        else if (suffixMax[j] >= prefixMin[i])
        {
            ans = max(ans, j - i);
            j++;
        }
    }
    return ans;
}

int main()
{
    int arr[9] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    cout << "the maximum index of j-i which satisfy the condition is -> " << maxIndexDiff(arr, 9) << endl;
    return 0;
}