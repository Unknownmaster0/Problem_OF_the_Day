#include<iostream>
#include<vector>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/implement-atoi/1

    int atoi(string s) {
        int len = s.length();
        int num = 0, place = 1;
        bool neg = false;
        for(int i = len-1; i>=0; i--){
            
            if(isdigit(s[i]) || (i == 0 && s[i] =='-')){
                if(s[i] == '-') neg = true;
                else
                    num = num + ((s[i]-'0') * place);
            }
            else    return -1;
            
            place *= 10;
        }
        
        if(neg) return -1*num; 
        return num;
    }

int main()
{
    
    return 0;
}