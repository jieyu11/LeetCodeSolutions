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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head) return NULL;
        if( k==0) return head;

        ListNode* h1 = head;
        ListNode* h2 = head;
        int ip = 0;
        // given: 1->2->3->4->5->NULL
        // at the end 
        // h1 = p5
        // h2 = p3
        while( h1->next ){
            h1 = h1 -> next;
            if(ip>=k){
                h2 = h2 -> next;
            }
            ip++;
        }
        
        // ip=0 meaning list having only one element!!
        if(ip==0) return head;
        
        // if the length of the list (ip+1) is lower than k
        // redo it for the remaining of the length by: k = k%(ip + 1)
        if(ip < k && ip != 0 ){
            k = k%(ip + 1);
            return rotateRight(head, k);
        }
        
        // do the rotation here:
        ListNode* tmp = h2 -> next;
        h1 -> next = head;
        h2 -> next = NULL;
        head = tmp;
        return head;
    }
};
