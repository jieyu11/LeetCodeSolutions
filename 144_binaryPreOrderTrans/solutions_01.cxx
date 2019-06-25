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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        
        stack<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* c = nodes.top();
            nodes.pop();
            result.push_back( c -> val );
            if(c->right) nodes.push( c->right );
            if(c->left) nodes.push( c->left );
        }
        return result;
    }
};
