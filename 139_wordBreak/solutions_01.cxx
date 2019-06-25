class Solution {
public:
    bool startWith(const string & s_long, const int & idx_start, const string & s_short){
        if(s_long.size() - idx_start < s_short.size()) return false;
        for(int i=0; i<s_short.size(); i++){if(s_long[i+idx_start] != s_short[i]) return false; }
        return true;
    }
    
    bool match(const string & s, int idx_start, set<int> & usedIndex, vector<string>& wordDict){
        if(usedIndex.find(idx_start) != usedIndex.end()) return false;
        if(idx_start == s.size()) return true;
       usedIndex.insert(idx_start);
        for(string & aword : wordDict){
            if(startWith(s, idx_start, aword)){
                if( match(s, idx_start+int(aword.size()), usedIndex, wordDict)) return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        /*
        s = "catsandog";
        wordDict = {"cats", "dog", "sand", "and", "cat"};
        */
        // sort from long words to short words
        /*
        sort(wordDict.begin(), wordDict.end(),
            [](const string & s1, const string & s2){
                return s1.size() >= s2.size();
            }
            );
            */
        set<int> usedIndex;
        return match(s, 0, usedIndex, wordDict);
    }
};
