#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // Floyd's Cycle detection Algorithm -> t.c = O(N) || s.c = O(1) where N -> number of nodes in the list.
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;
        if (head->next == NULL)
            return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        // having only one node.
        if (slow == fast)
            return true;

        while (slow != NULL && fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;

            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}