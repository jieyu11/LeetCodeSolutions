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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder){
        if( postorder.size() == 0 || postorder.size() != inorder.size() ) return NULL;
        int jend = postorder.size() - 1;
        TreeNode * head = new TreeNode(postorder[jend]);
        if(postorder.size() == 1) return head;
        
        size_t jright = jend;
        for(int i=inorder.size()-1; i>=0; i--){
            if(inorder[i] == postorder[ jend ]){
                break;
            }
            jright--;
        }
        TreeNode * right = NULL;
        if(jright < jend){
            vector<int> inorder_right(inorder.begin() + jright + 1, inorder.end() );
            vector<int> postorder_right(postorder.begin() + jright, postorder.end() - 1 );
            right = build(inorder_right, postorder_right);
        }
        TreeNode * left = NULL;
        if(jright > 0){
            vector<int> inorder_left(inorder.begin(), inorder.begin() + jright);
            vector<int> postorder_left(postorder.begin(), postorder.begin() + jright);
            left = build(inorder_left, postorder_left);
        }
        inorder.clear();
        postorder.clear();
        head -> left = left;
        head -> right = right;
        return head;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        /*
        tree:
            1
           / \
          2   3
         / \
        4   5
        Depth First Traversals:
        (a) Inorder (Left, Root, Right) : 4 2 5 1 3
        (b) Preorder (Root, Left, Right) : 1 2 4 5 3
        (c) Postorder (Left, Right, Root) : 4 5 2 3 1
        */      
        return build(inorder, postorder);
    }
};
