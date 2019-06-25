class Solution {
public:
// OVER TIME LIMIT
    vector<int> countSmaller(vector<int>& nums) {
        //nums = {5, 2, 5, 2, 6, 5, 1};
        int n = nums.size();
        vector<int> result(n,0);
        multiset<int> numright;
        // if there are duplicates in the inputs
        // should keep on track of these cases.
        map<int, int> numdup;
        for(int i=n-1; i>=0; i--){
            //pair<set<int>::iterator, bool> itb = numright.insert(nums[i]);
            multiset<int>::iterator it = numright.insert(nums[i]);
            if(it != numright.begin()){
                multiset<int>::iterator it0 = it; it0--;
                while(it!= numright.begin() && *it == *it0){
                    it--;
                    it0--;
                }
            }
            result[i] = distance(numright.begin(), it);// itb.first
            /*
            if(!itb.second){ // the element is already in the <set>
                // first duplicate
                if(numdup.find(nums[i]) == numdup.end()) numdup.insert( make_pair(nums[i], 1) );
                else numdup[ nums[i] ]++; // more than one duplicate
            }
            if(!numdup.empty()){
                int ndup = 0;
                map<int, int>::iterator it0 = numdup.begin();
                map<int, int>::iterator it1 = numdup.end();
                for(; it0 != it1; it0++){
                    // only count those smaller than nums[i]
                    if(it0->first >= nums[i]) break; 
                    ndup += it0->second;
                }
                result[i] += ndup;
            }
            */
            
        }
        return result;
    }
};
