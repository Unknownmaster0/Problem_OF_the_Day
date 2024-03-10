#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/find-the-n-th-character5925/1

// t.c = O(r * s.length)
char nthCharacter(string s, int r, int n)
{

    int len = s.length();
    string str = s;
    // t.c = O(r)
    while (r)
    {
        string temp = "";
        // t.c = O(length of original string)
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '0')
            {
                temp += "01";
            }
            else if (str[i] == '1')
            {
                temp += "10";
            }
            // we have to build the string, till the size of the input string, after that there is not need to build new string.
            // as the value of n in constraints is always less than original string length.
            // 0 ≤ n < |s|
            else if (temp.size() > str.size())
                break;
        }

        str = temp;
        r--;
    }

    return str[n];
}

int main()
{

    return 0;
}