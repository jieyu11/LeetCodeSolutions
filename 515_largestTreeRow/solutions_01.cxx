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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        // read the tree level by level
        vector<TreeNode*> qNode; qNode.push_back(root);
        while(!qNode.empty()){
            vector<TreeNode*> qNodeCurr = qNode;
            qNode.clear();
            int vmax = INT_MIN;
            for(int i=0; i<qNodeCurr.size(); i++){
                if(vmax < qNodeCurr[i]->val) vmax = qNodeCurr[i]->val;
                if(qNodeCurr[i]->left) qNode.push_back(qNodeCurr[i]->left);
                if(qNodeCurr[i]->right) qNode.push_back(qNodeCurr[i]->right);
            }
            result.push_back(vmax);
        }
        return result;
    }
};
