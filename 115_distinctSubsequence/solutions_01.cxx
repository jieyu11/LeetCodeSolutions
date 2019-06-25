class Solution {
public:
    int numDistinct(string s, string t) {
        int nt = t.size();
        if(!nt) return 0;
        int ns = s.size();
        if(ns<nt) return 0;
        vector<int> app(ns, 0);
        // if the first letter t[0] appears in s, set it to 1
        for(int j=0; j<ns; j++){
            if(s[j]==t[0]) app[j] = 1;
        }
        //
        // print to understand how it works.
        //
        //for(int a : app) cout<<a<<"";
        //cout<<endl;
        for(int i=1; i<nt; i++){
            // for each char in t at i: t[i], adds up all t[i-1] appeared before it.
            // keep this information for next round, i+1
            int app_til_curr = 0;
            vector<int> newapp(ns, 0);
            for(int j=0; j<ns; j++){
                if(s[j]==t[i]) newapp[j] = app_til_curr;
                if(s[j]==t[i-1]) app_til_curr += app[j];
            }
            app = newapp;
            //for(int a : app) cout<<a<<"";
            //cout<<endl;
        }
        // total matched is in the last app vector. Sum them up.
        int total = 0;
        for(int a : app) if(a) total += a;
        return total;
    }
};
