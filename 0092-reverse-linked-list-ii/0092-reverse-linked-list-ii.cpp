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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || head->next == nullptr || left==right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *back = &dummy, *curr=head;

        //reaching the left node
        for(int i = 0; i < left - 1; i++){ 
            back = back->next;
            curr = curr->next;
        }
        
        // reversing the nodes from left to right
        ListNode *prev = nullptr, *front;
        for(int i = 0; i < right-left+1; i++){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        // re-establishing links between nodes
        back->next->next = curr;
        back->next = prev;

        return dummy.next;
    }
};
