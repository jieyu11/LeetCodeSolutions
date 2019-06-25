class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(!n) return vector<double>{};
        vector<int> window;
        vector<double> res;
        int k2 = k/2;
        for(int i=0; i<n; i++){
            vector<int>::iterator it = lower_bound(window.begin(), window.end(), nums[i]);
            window.insert(it, nums[i]);
            if(i>=k-1){
                if(i>=k) window.erase( lower_bound(window.begin(), window.end(), nums[i-k]) );
                res.push_back( k%2==0 ? double(window[k2])/2.+double(window[k2-1])/2. : double(window[k2]));
            }
        }
        return res;
    }
};
