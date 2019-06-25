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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multimap<int, int> idxMap; // value, index in the vector
        int idx = 0;
        for(ListNode* h0 : lists){
            if(h0){idxMap.insert({h0->val, idx});}
            idx++;
        }
        if(idxMap.empty()) return NULL;
        ListNode* head = NULL;
        ListNode* curr = NULL;        
        while(!idxMap.empty()){
            idx = idxMap.begin() -> second;
            if(!head){
                head = lists[ idx ];
                curr = head;
            }else{
                curr -> next = lists[ idx ];
                curr = curr -> next;
            }
            idxMap.erase( idxMap.begin() );
            lists[ idx ] = lists[ idx ] -> next;
            if(lists[ idx ]){
                idxMap.insert( {lists[ idx ] -> val, idx});
            }
        }
        return head;
    }
};
