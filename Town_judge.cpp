#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/find-the-town-judge/description/?envType=daily-question&envId=2024-02-22

/*Approch -> It is nice graph analogy question. Thinking is based on graph but not have to make the actual graph.
            Just need to calculte the indegree and outdegree for each node.
*/

class Solution {
public:
// t.c = O(n + m)
// s.c = O(n + n) [for indegree and also for outdegree.]
// m = trust.size();
    int findJudge(int n, vector<vector<int>>& trust) {

//  METHOD 1 -> 
        // a trust b = a -> b [a has outgoing edge to b.]
        // find the outdegree of the each vertex, 
        // the vertex whose outdegree is 0 and the indegree is n-1(b/c all other trust him),
        // is the judge of the town
        // vector<int> outdegree(n, 0), indegree(n, 0);
        // for(auto it:trust){
        //     outdegree[it[0]-1] ++;
        //     indegree[it[1]-1] ++;
        // }

        // for(int i=0; i<n; i++){
        //     if(outdegree[i] == 0 && indegree[i] == n-1)   return i+1; // he is the judge.
        // }
        // return -1

//  METHOD 2 -> 
// as the max value of the (indegree can go upto n-1) and (outdegree can go upto n-1)
// as the min value of the (indegree can go upto 0)  and (outdegee can go upto 0)
        vector<int>degree(n+1, 0);
        for(auto it:trust){
            degree[it[0]]--;
            degree[it[1]]++;
        }

        for(int i=1; i<=n; i++){
            if(degree[i] == n-1)   return i; // he is the judge.
        }

        return -1;

        return -1;
    }
};

int main()
{

    return 0;
}