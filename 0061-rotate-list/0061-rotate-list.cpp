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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *temp = head;
        int n = 0;
        while(temp != nullptr){
            n++;
            temp = temp->next;
        }
        if(k % n == 0) return head;
        k = k % n;
        k = n - k;
        temp = head;
        for(int i = 0; i < k-1; i++){
            temp = temp->next;
        }
        ListNode *newHead = temp->next, *newTemp = newHead;
        temp->next = nullptr;
        while(newTemp->next != nullptr){
            newTemp = newTemp->next;
        }
        newTemp->next = head;
        return newHead;
    }
};