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
private:
    ListNode* reverseLL(ListNode* head){
        ListNode *prev = nullptr, *temp = head, *front;
        while(temp != nullptr){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* findKthNode(ListNode* head, int k){
        k -= 1; // we are at node 1 already
        ListNode *temp = head;
        while(k>0 && temp != NULL){
            k--;
            temp = temp->next;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head, *KthNode, *prevNode = nullptr, *nextNode;
        while(temp != nullptr){
            KthNode = findKthNode(temp, k);
            if(KthNode == nullptr){
                if(prevNode != nullptr) prevNode->next = temp;
                break;
            }
            nextNode = KthNode->next;
            KthNode->next = nullptr;

            reverseLL(temp);
            if(temp == head) head = KthNode;
            else prevNode->next = KthNode;

            prevNode = temp;
            temp = nextNode;            
        }
        return head;
    }
};