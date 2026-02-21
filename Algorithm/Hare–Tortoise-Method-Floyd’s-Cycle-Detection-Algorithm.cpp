//Hare–Tortoise Method (Floyd’s Cycle Detection Algorithm)
//Time Complexity: O(n)
//Space Complexity: O(1)
//The Hare–Tortoise Method, also known as Floyd’s Cycle Detection Algorithm, is a technique used to determine if a linked list contains a cycle. The algorithm uses two pointers, one slow pointer (the tortoise) that moves one step at a time, and one fast pointer (the hare) that moves two steps at a time. If there is a cycle in the linked list, the fast pointer will eventually meet the slow pointer. If there is no cycle, the fast pointer will reach the end of the list. The algorithm can be implemented as follows:    

//syntax: ListNode is a structure representing a node in a linked list, with a value and a pointer to the next node.
//Example usage:
// ListNode* head = new ListNode(1);
// head->next = new ListNode(2);
// head->next->next = new ListNode(3);
// head->next->next->next = head; // Creates a cycle
// bool hasCycle = hasCycle(head); // Returns true
// ListNode* head2 = new ListNode(1);
// head2->next = new ListNode(2);
// head2->next->next = new ListNode(3); // No cycle
// bool hasCycle2 = hasCycle(head2); // Returns false
//The algorithm is efficient and works in O(n) time complexity, where n is the number of nodes in the linked list, and it uses O(1) extra space since it only requires two pointers for traversal.

//code implementation:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;           // Move slow pointer by 1 step
            fast = fast->next->next;    // Move fast pointer by 2 steps

            if (slow == fast) {         // A cycle is detected
                return true;
            }
        }

        return false; // No cycle found
    }
};  
