class Solution {
// 26ms, beat 97%
public:
    class BSTree{
        public:
        BSTree(int m_val) : val(m_val), left(NULL), right(NULL), nless(0), ndup(1){
            
        }
        BSTree * left;
        BSTree * right;
        int ndup; // number of duplicates at this value
        int val;
        int nless; // number of values on the left side of this node. upper nodes are not counted!!!
    };
    // insert one node, return how many numbers previous inserted is lower than it.
    int insertNode(int m_val, BSTree * head){
        if (m_val == head -> val){
            head -> ndup++; 
            return head -> nless;
        }else if (m_val < head -> val){     
            // for m_val < head -> val below:
            head -> nless ++;
            if(head -> left)
                return insertNode(m_val, head -> left);
            else{
                BSTree * left = new BSTree(m_val);
                left -> nless = 0;
                head -> left = left;
                return 0;
            }
        }else{
            if(head -> right)
                return head->nless + head->ndup + insertNode(m_val, head -> right);
            else{
                BSTree * right = new BSTree(m_val);
                right -> nless = 0;
                head -> right = right;
                return head->nless + head->ndup;
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
