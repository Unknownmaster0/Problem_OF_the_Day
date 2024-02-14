#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/critical-connections/1

// finding the bridges in the graph is the question.

int main()
{

    return 0;
}

int timer = 1;
// dfs function -> Which will traverse the graph in DFS manner and checking for each node if it can visited back
//  to parent node or befor parent node. If adjNode can visit back to the parent or before parent.
// then it is not our bridge(critical point).
void dfs(int node, int parent, vector<int> &vis, vector<int> &tinsert, vector<int> &lowtime, vector<int> adj[], vector<vector<int>> &bridges)
{
    vis[node] = 1;
    tinsert[node] = lowtime[node] = timer++;

    for (auto adjNode : adj[node])
    {
        if (!vis[adjNode])
        {
            dfs(adjNode, node, vis, tinsert, lowtime, adj, bridges);

            lowtime[node] = min(lowtime[node], lowtime[adjNode]);

            if (tinsert[node] < lowtime[adjNode])
            {
                if (node < adjNode)
                    bridges.push_back({node, adjNode});
                else
                    bridges.push_back({adjNode, node});
            }
        }
        else if (adjNode != parent)
        {
            lowtime[node] = min(lowtime[node], lowtime[adjNode]);
        }
    }
}

// Time complexity -> O(V + E) [dFS]  +  O(E * log E) [worst case each edge can be bridges. then bridges vector contains all the edges
// then time to sort the bridges vector.]
vector<vector<int>> criticalConnections(int v, vector<int> adj[])
{

    // time of insertion
    vector<int> tinsert(v, 0); // at what time it is called by the dfs function.

    vector<int> lowestTime(v, 0); // minimum time back goes to which node.

    vector<int> vis(v, 0);
    vector<vector<int>> bridges;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, tinsert, lowestTime, adj, bridges);
        }
    }

    sort(bridges.begin(), bridges.end());

    return bridges;
}