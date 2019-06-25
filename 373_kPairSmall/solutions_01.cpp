class Solution {
public:
    struct comparePair {
        bool operator() (const pair<int, int> & A, const pair<int, int> & B) const {
            int sumA = A.first + A.second;
            int sumB = B.first + B.second;
            if ( sumA < sumB ) return true;
            if ( sumA > sumB ) return false;
            return A.first > B.first;
        }
    };

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        multiset<pair<int, int>, comparePair> resultSet;
        int n1 = nums1.size(); n1 = min(n1,k);
        int n2 = nums2.size(); n2 = min(n2,k);
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                pair<int, int> pX(nums1[i], nums2[j]); 
                //if(nums1[i] > nums2[j]) swap(pX.first, pX.second);
                resultSet.insert(pX);
            }
        }
        vector<pair<int, int>> result;
        int idx = 0;
        for(auto ar : resultSet){
            result.push_back( ar );
            idx++;
            if(idx>=k) break;
        }
        return result;
    }
};
