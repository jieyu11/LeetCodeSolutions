class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return vector<vector<int>>{};
        set<vector<int>> result;
        for(int i=1; i<n; i++){
            if(!result.empty()){
                set<vector<int>> resmore;
                for(auto & v : result){
                    if(nums[i]>=v.back()){
                        vector<int> v1 = v; v1.push_back(nums[i]);
                        if(result.find(v1) == result.end() && resmore.find(v1) == resmore.end()) resmore.insert(v1);
                    }
                }
                result.insert(resmore.begin(), resmore.end());
            }
            for(int j=0; j<i; j++){
                if(nums[j]<=nums[i] && result.find( {nums[j], nums[i]} ) == result.end()) result.insert( vector<int>{nums[j], nums[i]} );
            }
        }
        vector<vector<int>> r;
        r.insert(r.end(), result.begin(), result.end());
        return r;
    }
};
