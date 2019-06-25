class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        /*
        equations = {{"x1","x2"},{"x2","x3"},{"x3","x4"},{"x4","x5"}};
values = {3.0,4.0,5.0,6.0};
//queries = {{"x1","x5"},{"x5","x2"},{"x2","x4"},{"x2","x2"},{"x2","x9"},{"x9","x9"}};
        queries = {{"x5","x2"}};
        equations = {{ "a","b"},{"e","f"},{"b","e"}};
values = {3.4,1.4,2.3};
queries = {{"b","a"},{"a","f"}};
         */

        map<string, map<string, double>> equValMap; // assign each variable string an index
        int n = equations.size();
        vector<double> results;
        if(n==0 || n != values.size() ) return results;
        for(int i=0; i<n; i++){
            string & sequ1 = equations[i].first;
            string & sequ2 = equations[i].second;
            equValMap[sequ1][sequ1] = 1.;
            equValMap[sequ2][sequ2] = 1.;
            equValMap[sequ1][sequ2] = values[i];
            if(values[i] != 0.){
                equValMap[sequ2][sequ1] = 1. / values[i];
            }
            for(auto & itm3 : equValMap[sequ1]){ // sequ1 / sequ3 = val13
                string sequ3 = itm3.first;
                double val13 = itm3.second;
                for(auto & itm4 : equValMap[sequ2]){ // sequ2 / sequ4 = val24
                    string sequ4 = itm4.first;
                    if(equValMap.find(sequ3)!=equValMap.end() && equValMap[sequ3].find(sequ4) !=equValMap[sequ3].end()) continue;
                    // sequ1 / sequ2 = val12, so:
                    // sequ3 / sequ4 = 1/val13 * val24 * val12
                    double val24 = itm4.second;
                    if(val13 != 0.) equValMap[sequ3][sequ4] = 1./val13 * val24 * values[i];
                    if(equValMap[sequ3][sequ4] != 0.) equValMap[sequ4][sequ3] = 1./equValMap[sequ3][sequ4];
                }
            }
        }
        /*
        for(auto & itm : equValMap){
            for(auto & i2 : equValMap[itm.first]){
                cout<<itm.first<<" / "<<i2.first<<" = "<<i2.second<<endl;
            }
        }
        */
        for(auto & q : queries){
            if(equValMap.find(q.first) == equValMap.end() || equValMap[q.first].find(q.second) == equValMap[q.first].end()){
                results.push_back(-1.);
            }else{
                results.push_back(equValMap[q.first][q.second]);
            }
        }
        return results;
    }
};
