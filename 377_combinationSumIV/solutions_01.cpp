class Solution {
public:

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> result(target+1, 0);
        for(int i=0; i<=target; i++){
            int all = 0;
            for(auto a : nums){
                if     (i == a) all++;
                else if(i  > a) all += result[ (i - a) ];
            }
            result[i] = all;
        }
        
        return result[target];
    }
};
