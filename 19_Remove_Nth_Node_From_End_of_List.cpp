#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int data){
        val = data;
        next = NULL;
    }
};

class solution{

/*
    ListNode* reverse(ListNode* head){
        if(head == NULL)    return NULL;
        ListNode* curr = head, *prev = NULL, * forward = NULL;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
*/

    int countLength(ListNode* head){
        int count = 0;
        while(head != NULL){
            count ++;
            head = head->next;
        }
        return count;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)    return head;
/*
// Reverse method is not good as list has to reverse more number of times.
        ListNode* nHead = reverse(head);
        ListNode* temp = nHead, *prev = NULL;
        int count = 1;
        if(count == n){
            return reverse(nHead->next);
        }
        while(count != n && temp != NULL){
            count ++;
            ListNode* forward = temp->next;
            prev = temp;
            temp = forward;
        }

        if(temp && prev){
            prev->next = temp->next;
            temp->next = NULL;
        }

        return reverse(nHead);
*/

        int node = countLength(head) - n;

        if(node == 0){
            return head->next;
        }
/*
        ListNode* temp = head, * prev = NULL, *forward = NULL;
        while(node && temp!=NULL){
            node--;
            forward = temp->next;
            prev = temp;
            temp = forward;
        }

        if(temp && prev){
            prev->next = temp->next;
            temp->next = NULL;
        }

        return head;
*/

        ListNode* temp = head;
        int cnt =0;
        while(cnt < node-1){
            if(temp != NULL)
                temp = temp -> next;
            cnt++;
        }
        temp->next = temp->next->next;
        return head;
    }
};

int main()
{
    
    return 0;
}