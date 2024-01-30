#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// problem link -> https://leetcode.com/problems/evaluate-reverse-polish-notation/?envType=daily-question&envId=2024-01-30

// reverse polish notation -> also known as Postfix expression.

    int doOperation(string op, int f, int s){
        if(op == "+")   return f + s;
        else if(op == "-")   return f - s;
        else if(op == "*")  return f * s;

        return f / s;
    }


    int evalRPN(vector<string>& tokens) {
        
        // reverse polish notation also known as Postfix expression.

        stack<int> st;

        for(auto it:tokens){
            if(it != "+" && it != "-" && it!= "*" && it!= "/"){
                st.push(stoi(it));
            }

            if(it == "+" || it == "-" || it == "*" || it == "/"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();

                st.push(doOperation(it, first, second));
            }
        }

        return st.top();
    }

int main()
{
    
    return 0;
}