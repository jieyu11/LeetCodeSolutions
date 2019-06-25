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
    TreeNode* get(vector<int> & preorder, vector<int> & inorder){
        int treesize = preorder.size();
        if(treesize <= 0) return NULL;
        int numhead = preorder.at(0);
        TreeNode* head = new TreeNode( numhead );
        if(treesize == 1) return head;
        
        // left sub-tree
        // find the position of the head in the inorder vector
        size_t lefttreesize = 0;
        for(int i=0; i<treesize; i++){ 
            if(inorder[i] == numhead){ break; }
            lefttreesize++;
        }
        vector<int> inorder_left  ( inorder.begin(), inorder.begin() + lefttreesize );
        // right sub-tree inorder, skip the current head by +1
        vector<int> inorder_right ( inorder.begin() + lefttreesize + 1, inorder.end() );
        inorder.clear();
        
        // pre-order sub-trees
        vector<int> preorder_left  ( preorder.begin() + 1, preorder.begin() + lefttreesize + 1 );
        vector<int> preorder_right ( preorder.begin() + lefttreesize + 1, preorder.end() );
        preorder.clear();

        TreeNode* lefthead  = get(preorder_left,  inorder_left );
        TreeNode* righthead = get(preorder_right, inorder_right);
        
        head -> left = lefthead;
        head -> right = righthead;        
        return head;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
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
        
        // 1st item from Preorder is the root: 1
        // 1st -- before the 1 in Inorder is from left sub-tree (4 2 5)
        // right after 1 in Inorder is the right sub-tree (3...)
        // between 1 and 3 in Preorder is the left sub-tree
        */
        /*
        //test:
        preorder = {1, 2, 4, 5, 3};
        inorder = {4, 2, 5, 1, 3};
        
        preorder = {4,1,2,3};
        inorder = {1,2,3,4};
        */
        int npr = preorder.size(), nin = inorder.size();
        if(npr != nin || npr == 0) return NULL;
        
        return get(preorder, inorder);
        
    }
};
