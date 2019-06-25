class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // test
        /*
        gas = {2,6,4};
        cost = {3,5,4};
        */
        
        int ng = gas.size(), nc = cost.size();
        if(ng != nc || ng == 0) return -1;
        
        // key: gas[i] - cost[i]
        // value: i
        int pre = -1;
        for(int i=0; i<ng; i++){
            int gasleft = gas[i] - cost[i];
            if( gasleft < 0){
                pre = gasleft;
                continue;
            }
            
            // pre<0: the previous has gasleft <0,
            // then this one is the possible one to finish the loop
            // it cannot be the next one even if the it also has gasleft > 0
            // because in this case, this one should work too.
            if(pre<0){
                bool success = true;
                for(int j=0; j<ng-1; j++){
                    int k = i + 1 + j;
                    if(k >= ng) k -= ng;
                    gasleft += gas[k] - cost[k];
                    if(gasleft < 0){
                        success = false;
                        break;
                    }
                }
                if(success){ 
                    return i;
                }
            }
            pre = gasleft;
        }
        return -1;
    }
};
