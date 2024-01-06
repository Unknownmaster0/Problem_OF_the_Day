#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int main()
{
    
    return 0;
}

// Time complexity -> O(b * log(log b)) [sieve of eras] + O(sqrt(b) - (sqrt(b) - sqrt(a-1))) [for finding prime factorization]
	int sumOfPowers(int a, int b){
        
        // space complexity -> O(b)
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
	        if(num > 1) count++;
	        sumPower += count;
	    }
	    return sumPower;
	}