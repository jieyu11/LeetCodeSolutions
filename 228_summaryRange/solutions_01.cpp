class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        //nums = {0,2,3,4,6,8,9};
        int n = nums.size();
        vector<string> result;
        if(n==0) return result;
        string r = "";
        for(int i=0; i<n;){
            r += to_string(nums[i]);
            if(i<n-1 && nums[i] + 1 == nums[i+1]){
                r += "->";
                i++;
                while(i<n-1 && nums[i] + 1 == nums[i+1]){
                    i++;
                }
                r += to_string(nums[i]);
                result.push_back(r);
                r="";
                i++;
            }else{
                i++;
                result.push_back(r);
                r="";
            }
        }
        return result;
    }
};
