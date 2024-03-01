#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/sum-of-bit-differences2937/1

/*Approach ->
                Checking for each bit for every number in the array, and couting the number of ones and zeros at every ith bit.
                As, we have to consider the pair -> thus multiply (zeros * ones)

                zeros = 3 [this means that, 3 number has 0 as its ith bit.]
                ones = 2 [this means that, 2 number has 1 as its ith bit.]
                how many pairs can be made -> (3 * 2) = 6 pairs.

                // detail approach in the copy.
*/

// code -> t.c = O(N)   [N is the size of the array.]
	long long sumBitDifferences(int arr[], int n) {
	    // take the data type as long long as that of function.
	    long long int bitDiff = 0;
	    for(int i=0; i<32; i++){
	        long long int zeros = 0, ones = 0;
	        for(int j=0; j<n; j++){
	            if((arr[j] & (1 << i) ) != 0)   ones++;
	            else    zeros++;
	        }
	        bitDiff += (zeros * ones);
	    }
	    
	    return bitDiff * 2;
	}

int main()
{

    return 0;
}