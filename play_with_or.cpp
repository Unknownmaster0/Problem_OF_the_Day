#include <iostream>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/play-with-or5515/1

int* game_with_number(int arr[], int n)
{
    
    for(int i=0; i<n; i++){
        if(i+1 < n){
            arr[i] = arr[i] | arr[i+1];
        }
    }
    return arr;
}

int main()
{

    return 0;
}