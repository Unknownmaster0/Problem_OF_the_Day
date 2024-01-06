#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int main()
{
    
    return 0;
}

	int sumOfPowers(int a, int b){
        
        vector<int>isPrime(b+1, 1);
        
        isPrime[0] = isPrime[1] = 0;
        
        for(int i = 2; i<=b; i++)
        {
            if(isPrime[i]){
                // if the current number is prime then mark all the multiple of this number as not prime.
                for(int j = 2*i; j<=b; j+=i)
                {
                    isPrime[j] = 0;
                }
            }
        }
        	    
	    long long sumPower = 0;
	    for(int i = a; i<=b; i++)
	    {
	        long long count = 0;
	        int num = i;
	        for(int j = 2; j*j<=i; j++)
	        {
	            if(isPrime[j] == 0) continue;
	            while(num % j == 0){
	                count++;
	                num /= j;
	            }
	            
	            if(num == 1)
	                break;
	        }
            // do dry run for a = 9 and b = 12 then let to understand this line.
/*when the a increment to 10, and we check the prime factorization for this then, sqrt(10) = 3, but the prime 
factor of the 10 = 2 * 5 , so, after coming from the above loop, then we have still 5 in the num, which is prime
thus we increase the count.
*/
// if the num is still greater than 1 means that it is still prime , then increment the count by one also.
	        if(num > 1) count++;
	        sumPower += count;
	    }
	    return sumPower;
	}