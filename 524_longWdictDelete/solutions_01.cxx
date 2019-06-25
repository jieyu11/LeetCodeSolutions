class Solution {
public:
    bool matched(const string & s, const int & ns, const string & s_dict){
        int nd = s_dict.size();
        if(nd > ns) return false;
        int i=0,j=0;
        while(i<ns && j<nd){
            if(s[i]==s_dict[j]){i++; j++;}
            else{ i++; }
        }
        if(j==nd) return true;
        return false;
    }
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), 
            [](const string & s1, const string & s2){
                if(s1.size() > s2.size()) return true;
                if(s1.size() < s2.size()) return false;
                return s1 < s2;
            }
            );
        int ns = s.size();
        for(string & sd : d){
            if(matched(s, ns, sd)) return sd;
        }
        return "";
    }
};
