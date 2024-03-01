#include<iostream>
#include<vector>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/peak-element/1


// Naive approach usng -> linear search 
// t.c = O(N)
    int peakElement(int arr[], int n)
    {
       for(int i=0; i<n; i++){
           if((i == 0 || arr[i-1] <= arr[i]) && (i == n-1 || arr[i+1] <= arr[i]))
            return i;
       }
       return -1;
    }


// Method -> using Binary search
// t.c = O(log N) [N is the size of the array]
    int peakElement(int arr[], int n)
    {
       int start = 0, end = n-1;
       while(start < end){
           int mid = start + (end - start) /2 ;
           
           // check if the curr element is the peak element.
           if((mid == 0 || arr[mid] >= arr[mid-1]) && (mid == n-1 || arr[mid] >= arr[mid+1])){
               return mid;
           }
           // check if peak is present in the right side
            else if(arr[mid] > arr[mid-1]){
                start = mid + 1;
            }
            // if the peak is present in the left side.
            else{
                end = mid - 1;
            }
       }
       
       return -1;
    }

int main()
{
    
    return 0;
}