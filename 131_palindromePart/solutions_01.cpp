class Solution {
public:
    bool isPalindrome(string s){
        int nch = s.size();
        if(nch<=1) return true;
        for(int i=0; i<nch/2; i++){
            if(s[i] != s[nch-1-i]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        // test: 
        //s = "aaaa";
        //s = "aba";
        int nch = s.size();
        vector<vector<string>> result;
        if(nch==0) return result;

        result.push_back( vector<string>{s.substr(0,1)} );
        for(int i=1; i<nch; i++){
            //attach the char to the last element of the 
            //existing results, check it is also a palindrome
            //if yes, keep it!
            int nres = result.size();
            for(int j=0; j<nres; j++){
                vector<string> ares = result.at(j);
                int ilast = ares.size() - 1;
                ares[ilast] += s[i];
                if( isPalindrome( ares[ilast] ) ){
                    result.push_back(ares);
                }
                else if(ilast > 0){   
                    // consider cases like "aba", when the last 'a' is added
                    // check the previous two char, 'a' and 'b'
                    if( isPalindrome( ares[ilast-1]+ares[ilast] ) ){
                        ares[ilast-1] += ares[ilast];
                        ares.erase( ares.end() - 1 );
                        result.push_back(ares);
                    }
                }
            }
            //single letter is always OK.
            for(int j=0; j<nres; j++){
                result[j].push_back(s.substr(i,1));
            }
        }

        return result;
    }
};
