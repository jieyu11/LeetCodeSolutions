/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// small improvement using max_element below!
class Solution {
public:
    // return {largest completed nodes path (might not include this node), largest including this node}
    // example, nodes
    // ... ...
    //     1
    //    / \
    //   -1 1
    //     / \
    //    3   4
    // then at value 2 position, the max node path is 1+3+4=8, max value til this node is  4+1+1=6.
    //   it is smaller than the completed node, but it can be connected to the rest of the nodes still.
    //   so, return the pair is (8, 6); .first >= .second
    //
    pair<int, int> calc(TreeNode* X){
        if(!X->left && !X->right) return {X->val, X->val}; // it is an end node
        if( X->left && !X->right){
            pair<int, int> vl = calc( X->left );
            vl.second = max(vl.second+X->val, X->val);
            if(vl.first < vl.second) vl.first = vl.second;
            return vl;
        }
        if(!X->left &&  X->right){
            pair<int, int> vr = calc( X->right );
            vr.second = max(vr.second+X->val, X->val);
            if(vr.first < vr.second) vr.first = vr.second;
            return vr;
        }
        if( X->left &&  X->right){
            pair<int, int> vl = calc( X->left );
            pair<int, int> vr = calc( X->right );
            // max of this node, can be either one of the nodes in left or right
            // or left pass through this node to right
            vector<int> maxnode_candidates{
                vl.second + X->val, vr.second + X->val, vl.second + X->val + vr.second, vl.first, vr.first, X->val};
            int maxnode = *max_element(maxnode_candidates.begin(), maxnode_candidates.end());
            int maxnext = max( max(vl.second, vr.second)+X->val, X->val);
            return pair<int, int>{ maxnode,  maxnext};
        }
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return root -> val;
        pair<int, int> res = calc(root); // largest node on the left or right when both exits
        return res.first;
    }
};
