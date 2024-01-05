#include<iostream>
using namespace std;

int main()
{
    
    return 0;
}

    int singleElement(int arr[] ,int n) {
        
        // Approach 1 -> using the sorting.
        /*
        sort(arr,arr+n);
        
        if(arr[0] != arr[1])    return arr[0];
        if(arr[n-1] != arr[n-2])    return arr[n-1];
        
        int ans = -1;
        for(int i = 1; i<n; i++){
            if(i < n && arr[i] != arr[i-1] && arr[i] != arr[i+1])
                ans = arr[i];
        }
        return ans;
        */

    //  Approach 2 -> using the bit magic. 
    /*count the number of set bit at the ith idx , take its modulo with the 3(as all elements is present thrice) and if the modulo is 1, then set the ith bit of the ans as 1.*/
        int ans = 0;
        int bit[32] = {0};
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=31; j++){
                if(arr[i] >>j & 1 == 1)
                    bit[j]++;
            }
        }
        
        for(int i = 0; i<32; i++){
            // check the ith bit of the bit[i] if it is not 0, then find modulo with 3 and set that bit of ans as 1.
            if(bit[i] != 0 && bit[i] % 3 != 0){
                ans = ans | (1 << i);
            }
        }
        
        return ans;
    }