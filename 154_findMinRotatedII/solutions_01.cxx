class Solution {
public:
    void findMin(vector<int>& nums, int i0, int i1, int & minval){
        if(i0>i1) return;
        if(i0==i1){ minval = min(minval, nums[i0]); return; }
        int j = i0 + (i1 - i0) / 2;
        if(nums[j] < nums[i1]){
            minval = min(nums[j], minval);
            findMin(nums, i0, j-1, minval);
        }else if(nums[j] > nums[i0]){
            minval = min(nums[i0], minval);
            findMin(nums, j+1, i1, minval);
        }else{
            findMin(nums, i0, j-1, minval);
            findMin(nums, j+1, i1, minval);
        }
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int minval = INT_MAX;
        findMin(nums, 0, n-1, minval);
        return minval;
    }
};
