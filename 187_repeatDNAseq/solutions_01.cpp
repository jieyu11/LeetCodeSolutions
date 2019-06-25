class Solution {
public:
    unsigned int getn(char & ac){
        if(ac=='C') return 1;
        if(ac=='G') return 2;
        if(ac=='T') return 3;
        return 0;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        size_t ns = s.size();
        vector<string> result;
        set<unsigned int> tested;
        set<unsigned int> stored;
        if(ns <= 10) return result;
        
        const int denom = pow(10,9);
        /*
        A:0, C:1, G:2, T:3
        conert string into number,
        e.g.: AAAAACCCCC = 0000011111 = 11111
        */
        unsigned int testnum = 0;
        for(unsigned int j=0; j<10; j++) testnum = testnum * 10 + getn(s[j]);
        tested.insert( testnum );
        for(size_t j=10; j<ns; j++){
            testnum = testnum % denom * 10 + getn(s[j]);
            if(stored.find(testnum)!=stored.end()) continue;
            if(tested.find(testnum)!=tested.end()){
                result.push_back( s.substr(j-9,10) );
                stored.insert( testnum );
            }else{
                tested.insert( testnum );
            }
        }
        return result;
    }
};
