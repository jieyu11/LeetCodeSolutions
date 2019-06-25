class Solution {
public:
    string getHint(string secret, string guess) {
        //secret = "1123"; //"1";
        //guess = "0111"; //"0";
        
        int iA = 0;
        int n = secret.size();
        // map key: number either in Secret or Guess
        // map value: first -> count in Secret, second -> count in Guess
        typedef unordered_map<int, pair<int,int>> IntPair;
        IntPair countMap;
        for(int j=0; j<n; j++){
            if(secret[j]==guess[j]) iA++;
            else{
                int id = secret[j] - '0';
                if(countMap.find(id) != countMap.end()) countMap[id].first += 1;
                else countMap.insert( make_pair(id, make_pair(1,0) ) );
                id = guess[j] - '0';
                if(countMap.find(id) != countMap.end()) countMap[id].second += 1;
                else countMap.insert( make_pair(id, make_pair(0,1) ) );
            }
        }
        // count the number of cows.
        int iB = 0;
        for(IntPair::iterator it = countMap.begin(); it!= countMap.end(); it++){
            if(!(it->second).first || !(it->second).second) continue;
            iB += min( (it->second).first, (it->second).second );
        }
        string result = to_string(iA) + "A" + to_string(iB) + "B";
        return result;
    }
};
