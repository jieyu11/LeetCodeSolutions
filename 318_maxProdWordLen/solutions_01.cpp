class Solution {
public:
    bool withOverlapChar(string & s1, string & s2){
        //if(s1.size() > s2.size()) return withOverlapChar(s2, s1);
        for(char c1 : s1){
            if(s2.find(c1) != string::npos) return true;
        }
        return false;
    }
    // sort string from long to short
    /*
    bool compare(const string& first, const string& second) {
        return first.size() > second.size();
    }
    */
    struct compare {
        bool operator()(const std::string& first, const std::string& second) {
            return first.size() > second.size();
        }
    };
    int maxProduct(vector<string>& words) {
        //words = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
        int n = words.size();
        if(n==0) return 0;
        compare cc;
        sort(words.begin(), words.end(), cc);
        int max = 0;
        for(int i=0; i<n-1; i++){
            int nwi = words[i].size();
            if(nwi * nwi <= max) break;
            for(int j=i+1; j<n; j++){
                int nwj = words[j].size();
                int count = nwi * nwj;
                if( count <= max) break;
                if(!withOverlapChar(words[j], words[i])){
                    max = count;
                }
            }
        }
        return max;
    }
};
