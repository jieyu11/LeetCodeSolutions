class Solution {
public:
    int hIndex(vector<int>& citations) {
        //citations = {3, 0, 6, 1, 5};
        int n = citations.size();
        if(n==0) return 0;
        sort( citations.begin(), citations.end() );
        for(int i=0; i<n; i++){
            if(citations[i] >= n-i) return (n-i); 
        }
        return 0;
    }
};
