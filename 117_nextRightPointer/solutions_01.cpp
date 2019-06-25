/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode *> nodeq;
        nodeq.push(root);
        while(!nodeq.empty()){
            int sizeq = nodeq.size();
            TreeLinkNode * p0 = NULL;
            for(int i=0; i<sizeq; i++){
                TreeLinkNode * p = nodeq.front();
                nodeq.pop();
                if(i==0) p0 = p;
                else{
                    p0 -> next = p;
                    p0 = p;
                }
                if(p->left ) nodeq.push( p->left  );
                if(p->right) nodeq.push( p->right );
            }            
        }        
    }
};
