/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result  = "";
        if(!root) return result;
        queue<TreeNode*> nodes; nodes.push(root);
        while(!nodes.empty()){
            TreeNode* n = nodes.front();
            nodes.pop();
            if(n){
                result += to_string( n -> val );
                nodes.push(n->left);
                nodes.push(n->right);
            }
            result += ',';  
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        if(data.empty() || data == ",") return root;
        size_t k0 = 0;
        size_t k1 = data.find(',');
        root = new TreeNode( stoi(data.substr(k0, k1-k0)) );
        queue<TreeNode*> nodes; nodes.push(root);
        k0 = k1+1; k1 = data.find(',', k0);
        while(k1 != string::npos){
            TreeNode * n = nodes.front();
            nodes.pop();
            
            string s0 = data.substr(k0, k1-k0);
            //cout<<s0<<endl;
            if(!s0.empty()){
                n -> left = new TreeNode( stoi(data.substr(k0, k1-k0)) );
                //cout<<n->val<<", left "<<n->left->val<<endl;
                nodes.push(n->left);
            }
            k0 = k1+1; k1 = data.find(',', k0);
            s0 = data.substr(k0, k1-k0);
            if(!s0.empty()){
                n -> right = new TreeNode( stoi(data.substr(k0, k1-k0)) );
                //cout<<n->val<<", right "<<n->right->val<<endl;
                nodes.push(n->right);
            }
            k0 = k1+1; k1 = data.find(',', k0);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
