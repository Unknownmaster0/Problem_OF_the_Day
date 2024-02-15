#include<iostream>
#include<vector>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/castle-run3644/1

int main()
{
    
    return 0;
}

int isPossible(vector<vector<int>>paths){
    /* Approach -> Each vertex must have even degree, so that it can go out with one vertex and come again
                    with different vertex.*/
                    
    int n = paths.size();
    for(int i=0; i<n; i++){
        int degree = 0;
        for(int j = 0; j<n; j++){
            if(paths[i][j] == 1) degree++;
        }
        if(degree % 2 != 0)  return 0;
    }
    return 1;
}