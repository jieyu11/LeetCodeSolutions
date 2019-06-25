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
    int find(TreeNode* root, int level){
        if(!root->left && !root->right) return level;
        
        if(level < 0) return level;
        
        int level_left = level;
        if( root->left){
            level_left = find(root->left, level+1);
        }
        
        int level_right = level;
        if(root->right){
            level_right = find(root->right, level+1);
        }
        
        if( abs(level_left - level_right) > 1 ) return -1;
        else if(level_left > level_right) return level_left;
        else                              return level_right;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int deepest = find(root, 1);
        if(deepest < 0) return false;
        else            return true;
    }
};
