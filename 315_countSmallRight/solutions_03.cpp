class Solution {
public:
// OVER TIME LIMIT
    class BSTree{
        public:
        BSTree(int m_val) : val(m_val), left(NULL), right(NULL), nless(0), ndup(1){
            
        }
        BSTree * left;
        BSTree * right;
        int ndup; // number of duplicates at this value
        int val;
        int nless; // number of values on the left side of this count.
    };
    // insert one node, return how many numbers previous inserted is lower than it.
    int insertNode(int m_val, BSTree * head){
        if (m_val <= head -> val){
            // should do nless++ to all nodes under head->right.
            queue<BSTree *> nodeRight; if(head->right) nodeRight.push(head->right);
            while(!nodeRight.empty()){
                BSTree * ndr = nodeRight.front();
                nodeRight.pop();
                if(ndr){
                    ndr -> nless++;
                    if(ndr->right) nodeRight.push(ndr->right);
                    if(ndr->left) nodeRight.push(ndr->left);
                }
            }
            
            if(m_val == head -> val) { head -> ndup++; return head -> nless;}
            
            // for m_val < head -> val below:
            head -> nless ++;
            if(head -> left)
                return insertNode(m_val, head -> left);
            else{
                BSTree * left = new BSTree(m_val);
                // should subtract itself (also smaller than head)
                left -> nless = head -> nless - 1;
                head -> left = left;
                return left -> nless;
            }
        }else{
            if(head -> right)
                // since it is over head, so, it should at least larger than head and those smaller than head.
                return insertNode(m_val, head -> right);
            else{
            // since it is larger than head -> val, then 
            // it should include all in head and smaller than head
                BSTree * right = new BSTree(m_val);
                right -> nless = head->nless + head->ndup;
                head -> right = right;
                return right -> nless;
            }
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);
        if(n==0) return result;
        
        BSTree * head = new BSTree(nums[n-1]);
        for(int i=n-2; i>=0; i--){
            result[i] = insertNode(nums[i], head);
        }
        return result;
    }
};
