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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return;

        //finding the middle node
        ListNode *midNode, *slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        midNode = slow;

        //detaching the LL
        ListNode *secondHead = midNode->next;
        midNode->next = nullptr;

        //reversing the second LL
        ListNode *curr = secondHead, *prev = nullptr, *front;
        while(curr != nullptr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        secondHead = prev;

        //inserting the second LL in first LL according to the problem
        ListNode *t1 = head, *t2 = secondHead, *m1, *m2;
        while(t2 != nullptr){
            m1 = t1->next;
            m2 = t2->next;
            t1->next = t2;
            t2->next = m1;
            t1 = m1;
            t2 = m2;
        }
    }
};