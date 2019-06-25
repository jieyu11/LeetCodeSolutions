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
    void get(TreeNode* node, vector<int> & result){
        if(!node) return;
        if(node->left) get(node->left, result);
        result.push_back(node->val);
        if(node->right) get(node->right, result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // inorder: left root right
        vector<int> result;
        get(root, result);
        return result;
    }
};
