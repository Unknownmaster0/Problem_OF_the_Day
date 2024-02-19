#include <iostream>
using namespace std;

// Problem link -> https://leetcode.com/problems/power-of-two/?envType=daily-question&envId=2024-02-19

// Solution using various method.
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        /*  THIS PEACE OF CODE CAN ALSO BE WRITTEN IN THREE LINES.
                if(n == 1)  return true;
                if(n == 0 || n % 2 != 0 || n < 0)  return false;
                while(n > 1){
                    n /= 2;
                    if(n != 1 && n % 2 != 0){
                        return false;
                    }
                }
                return true;
        */

        if (n == 0 || n < 0)
            return false; // this line will always in every method.
                          /*      *********** Method 1 *************
                          t.c = O(log N)  s.c = O(1)
                                  while(n % 2 ==0 ){
                                      n >>= 1;
                                  }
                                  // after coming out of the loop,
                                  // if (n == 1) means all other are divisible by 2, means it is power of 2.
                                  return (n == 1); // if n != 1 means it is not power of 2.
                          */
                          /* ************METHOD 2 **********************
                          The power of 2 numbers always has only one set bit in them.
                  
                          // T.C = O(log N), S.C = O(1)
                                  int setBit = __builtin_popcount(n); // counting the setbit in the 'n'.
                                  return setBit == 1;
                          */

        /*  ***************** METHOD 3 *****************
        The power of 2 number and the number just before it, has the bit-and as 0.
            Example ->  8 == 1000
                        7 == 0111
                    and ______________
                             0000
        */
        return ((n & (n - 1)) == 0); // t.c = O(1)   s.c = O(1)
    }
};

int main()
{

    return 0;
}