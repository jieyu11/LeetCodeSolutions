class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //nums = {1,3,-1,-3,5,3,6,7};
        //k = 3;
        if( k == 1 ) return nums;
        vector<int> result;
        int n = nums.size();
        if( k < 1 || n==0 || n < k) return result;
        map<int,int, std::greater<int>> nCountMap;
        for(int i=0; i<n; i++){
            map<int, int>::iterator it = nCountMap.find(nums[i]);
            if( it != nCountMap.end()) (it -> second) += 1;
            else nCountMap.insert( make_pair(nums[i], 1) );
            if(i>=k){
                map<int, int>::iterator it_out = nCountMap.find(nums[i-k]);
                if(it_out -> second > 1) (it_out -> second) -= 1;
                else nCountMap.erase( it_out );
            }
            if(i>=k-1){
                result.push_back( (nCountMap.begin()) -> first);
            }
        }
        return result;
    }
};
