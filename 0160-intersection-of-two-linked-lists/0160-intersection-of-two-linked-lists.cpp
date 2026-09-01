/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto t1 = headA, t2 = headB;
        unordered_set<ListNode*> visited;
        while (t1 != NULL){
            visited.insert(t1);
            t1 = t1->next;
        }
        while (t2 != NULL){
            if(visited.count(t2)){
                return t2;
            }
            t2 = t2->next;
        }
        return nullptr;
    }
};