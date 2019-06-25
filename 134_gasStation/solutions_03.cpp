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
        typedef map<int, vector<int>, std::greater<int>> IntVectorMap;        
        IntVectorMap gasleftIdMap;

        // improved from _01 by considering only the first positive gasleft after a negative gasleft.
        int pre = -1;
        for(int j=0; j<ng; j++){
            int gasleft = gas[j] - cost[j];
            if( gasleft < 0){ pre = gasleft; continue;}
            if( pre <0 ){
                if(gasleftIdMap.find(gasleft) == gasleftIdMap.end()) 
                    gasleftIdMap.insert( make_pair(gasleft, vector<int>{j}) );
                else 
                    gasleftIdMap[gasleft].push_back( j );
            }
            pre = gasleft;
        }

        IntVectorMap::iterator it = gasleftIdMap.begin();
        while(it != gasleftIdMap.end()){
            for(int istart : it -> second){
                int gasleft = it -> first;
                bool success = true;
                for(int j=0; j<ng-1; j++){
                    int k = istart + 1 + j;
                    if(k >= ng) k -= ng;
                    gasleft += gas[k] - cost[k];
                    if(gasleft < 0){
                        success = false;
                        break;
                    }
                }
                if(success){ 
                    return istart;
                }
            }
            it++;
        }
        return -1;
    }
};
