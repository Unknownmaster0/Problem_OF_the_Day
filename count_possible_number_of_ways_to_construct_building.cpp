#include<iostream>
using namespace std;

// just do more than two dry run for the n = 1, n = 2, n = 3, and find the number of building can be made on one side 
// of the road.
/*check for every n, the number of building can be made on one side of the road where building are not adjacent.

    n = 1 , building = 2 on one side.
    n = 2 , building = 3 on one side.
    n = 3 , building = 5 on one side. 

    observe the number of building in the (fibonaaci sequence.)
*/

// problem link -> https://www.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1

int main()
{
    
    return 0;
}

    int mod = 1e9+7;
	int TotalWays(int N)
	{
	    // find the nth fibonnaci and return the square of it.
	    long long a = 1;
	    long long b = 1;
	    
	    while(N)
	    {
	        long long temp = b % mod;
	        b = (a+b) % mod;
	        a = temp % mod;
	        N--;
	    }
	    
	    return ( (b % mod) * (b % mod) ) % mod;
	}