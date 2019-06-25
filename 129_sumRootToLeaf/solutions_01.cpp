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
    void calc(TreeNode* root, int prehead, vector<int> & result){
        if(!root) return;
        int newhead = prehead * 10 + root->val;
        
        if(!root -> left && !root -> right){
            result.push_back(newhead);
            return;
        }
        if(root->left ) calc(root->left,  newhead, result);
        if(root->right) calc(root->right, newhead, result);
    }
    int sumNumbers(TreeNode* root) {
        /*
        // test
        root = new TreeNode(0);
        TreeNode * left = new TreeNode(1);
        root -> left = left;
        */
        
        if(!root) return 0;
        vector<int> result;
        calc(root, 0, result);
        int total = 0;
        for(auto num : result) total += num;
        return total;
    }
};
