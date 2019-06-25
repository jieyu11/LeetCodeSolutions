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
    map<int, int> sums(TreeNode* node, map<int, int> & sumCountInc){
        map<int, int> sumCountLeft, sumCountRight;
        if(node->left) sumCountLeft = sums(node->left, sumCountInc);
        if(node->right) sumCountRight = sums(node->right, sumCountInc);
        // calculate the sum counts passing this node
        map<int, int> sumCount;
        if(sumCountLeft.empty() && sumCountRight.empty()){
            sumCount[ node->val ] = 1;
        }else if(!sumCountLeft.empty() && sumCountRight.empty()){
            for(auto & itmL : sumCountLeft){
                int val = node->val + itmL.first;
                sumCount[ val ] += itmL.second;
            }
        }else if(sumCountLeft.empty() && !sumCountRight.empty()){
            for(auto & itmR : sumCountRight){
                int val = node->val + itmR.first;
                sumCount[ val ] += itmR.second;
            }
        }else{
            for(auto & itmR : sumCountRight) for(auto & itmL : sumCountLeft){
                int val = itmR.first + node->val + itmL.first;
                sumCount[ val ] += itmR.second * itmL.second;
            }
        }
        
        // update the inclusive sum: count map
        for(auto & itm : sumCount){
            sumCountInc[ itm.first ] += itm.second;
        }
        
        return sumCount;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root) return vector<int>{};
        map<int, int> sumCountInc;
        map<int, int> last = sums(root, sumCountInc);
        vector<int> result;
        int freq = 0;
        for(auto & itm : sumCountInc){
            if(itm.second > freq){
                freq = itm.second;
                result.clear();
                result.push_back(itm.first);
            }else if(itm.second == freq) result.push_back(itm.first);
        }
        return result;
    }
};
