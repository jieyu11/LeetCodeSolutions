class Solution {
public:
    void get(const string & s, const int & n, int i, int isection, string cur, vector<string> & result){
        if(n-i > 3 * (4 - isection) || i>=n) return;
        if(isection == 3){
            if(s[i]=='0' && n-i>1) return;
            int num = stoi(s.substr(i, n-i));
            if(num<=255) result.push_back( cur+s.substr(i, n-i) );
            return;
        }
        int ndig = 3; // maximu of 3 digits
        if(s[i]=='0') ndig = 1; // if start with 0, use only one digit
        for(int j=1; j<=ndig; j++){
            string stest = s.substr(i,j);
            if(j==3 && stoi(stest) > 255) continue;
            get(s, n, i+j, isection+1, cur+stest+'.', result);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        //["0.10.0.10","0.100.1.0"]
        //s = "010010";
        int n = s.size();
        vector<string> result;
        get(s, n, 0, 0, "", result);
        return result;
    }
};
