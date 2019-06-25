/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* build(ListNode* head, ListNode* end){
        if(head == end) return NULL;
        ListNode* p0 = head;
        ListNode* p1 = head;
        ListNode* p2 = head;
        int items = 0;
        while(p1 != end){
            p1 = p1 -> next;
            items++;
            if(items>0&&items%2==0) p2 = p2 -> next;
        }
        // if there are 4 items in the link, 
        // should take the 3rd one as head
        
        TreeNode * midnode = new TreeNode( p2 -> val);
        if(p2==head) return midnode;
        
        TreeNode * leftnode = build(p0, p2);
        TreeNode * rightnode = build(p2->next, end);
        midnode -> left = leftnode;
        midnode -> right = rightnode;
        return midnode;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        // test
        /*
        head = new ListNode(1);
        ListNode * pp1 = new ListNode(2);
        ListNode * pp2 = new ListNode(3);
        ListNode * pp3 = new ListNode(4);
        head -> next = pp1;
        pp1 -> next = pp2;
        pp2 -> next = pp3;
        */
        
        if(!head) return NULL;
        return build(head, NULL);
    }
};
