// time limit excceeded 
class Solution {
public:
    bool isNeighbour(string & w1, string & w2){
        if(w1.size() != w2.size()) return false;
        int ndif=0;
        for(int i=0; i<w1.size(); i++){
            if(w1[i] != w2[i]) ndif++;
            if(ndif >=2) return false;
        }
        if(ndif==1) return true;
        return false;
    }
    void ladder(vector<string>& wordList, vector<vector<int>> & neighbours, const int & endIndex, 
                vector<bool> used, int curIndex, 
                vector<string> seq, vector<vector<string>> & result){
        if(!result.empty() && seq.size() >= result[0].size()) return;
        if(used[curIndex]) return;
        
        if(curIndex == endIndex){
            seq.push_back( wordList[endIndex] );
            if(result.empty() || seq.size() == result[0].size()){ result.push_back(seq); return; }
            if(seq.size() > result[0].size()) return;
            result.clear();
            result.push_back(seq); return;
        }else{
            used[curIndex] = true;
            seq.push_back( wordList[curIndex] );
            for(int nextIndex : neighbours[curIndex]){
                ladder(wordList, neighbours, endIndex, used, nextIndex, seq, result);
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        int n = wordList.size();
        vector<vector<string>> result;
        if(!n) return result;
        if(beginWord == endWord) return result;
        int endword_idx = -1;
        for(int i=0; i<n; i++){
            if(wordList[i] == endWord) endword_idx = i;
        }
        if(endword_idx < 0) return result;
        
        // create graph
        wordList.push_back(beginWord);
        n++;
        vector<vector<int>> neighbours(n, vector<int>{});
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isNeighbour(wordList[i], wordList[j])){
                    neighbours[i].push_back(j);
                    neighbours[j].push_back(i);
                }
            }
        }
        
        vector<bool> used(n, false);
        used[n-1] = true;
        for(int inext : neighbours[n-1]){
            ladder(wordList, neighbours, endword_idx, used, inext, vector<string>{beginWord}, result);
        }
        return result;
    }
};
