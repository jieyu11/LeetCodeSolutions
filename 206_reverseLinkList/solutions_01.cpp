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
    ListNode* reverseList(ListNode* head) {
        if(!head ||!head->next) return head;
        ListNode* p0 = NULL;
        ListNode* p1 = head;
        while(p1->next){
            ListNode* tmp = p1->next;
            p1->next = p0;
            p0 = p1;
            p1 = tmp;
        }
        p1->next = p0;
        return p1;
    }
};
