#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// Problem link -> https://leetcode.com/problems/bag-of-tokens/description/?envType=daily-question&envId=2024-03-04


/*Normal approach of just traversing the array, but need some logical thinking to think on the both power and score if statement.

    If we use the power then we took the token having min value.
    but when we use the score then we took the token having max value among the tokens.

*/

// t.c = O(n * log n)  ||  s.c = O(1)
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0, max_score = INT_MIN;

        int n = tokens.size();
        if(n == 0)  return  0;
        if(n == 1)
            return (power >= tokens[0]) ? 1 : 0;

        sort(tokens.begin(), tokens.end());
        if(tokens[0] > power)   return 0;
        else{
            // takng the first token with the power help.
            score ++;
            power = power - tokens[0]; // decrementing the power 
            max_score = max(max_score, score);

            int start = 1, end = n-1;
            while(start <= end){
                // power use krenge then minimum token wala product lenge.
                if(power >= tokens[start]){
                    power -= tokens[start++];
                    score ++;
                }
// scroe use krenge then we can take any of the tokens in 1 score only, then we took the maximum score tokens.
                else if(score > 0){
                    score --;
                    power += tokens[end--];
                }
                else {
                    break;
                }
                max_score = max(max_score, score);
            }
        }

        return max_score;
    }

int main()
{

    return 0;
}