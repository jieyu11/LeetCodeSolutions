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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        
        stack<TreeNode*> nodes;
        set<TreeNode*> visited;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* c = nodes.top();
            if(visited.find(c) != visited.end() || (!c->left && !c->right)){
                nodes.pop();
                result.push_back( c -> val );
            }else if(c->right || c->left){
                if(c->right) nodes.push( c->right );
                if(c->left ) nodes.push( c->left );
                visited.insert( c );
            }
        }
        return result;        
    }
};
