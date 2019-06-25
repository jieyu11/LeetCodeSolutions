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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(root -> val == sum && !root -> left && !root -> right) return true;
        bool left = false;
        if(root -> left){
            left = hasPathSum( root -> left, sum - root -> val);
        }
        bool right = false;
        if(root -> right){
            right = hasPathSum( root -> right, sum - root -> val);
        }
        return left || right;
    }
};
