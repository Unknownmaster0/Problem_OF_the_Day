#include <iostream>
#include <algorithm>
using namespace std;

// problem link -> https://leetcode.com/problems/maximum-odd-binary-number/?envType=daily-question&envId=2024-03-01

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // set the 0th bit, if not already done. -> Base condition for the odd number.
        // then place all the set bit to the start of string. -> to maximise the odd number.

        int n = s.length();

/*// Method 1-> Two pointer approach .
        string ans = s;
        int start = 0, end = n-1, i = n-2;
// t.c = O(n/2) === O(n)
// s.c = O(n) 
// n = length of the string.
        while(start <= i){
            if(ans[i] == '0')   i--;
            else{
                if(ans[end] == '0'){
                    swap(ans[i], ans[end]);
                    i--;
                }
                else {
                    // if s[start] == 0 then also start ++. and if(s[start] == 1) then also start++;
                    if(ans[start] == '0'){
                        swap(ans[i], ans[start]);
                        i--;
                    }
                    start ++;
                }
            } 
        }

        return ans;
*/


// Method 2 -> making a new string and building the binary number.

        string ans = "1";
        int countOnes = count(s.begin(), s.end(), '1');

        int zeros = n-countOnes;

        while(zeros--){
            ans += "0";
        }

        countOnes--;// as we have added one '1' into the string intially.

        while(countOnes--){
            ans += "1";
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{

    return 0;
}