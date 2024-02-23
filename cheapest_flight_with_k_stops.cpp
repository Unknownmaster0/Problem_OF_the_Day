#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

// Problem link -> https://leetcode.com/problems/cheapest-flights-within-k-stops/description/?envType=daily-question&envId=2024-02-23

class Solution {
public:
// t.c = O(n * flights.size()) s.c = O(n) + O(flights.size()) [for queue] + O(n) [for totalPrice]
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        // normal queue se baat ban jayega, as stops are alredy coming in arranged order.
        // stop1, stop2, stop3 ...... stopk
        // queue<pair<int,pair<int,int> > > q;
        queue<pair<int,int>> q;
        q.push({src,0}); // src, price.

        vector<int> totalPrice(n, 1e9);
        totalPrice[src] = 0;

        int stops = 0;
        while(!q.empty() && stops <= k){
            int size = q.size();
            while(size){
                auto top = q.front();
                q.pop();
                size--;
                int city = top.first;
                int price = top.second;

                for(auto itr:adj[city]){
                    int adjcity = itr.first;
                    int adjprice = itr.second;
                    if(price + adjprice < totalPrice[adjcity]){
                        totalPrice[adjcity] = adjprice + price;
                        q.push({adjcity, price+adjprice});
                    }
                }
            }
            stops ++;
        }

        return totalPrice[dst] != 1e9 ? totalPrice[dst] : -1;
    }
};

int main()
{

    return 0;
}