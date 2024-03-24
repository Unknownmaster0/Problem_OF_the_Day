#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1

// Code->
// t.c = O(n)   ||  s.c = O(n)  [where 'n' is the number of elements in stack.]
class Solution{
public:
    stack<int> insertAtBottom(stack<int> st,int x){
        
        stack<int> output = st;
        stack<int> temp;
        
        while(!output.empty()){
            
            temp.push(output.top()), output.pop();
        }
        
        output.push(x);
        while(!temp.empty()){
           
            output.push(temp.top()), temp.pop();
        }
        
        return output;
    }
};


int main()
{
    
    return 0;
}