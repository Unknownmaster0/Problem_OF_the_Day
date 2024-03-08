#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/check-frequencies4211/1

bool freqCheck(vector<int> freq)
{
    int val = -1;
    for (auto it : freq)
    {
        // as not present character also have value as '0'
        if (it > 0)
        {

            if (val == -1)
                val = it;
            else if (val != it)
                return false;
        }
    }
    return true;
}

/* Concept -> Just do what the question says to do.
                step1 -> store the frequency of each of characters.
step2 -> Now, check if the frequency of each distinct character is same or not, if same then return true.
                step 3-> else if not same, then decrement the frequency of each character one by one and
                        check if now the frequency become equal or not.
*/
bool sameFreq(string s)
{
    vector<int> freq(26, 0);
    for (auto ch : s)
    {
        freq[ch - 'a']++;
    }

    if (freqCheck(freq))
        return true;

    // check by decreasing the freq of characters.
    for (int i = 0; i < 26; i++)
    {

        if (freq[i] > 0)
        {
            freq[i]--;

            if (freqCheck(freq))
                return true;

            // but after decreasing the frequency make sure to undo the change, that means again increase the frequency.
            freq[i]++;
        }
    }

    return false;
}

int main()
{

    return 0;
}