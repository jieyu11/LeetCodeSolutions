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
        vector<ListNode*> veclist;
        // given: 1->2->3->4->5->NULL
        // at the end 
        // h1 = p5
        // h2 = p3
        while( h1->next ){
            veclist.push_back( h1 );
            h1 = h1 -> next;
        }
        // h1: now is the last item
        // veclist contains all the rest items
        // nlist is 1 less than the total size
        int nlist = veclist.size();
        
        // nlist=0 meaning list having only one element!!
        if(nlist==0) return head;
        
        // if the length of the list (nlist+1) is lower than k
        // redo it for the remaining of the length by: k = k%(nlist + 1)
        if(nlist < k && nlist != 0 ){
            k = k%(nlist + 1);
            return rotateRight(head, k);
        }
        
        // h2 is the last item after rotation
        // when k = 1, h2 is the last item in veclist: veclist[nlist - 1]
        // when k = 2, h2 = veclist[nlist - 2]
        // ...
        // do the rotation here with h2 = veclist[nlist - k];
        ListNode* tmp = veclist[nlist - k] -> next;
        h1 -> next = head;
        veclist[nlist - k] -> next = NULL;
        head = tmp;
        return head;
    }
};
