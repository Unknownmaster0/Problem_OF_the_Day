#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// problem link -> https://leetcode.com/problems/furthest-building-you-can-reach/

// Time complexity -> O(N * log N) [log N -> for insertion and deletion from priority queue.]
    int furthestBuilding(vector<int>& height, int briks, int ladrs) {
        int n = height.size();
/*  NOT CORRECT CODE BUT THE CORRECT APPROACH.
        // using binary search
        int farthestIdx = 0;
        int low = 0, high = n-1;
        
        while(low < high){
            int mid = (low + high)/2;
            cout<<"mid -> "<<mid<<endl;
// check if mid statify the property.
            priority_queue<int> maxi;
            for(int i=0; i<mid; i++){
                int height_diff = height[i+1]-height[i];
                cout<<"height_diff -> "<<height_diff<<endl;
                if(height_diff > 0) maxi.push(height_diff);
            }

// pop out the element from the maxi for the number of ladrs.
            int l = ladrs;
            while(l > 0){
                maxi.pop();
                l--;
            }
// now whatever elements reamining in the maxi, if its sum is less than or equal to the number of bricks, then can't able to reach to that building.
            int sum = 0;
            while(!maxi.empty()){
                int height = maxi.top();
                maxi.pop();
                sum += height;
            }

            // then possible, then make the [low = mid + 1  &&  high as it is.]
            cout<<"overall sum -> "<<sum<<endl;
            if(briks-sum >= 0){
                farthestIdx = mid;
                low = mid + 1;
            }  
            else{
                high = mid;
            }
            cout<<"farthest -> "<<farthestIdx<<endl;
        }

        return low; */

        int i=0;
        priority_queue<int,vector<int>, greater<int>> q; // min heap.
        for(;i<n-1; i++){
            int height_diff = height[i+1]-height[i];
            if(height_diff > 0) q.push(height_diff);
            if(q.size() > ladrs){
                int minimum_height = q.top();
                q.pop();

                if(briks-minimum_height >= 0){
                    briks -= minimum_height;
                }
                else    break;
            }
        }
        return i;
    }

int main()
{

    return 0;
}