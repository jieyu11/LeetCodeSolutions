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
    void flatten(TreeNode* root) {
        if(!root) return;
        
        // store nodes, so that they can be treated later
        // e.g. 
        //   1
        //  / \
        // 2   3
        // first put 1 into nodes, then put 3 (right) into nodes, then 2 (left)...
        // first read 1 (root), then read 2 (left), ... 
        // always read left before right.
        stack<TreeNode*> nodes;
        nodes.push(root);
        
        // p0 used to track where is the current pointer.
        TreeNode* p0 = root;
        while(!nodes.empty()){
            TreeNode* p = nodes.top();
            nodes.pop();
            if(p!=root){
                p0 -> right = p;
                p0 = p0 -> right;
            }
            // push right first, read right later.
            if(p->right){
                nodes.push( p -> right);   
            }
            // push left later, read left first.
            if(p->left){
                nodes.push( p -> left);                
            }
            // reset left to NULL if necessary.
            if(p->left) p -> left = NULL;
        }
    }
};
