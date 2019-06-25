class Solution {
public:
    int calc(int n, vector<int> & results){
        if(results[n] > 0) return results[n];
        int count_min = INT_MAX;
        for(int i=1; i<=n; i++){
            int j2 = i * i;
            if(j2 >n) break;
            if(j2==n) return 1;
            count_min = min(count_min, calc(n-j2, results)+1);
        }
        results[n] = count_min;
        return count_min;
    }
    int numSquares(int n) {
        vector<int> results(n+1, 0);
        for(int i=1; i<=n; i++){
            int j2 = i * i;
            if(j2==n) return 1;
            if(j2>n) break;
            results[j2] = 1;
        }
        return calc(n, results);
    }
};
