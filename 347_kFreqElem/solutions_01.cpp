class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int i : nums){
            if(count.find(i)!=count.end()) count[i]++;
            else count.insert(make_pair(i,1));
        }
        multimap<int, int> revcount;
        for(auto idx:count){
            revcount.insert( make_pair(idx.second, idx.first) );
        }
        vector<int> result;
        int idx = 0;
        for(multimap<int, int>::reverse_iterator itr = revcount.rbegin(); itr != revcount.rend(); itr++){
            if(idx < k ) result.push_back(itr -> second);
            else break;
            idx++;
        }
        return result;
    }
};
