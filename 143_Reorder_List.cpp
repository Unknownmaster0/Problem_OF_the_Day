#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/reorder-list/description/?envType=daily-question&envId=2024-03-23

// Code->
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*Approach -> Just find mid and reverse the list after the mid.
                And then merge the reveresed list with the original list, in reorder fashion, as the answer required.
*/

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
// t.c = O(number of nodes.)    ||  s.c = O(number of nodes.)
    void reorderList(ListNode *head)
    {
        if (head->next == NULL)
            return;

        ListNode *slow = head, *fast = head, *prevSlow;

        while (fast && fast->next)
        {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prevSlow->next = reverse(slow); // reversing the half part of the list.

        slow = head; // now point slow, to head again, because we want a pointer to head. INstead of declaring a new pointer use the slow.  As 'slow' is free now.

        // merging the list in reorder fashion.
        while (slow != prevSlow)
        {
            fast = prevSlow->next;  // similarly using fast here, as fast is free here.
            prevSlow->next = fast->next;
            fast->next = slow->next;
            slow->next = fast;
            slow = fast->next;
        }
    }
};

int main()
{

    return 0;
}