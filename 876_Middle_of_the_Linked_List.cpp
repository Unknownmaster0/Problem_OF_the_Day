#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=daily-question&envId=2024-03-07

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
/* Method 1 -> using the finding length of the linked list approach.
                if (length is even) then return the (middle + 1)th node.
                if(length is odd)   then return the (middle) node.

                middle = length / 2;


    Method 2 -> using the fast and slow pointer approach.
                slow will move one step, and fast will move two steps.
                thus, when fast reaches to NULL or last , then 
                'slow' must be poiting to the middle.
*/
        // Applying the method 2.
        // a/c to constraints -> it must have 1 node atleast.
        if(head->next == NULL)  return head;
        ListNode* slow = head, *fast = head->next;

        while(fast != NULL){
            slow = slow -> next;

            fast = fast -> next;
            if(fast != NULL)    fast = fast->next;
        }

        return slow;
    }
};


int main()
{

    return 0;
}