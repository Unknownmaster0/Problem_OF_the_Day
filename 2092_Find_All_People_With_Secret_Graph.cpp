#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Problem link -> https://leetcode.com/problems/find-all-people-with-secret/description/?envType=daily-question&envId=2024-02-24

// Nice question based on the disjoint set data structure.

class DisjointSet{
public:
    vector<int> parent, size;
    // constructor.
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // method to find ultimate parent of node.
    // Time complexity -> O(4* alpha)
    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    // Time complexity -> O(4* alpha)
    void unionBySize(int u, int v)
    {
        int ultiParent_u = findParent(u);
        int ultiParent_v = findParent(v);

        if (ultiParent_u == ultiParent_v)
            return;

        if (size[ultiParent_u] > size[ultiParent_v])
        {
            parent[ultiParent_v] = ultiParent_u;
            size[ultiParent_u] += size[ultiParent_v];
        }
        else
        {
            parent[ultiParent_u] = ultiParent_v;
            size[ultiParent_v] += size[ultiParent_u];
        }
    }

// to make undo the connected node, with some component.
    void reset(int node){
        parent[node] = node;
    }
};


class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        DisjointSet d(n);

// as we need to sort the given meeting array in terms of time, so I use the min Heap priority queue.
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({0, {0,firstPerson}});
        for(auto it:meetings){
            int x = it[0], y = it[1], timei = it[2];
            pq.push({timei, {x,y}});
        }

        while(!pq.empty()){
            vector<int> cntPeople;  // to store the people having meeting on same time.
            int initialTime = pq.top().first;
            // making connection for all the nodes having the same current time
            while(!pq.empty() && pq.top().first == initialTime){
                auto node = pq.top();
                pq.pop();
                d.unionBySize(node.second.first, node.second.second);   // first connecting all the people having meeting at same time or connecting nodes blindly
                cntPeople.push_back(node.second.first); // stroing the people that are connecting above
                cntPeople.push_back(node.second.second);
            }

// if the node have same curr time was not connected to the 0th node parent, then it will not knowing the 
// secret, remove them from the connected component or disconnect them from the component.
            for(auto it:cntPeople){
                if(d.findParent(it) != d.findParent(0))
                    d.reset(it);
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(d.findParent(i) == d.findParent(0)){
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{
    
    return 0;
}