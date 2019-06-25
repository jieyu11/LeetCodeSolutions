class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int, int> kn;
        for(int j : nums){
            if(kn.find(j) != kn.end()){
                kn[j] ++;
            }else{
                kn.insert( make_pair(j, 1) );
            }
        }
        int n = nums.size();
        int i = 0;
        for(map<int,int>::iterator it = kn.begin(); it!=kn.end(); it++){
            i += it->second;
            if(i>=(n-k+1)) return it->first;
        }

    }
};
