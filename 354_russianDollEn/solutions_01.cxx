class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        //envelopes = {{46,89},{50,53},{52,68},{72,45},{77,81}};
        //envelopes = {{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}};
        int n = envelopes.size();
        if( n <= 1) return n;
        sort(envelopes.begin(), envelopes.end());
        multimap<int, int, greater<int>> numIdxMap; // key: number of envelopes at the index, value: index
        numIdxMap.insert( {1,0} ); // n=1, index = 0;
        for(int i=1; i<n; i++){
            bool found = false;
            for(auto & ei : numIdxMap){
                int & idx = ei.second;
                if( envelopes[i].first > envelopes[idx].first && envelopes[i].second > envelopes[idx].second ){
                    numIdxMap.insert( {ei.first + 1, i} );
                    found = true;
                    break;
                }
            }
            if(!found){
                numIdxMap.insert( {1,i} );
            }
        }
        return (numIdxMap.begin())->first;
    }
};
