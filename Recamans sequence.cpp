#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    vector<int> recamanSequence(int n){
        if(n == 1)  return {0};
        unordered_map<int,bool>freq;
        freq[0] = true;
        
        int prev = 0;
        
        vector<int> ans;
        ans.push_back(prev);
        
        for(int i=1; i<n; i++){
            int temp = prev - i;
            if(temp > 0 && freq.find(temp) == freq.end()){
                ans.push_back(temp);
            }
            else{
                temp = prev + i;
                ans.push_back(temp);
            }
            freq[temp] = true;
            prev = temp;
        }
        return ans;
    }
};

int main()
{

    return 0;
}

