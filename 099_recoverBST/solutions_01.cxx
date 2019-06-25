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
    void check(TreeNode* node, vector<TreeNode*> & lastnode, vector<TreeNode*> & swappednodes){
        // for a correct BST, numbers in orders should always been increasing 1, 2, 3, 4, 5, 6, 7
        // if two of them are swapped, then it looks like: 1, 2, 3, 7, 5, 6, 4 OR 1, 2, 3, 5, 4, 6, 7
        // looking for the two numbers which decreases.
        if(!node) return;
        if(node -> left) check(node->left, lastnode, swappednodes);
        
        if(lastnode.empty()) lastnode.push_back( node );
        else{ 
            // always expect the node value to be higher than last node value
            // if not, then 
            //    - if swappednodes is empty, then the last node is one of the swapped
            //    - if swappednodes is not empty, then the current node is one of the swapped
            if( node-> val < lastnode[0]->val ){
                if(swappednodes.empty()){
                    // keep both of them, because the swapped may just be these two, see above, 4 <--> 5
                    swappednodes.push_back(lastnode.back()); 
                    swappednodes.push_back(node);
                }else{ 
                    // if another place there is a decreasing value, it is the other number get swapped!
                    swappednodes.push_back(node);
                    return; /* this should be the end */
                }
            }
            lastnode[0] = node;
        }
        
        if(node -> right) check(node->right, lastnode, swappednodes);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> lastnode;
        vector<TreeNode*> swappednodes;
        check(root, lastnode, swappednodes);
        if(swappednodes.size() < 2) return;
        swap(swappednodes[0]->val, swappednodes.back()->val);
    }
};
