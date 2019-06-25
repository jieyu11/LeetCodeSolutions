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
    void update(TreeNode* root, vector<int> & result, int level){
        if(!root) return;
        if(level==result.size()) result.push_back( root -> val );
        if(root->right) update( root->right, result, level+1);
        if(root->left) update( root->left, result, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        update(root, result, 0);
        return result;
    }
};
