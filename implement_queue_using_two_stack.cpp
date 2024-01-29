#include<iostream>
#include<stack>
using namespace std;

// Brutforce -> Because in every peek and pop operation we are again and again  (removing every element from the st1 and pushing into st2) and ,  (putting every element of st2 again into st1).
class MyQueue {
    
    stack<int>st1;
    stack<int>st2;
        
public:
    MyQueue() {

    }
    
    void push(int x) {
        
        st1.push(x);

    }
    
    int pop() {
        
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }

        int top = st2.top();
        st2.pop();

        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }

        return top;
    }
    
    int peek() {
        
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }

        int top = st2.top();

        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }

        return top;

    }
    
    bool empty() {
        
        if(st1.size() == 0) return 1;
        return 0;
    }
};

// OTIMAL APPROACH -> here we are not always popping out the one stack into other and then do backtrace.
/* Time complexity -> 

    push(x) -> O(1)
    pop() / peek() =  O(2 * N)
*/
class MyQueue {
    stack<int> in;
    stack<int> out;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        
        int top = peek();
        out.pop();

        return top;
    }
    
    int peek() {
        
        if(out.empty())
        {
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }

        int top = out.top();
        return top;
    }
    
    bool empty() {
        
        if(in.empty() && out.empty())   return 1;
        return 0;
    }
};


int main()
{
    
    return 0;
}