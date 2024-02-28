#include<iostream>
using namespace std;

    int DivisibleByEight(string s){
        //code here
        // to get the last three digit of the number -> divisibility of 8 -> if the last three digit is 000 or divisible by 8.
        // example -> 87816 = 816 is divisible by 8.
        // example -> 87000 = 000 is divisible by 8.
        int n = s.size();
        int i = n-1;
        int last = 0, slast = 0, tlast = 0, num = 0;
        if(n >= 1){
            last = s[i] - '0';
            i--;
            num += last;
        }
        if(n >= 2){
            slast= (s[i] - '0') * 10;
            i--;
            num += slast;
        }
        if(n >= 3){
            tlast = (s[i] - '0') * 100;
            i--;
            num += tlast;
        }     
        
        if(num % 8 == 0)    return 1;
        
        return -1;
    }

int main()
{
    
    return 0;
}