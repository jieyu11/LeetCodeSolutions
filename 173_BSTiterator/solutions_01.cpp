/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        index = 0;
        store(root);
        size = numbers.size();
    }
    void store(TreeNode *root){
        if(!root) return;
        
        if( root -> left) store( root -> left );
        numbers.push_back( root -> val);
        if( root -> right) store( root -> right );
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(index < size) return true;
        else             return false;
    }

    /** @return the next smallest number */
    int next() {
        index++;
        return numbers[index - 1];
    }
    
    vector<int> numbers;
    int index;
    int size;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
