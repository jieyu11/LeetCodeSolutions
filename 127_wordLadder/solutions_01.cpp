class Solution {
public:
    bool difbyonechar(string & refWord, string & testWord) const {
        // see if the two words are different with 1 charachater or not.
        
        if(refWord == testWord) return false;
        int idif = 0;
        for(int i=0; i<refWord.size(); i++){
            if(refWord[i] != testWord[i]) idif++;
            if(idif > 1) return false;
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ns = beginWord.size();
        int nl = wordList.size();
        if( ns==0 || nl==0 || ns != endWord.size() ) return 0;
        
        queue<int> idxnext; 
        idxnext.push(-1);
        // count the current level, the beginWord has level 1,
        // the words in wordList should be from 2 to ...
        vector<int> ilevel( nl, 0);
        // check if the word has been visited or not.
        vector<bool> checked( nl, false);
        
        int minSteps = nl+2;
        while(!idxnext.empty()){
            int idxnow = idxnext.front(); 
            idxnext.pop();
            if(idxnow<0){
                // beingWord
                if(beginWord == endWord) return 2;
                for(int i=0; i<nl; i++){
                    if(difbyonechar(beginWord, wordList[i])){
                        idxnext.push( i );
                        ilevel[i] = 2;
                    }
                }
            }else{
                // the word in the dict has already been visited, skip
                if( checked[idxnow] ) continue;
                checked[idxnow] = true;
                if( wordList[idxnow] == endWord){ 
                    if(ilevel[idxnow] < minSteps) minSteps = ilevel[idxnow];
                    continue;
                }
                //cout<<idxnow<<", "<<wordList[idxnow]<<endl;
                for(int i=0; i<nl; i++){
                    // checked or already in queue (ilevel > 0), skip
                    if( checked[i] || ilevel[i] > 0) continue;
                    if(difbyonechar(wordList[idxnow], wordList[i])){ 
                        idxnext.push( i );
                        ilevel[i] = ilevel[idxnow] + 1;
                        //cout<<" neighbour: "<<i<<", "<<wordList[i]<< " "<<ilevel[i]<<endl;
                    }
                }
            }
        }
        if(minSteps>nl+1) return 0;
        else return minSteps;
    }
};
