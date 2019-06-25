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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode* p0 = head;
        ListNode* p1 = head -> next;
        ListNode* p2 = p1;
        while( p2 ){
            p0 -> next = p2 -> next;
            if(p2 -> next) p2 -> next = p2 -> next -> next;
            if(p0 -> next) p0 = p0 -> next;
            p2 = p2 -> next;
        }
        p0 -> next = p1;
        return head;
    }
};
