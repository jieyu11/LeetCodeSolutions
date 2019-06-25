class Solution {
public:
    
    // recursion function to get the results
    // current: current sequence holding the first a few digits, e.g. 3,1 (from 1,2,3,4)
    // rest: the rest of the digits needs to be added, e.g. 2,4
    void solve(vector<vector<int>> & result, vector<int> current, vector<int> rest, int nmax){
        // size of the current, used to check if current is empty or not
        int ncur = current.size();
        
        // only do the first half of the possible answers,
        // the second half is simply reversing the first half answers
        if(ncur > 0 && nmax%2==0  && current[0] > nmax/2    ) return;
        if(ncur > 0 && nmax%2==1  && current[0] > nmax/2 + 1) return;

        // when rest is empty, it means current is fully filled.
        // store the current into result and return -> this sequence is done!
        if(rest.size()==0){
            result.push_back( current );
            return;
        }
        
        for(vector<int>::iterator it=rest.begin(); it!=rest.end(); it++){
            // starting from the "rest" of the numbers, one by one
            // to add into current
            // skip those numbers which are:
            // +-1 compared to the 1 step  before the "it" under test (last digit in current)
            // +-2 compared to the 2 steps before the "it"
            // ...
            if( ncur > 0 ){
                bool skip = false;
                for(int ic=1; ic<=ncur; ic++){
                    if( abs(current[ncur - ic] - (*it)) == ic ){ skip = true; break; }
                }
                if(skip) continue;
            }
            
            // copy the current for next round and put "it" from rest to the next current
            vector<int> currnext = current;
            currnext.push_back( *it );
            
            // at the same time, remove this number "it" for the next round of rest
            vector<int> restnext;
            restnext.insert(restnext.end(), rest.begin(), it);
            restnext.insert(restnext.end(), it+1, rest.end());
            
            // go through the next round then!
            solve(result, currnext, restnext, nmax);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        // The problem is converted to:
        // given 1,2,3,4, provide all sequeces that no adjacent numbers are continuous
        // e.g. only 3,1,4,2 and 2,4,1,3 is allowed
        // TODO: 
        // make use of the symmetric nature, 2,4,1,3 is simply reversed order to 3,1,4,2
        // only need to work with numbers starting with the first half of the numbers,
        // e.g. n=4, consider 1--,2--
        // e.g. n=5, consider 1--,2--,34--,35--

        // test: 
        // n = 5;
        
        vector<int> rest( n ) ; 
        iota (begin(rest), end(rest), 1); // Fill with 1, ... n.
        vector<int> nums;
        vector<vector<int>> result;
        
        solve(result, nums, rest, n);
        
        
        // test: print
        /*
        for(auto ares: result){
            for(auto i : ares){
                cout<<i<<", ";
            }
            cout<<endl;
        }
        */
        
        
        // convert numbers into strings!!
        vector<vector<string>> strres;
        for(auto ires: result){
            vector<string> sres;
            for(int i : ires){
                string as = "";
                for(int j=1; j<=n; j++){
                    if(j==i) as += 'Q';
                    else     as += '.';
                }
                sres.push_back( as );
            }
            strres.push_back(sres);
        }
        
        // if results after n/2 are not included,
        // add them to the tail
        vector<vector<string>> strresmore;
        for(auto ires: result){
            if( ires[0] > n/2 ) break;
            
            vector<string> sres;
            for(int i : ires){
                string as = "";
                for(int j=1; j<=n; j++){
                    // if i=1, put Q at n
                    // if i=2, put Q at n-1 ...
                    if( j== (n+1-i) ) as += 'Q';
                    else              as += '.';
                }
                sres.push_back( as );
            }
            strresmore.insert(strresmore.begin(), sres);
        }
        strres.insert( strres.end(), strresmore.begin(), strresmore.end());
        
        
        return strres;

    }
};
