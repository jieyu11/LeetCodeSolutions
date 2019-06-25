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
    void find(vector<vector<int>> & result, vector<int> items, TreeNode* root, int sum){
        if(!root) return;
        if(root -> val == sum && !root -> left && !root -> right){
            items.push_back(sum);
            result.push_back( items );
            return;
        }
        items.push_back( root -> val );
        int sum_next = sum - root -> val;
        if(root -> left){
            find( result, items, root -> left, sum_next);
        }
        if(root -> right){
            find( result, items, root -> right, sum_next);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        find(result, vector<int>{}, root, sum);
        
        return result;
    }
};
