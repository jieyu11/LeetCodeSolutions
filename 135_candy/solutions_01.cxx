class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> nup(n, 1);
        vector<int> ndn(n, 1);
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){ nup[i] = nup[i-1] + 1;}
            if(ratings[n-i-1] > ratings[n-i]){ ndn[n-i-1] = ndn[n-i] + 1;}
        }
        int total = 0;
        for(int i=0; i<n; i++){
            total += max(nup[i], ndn[i]);
        }
        return total;
    }
};
