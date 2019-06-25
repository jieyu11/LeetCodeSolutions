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
    bool isOK(TreeNode* node, long int highest, long int lowest){
        if(!node) return true;
        long int test = node -> val;
        if(test >= highest) return false;
        if(test <= lowest ) return false;
        if(node -> left && !isOK(node -> left, min(test, highest), lowest)) return false;
        if(node -> right && !isOK(node -> right, highest, max(lowest, test))) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return isOK(root, LONG_MAX, LONG_MIN);
    }
};
