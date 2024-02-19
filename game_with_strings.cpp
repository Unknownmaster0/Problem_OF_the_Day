#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/game-with-string4100/1

/* minimizing the count of the maximum freq character everytime.
    First store the count of every character in the map [char, int]

    then push all the mapping into the maxHeap.

    now take out the top maximum count element and reduce its count by 1, everytime. Such, that count of maximum element will be reduced every time.
*/

    int minValue(string s, int k){
        
        priority_queue< int > maxHeap;
        unordered_map<char,int> mp;
        
        for(auto it:s){
            mp[it]++;
        }
        
        for(auto it:mp){
            maxHeap.push(it.second);
        }
        
        while(k > 0){
            auto val = maxHeap.top();
            maxHeap.pop();
            
            val--;
            maxHeap.push(val);
            k--;
        }
        
        long long sumSquares = 0;
        while(!maxHeap.empty()){
            auto it = maxHeap.top();
            maxHeap.pop();
            
            sumSquares += (it * it);
        }
        return sumSquares;
    }

int main()
{

    return 0;
}