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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL; 
        ListNode *fast = head->next->next, *slow = head, *middleNode; // skipping one step for slow pointer. Normally, the slow will point to the middle node but we need the node before it so we skip one iteration for slow pointer.
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        middleNode = slow->next;
        slow->next = slow->next->next;
        delete middleNode;
        return head;
    }
};