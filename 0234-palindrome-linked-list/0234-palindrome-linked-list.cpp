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
private: // recursive way to reverse a LL
    ListNode* reverseLinkedList(ListNode* head){
        if (head == NULL || head->next == NULL) return head;
        ListNode *newHead = reverseLinkedList(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head;
        if(slow==NULL || slow->next==NULL) return true;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *newNode=reverseLinkedList(slow->next);
        ListNode *first = head, *second = newNode;
        while(second != NULL){
            if(first->val != second->val){
                reverseLinkedList(newNode);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLinkedList(newNode);
        return true;
    }
};