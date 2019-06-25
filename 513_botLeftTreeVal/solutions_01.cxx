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
    int findBottomLeftValue(TreeNode* root) {
        // read the tree level by level
        vector<TreeNode*> qNode; qNode.push_back(root);
        int last_first =0;
        while(!qNode.empty()){
            vector<TreeNode*> qNodeCurr = qNode;
            qNode.clear();
            last_first = qNodeCurr[0] -> val;
            for(int i=0; i<qNodeCurr.size(); i++){
                if(qNodeCurr[i]->left) qNode.push_back(qNodeCurr[i]->left);
                if(qNodeCurr[i]->right) qNode.push_back(qNodeCurr[i]->right);
            }
        }
        return last_first;
    }
};
