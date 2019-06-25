class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // divide the prices at any point into two sub-prices,
        // calculate the maximum in both sub-prices.
        // prices = {9,8, 6, 1,3,5,6,7,2,4,3,5,8};
        //prices = vector<int>(2000, 0);
        //for(int i=1; i<=2000; i++) prices[i-1] = i*2;
        
        int np = prices.size();
        if(np<=1) return 0;

        // loop 0 -- np
        // at each position, i, calculate the possible maximum profit
        // from 0 -- i
        vector<int> profit1(np, 0);
        int min = INT_MAX, maxprofit = 0;
        for(int i=0; i<np; i++){
            if(min > prices[i]) min = prices[i];
            int curprofit = prices[i] - min;
            
            if( curprofit > maxprofit ){
                maxprofit  = curprofit;
            }
            profit1[i] = maxprofit;
        }

        // loop from np - 1 -- 0
        // at each position, i, calculate the possible maximum profit
        // from i -- np - 1
        vector<int> profit2(np, 0);
        int max = 0;
        maxprofit = 0;
        for(int i=np-1; i>=0; i--){
            if(max < prices[i]) max = prices[i];
            int curprofit = max - prices[i];
            
            if( curprofit > maxprofit ){
                maxprofit  = curprofit;
            }
            profit2[i] = maxprofit;
        }
        
        // maximum profit initialized with the max from 0 -- np
        // compare it to the combination of 0 -- i (+) i+1 -- np
        // because one can only do "two" transactions at most
        maxprofit = profit2[0];
        for(int i=1; i<np-2; i++){
            if(profit1[i] + profit2[i+1] > maxprofit) maxprofit = profit1[i] + profit2[i+1];
        }
        return maxprofit;
    }
};
