#include <iostream>
using namespace std;

// Problem link -> https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

int main()
{

    return 0;
}

    bool maxheap(int idx, int n, int *arr){
        int curr = idx;
        int leftChild = 2 * curr + 1;
        int rightChild = 2 * curr + 2;
        
        if(leftChild < n && arr[leftChild] > arr[curr]) return false;
        if(rightChild < n && arr[rightChild] > arr[curr])   return false;
        
        return true;
    }

    
    bool isMaxHeap(int arr[], int n)
    {
        // leaf node indexing start from -> N/2 to N-1;
        for(int i=n/2-1; i>=0; i--){
            if(maxheap(i, n, arr) == false) return false;
        }
        
        return true;
    }