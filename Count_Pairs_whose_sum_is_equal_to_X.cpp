#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// problem link ->

// code ->
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution{
  public:
    // your task is to complete this function
    
    // t.c = O(n1 + n2) || s.c = O(n1)  [where n1-> length of list 1, n2 = length of list 2]
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        unordered_map<int,int> freq;
        Node* temp = head1;
        // t.c = O(length of 1st list)
        while(temp != NULL){
            int val = temp->data;
            freq[x-val]++;
            temp = temp->next;
        }
        
        Node* head = head2;
        int cnt = 0;
        // t.c = O(length of 2nd list)
        while(head != NULL){
            int val = head->data;
            if(freq.find(val) != freq.end())    cnt++;
            head = head->next;
        }
        
        return cnt;
    }
};

int main()
{

    return 0;
}