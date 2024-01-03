#include<iostream>
#include<vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/?envType=daily-question&envId=2024-01-03

int main()
{
    
    return 0;
}

    int numberOfBeams(vector<string>& bank) {
        int nbeams = 0;
        int prev = 0;
        // traverse the first row.

        for(int i = 0; i<bank[0].size(); i++)
        {
            if(bank[0][i] == '1') prev ++;
        }
        for(int i = 1; i<bank.size(); i++)
        {
            int curr = 0;
            for(int j = 0; j<bank[i].size(); j++)
            {
                if(bank[i][j] == '1') curr ++;
            }

            if(curr != 0){
                nbeams += (curr * prev);
                prev = curr;
            }
        }
        return nbeams;
    }