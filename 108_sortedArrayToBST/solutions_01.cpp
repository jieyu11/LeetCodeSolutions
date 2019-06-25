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
    TreeNode* build(vector<int>& nums, int istart, int iend){
        if(istart>iend) return NULL;
        int imid = (istart + iend + 1) / 2;
        TreeNode * head = new TreeNode( nums[imid] );
        if( istart == iend ) return head;
        TreeNode * left = build(nums, istart, imid - 1);
        TreeNode * right = build(nums, imid + 1, iend);
        head -> left = left;
        head -> right = right;
        return head;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        return build( nums, 0, nums.size() - 1);
    }
};
