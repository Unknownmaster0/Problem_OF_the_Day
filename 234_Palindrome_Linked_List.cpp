#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/palindrome-linked-list/?envType=daily-question&envId=2024-03-22

struct ListNode
{

    int val;
    ListNode *next;

    ListNode(){
        val = 0, next = NULL;
    }

    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

class Solution
{
    ListNode *reverse(ListNode *head)
    {

        ListNode *prev = NULL, *curr = head, *forward = NULL;

        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return true;

        // getting the middle of the linked list and reversing them.
        ListNode *slow = head, *fast = head, *prev = NULL;
        while (fast && fast->next)
        {

            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        // now slow is at your middle of the list.
        prev->next = reverse(slow);
        // now the list has become like this==  1->2->1->2

        // now iterate from head and from prev->next, if they are same till end then they are palindrome.
        ListNode *revHead = prev->next;
        prev = prev->next;
        while (head != prev && revHead != NULL)
        {

            if (head->val != revHead->val)
                return false;
            head = head->next;
            revHead = revHead->next;
        }

        return true;
    }
};

int main()
{

    return 0;
}