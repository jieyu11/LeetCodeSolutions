class Solution {
public:
    bool lookfor(vector<int>& nums, int i0, int i1, const int & target){
        if(i0 > i1) return false;
        if(nums[i0] < nums[i1]){
            vector<int>::iterator it = lower_bound(nums.begin()+size_t(i0), nums.begin()+size_t(i1+1), target);
            if(*it == target) return true;
            else return false;
        }
        int imid = i0 + (i1-i0)/2;
        if(nums[imid]==target) return true;
        if(lookfor(nums, i0, imid-1, target) || lookfor(nums, imid+1, i1, target) ) return true;
        return false;

    }
    bool search(vector<int>& nums, int target) {
        return lookfor(nums, 0, nums.size()-1, target);
    }
};
