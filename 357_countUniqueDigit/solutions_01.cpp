class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> result {1, 10};
        if(n<=1) return result[n];
        int k = 2;
        while(k<=n){
            int j = 0;
            int count = 1;
            while(j<k){
                if(j<=1) count *= 9;
                else     count *= 9 - j + 1;
                j++;
            }
            result.push_back(count + result[k-1]);
            k++;
        }
        return result[n];
    }
};
