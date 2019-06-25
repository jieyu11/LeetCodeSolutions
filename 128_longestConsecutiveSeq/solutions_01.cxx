class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // keep two maps, start -> end & end -> start of the interval
        unordered_map<int, int> statoend;
        unordered_map<int, int> endtosta;
        for(int & i : nums){
            // for each number check if it is in one of the intervals that were already found.
            bool is_interval = false;
            for(auto & itm : statoend){
                if(i <=itm.second && i>= itm.first){
                    is_interval = true;
                    break;
                }
            }
            if(is_interval) continue;
            
            // if it is a new number, check if plus 1 is already one of the start numbers, or minus 1 is one of the end numbers
            // if so, update the two maps
            // if not, just insert the new number into the maps
            int new_end = i, new_sta = i;
            if(i<INT_MAX && statoend.find(i+1)!=statoend.end()){
                new_end = statoend[i+1];
                statoend.erase(i+1);
                endtosta.erase(new_end); 
            }
            if(i>INT_MIN && endtosta.find(i-1)!=endtosta.end()){
                new_sta = endtosta[i-1];
                endtosta.erase(i-1); 
                statoend.erase(new_sta); 
            }
            statoend.insert({new_sta, new_end});
            endtosta.insert({new_end, new_sta});
        }
        
        // calculate the longest sequence
        int llen = 0;
        for(auto & itm : statoend){
            int jlen = itm.second - itm.first + 1;
            if(llen < jlen ) llen = jlen;
        }
        return llen;
    }
};
