class Solution {
public:
    void count(vector<int>& nums, int i0, int & steps){
        steps++;
        if(nums.size() - 1 - i0 <= nums[i0]){
            return;
        }
        int inext = -1;
        int space = 0;
        // at the current index i0, see which next step will take you to a further place
        for(int j = 1; j<=nums[i0]; j++){
            if(space < j+nums[i0+j]){
                space = j+nums[i0+j];
                inext = i0+j;
            }
        }
        count(nums, inext, steps);
    }
    int jump(vector<int>& nums) {
        int n = nums.size() - 1;
        if(n<=0) return 0;
        int steps = 0;
        count(nums, 0, steps);
        return steps;
    }
};
