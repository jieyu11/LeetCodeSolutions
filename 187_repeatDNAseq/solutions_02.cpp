class Solution {
public:
    int getn(char & ac){
        if(ac=='C') return 1;
        if(ac=='G') return 2;
        if(ac=='T') return 3;
        return 0;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        size_t ns = s.size();
        vector<string> result;
        set<int> tested;
        set<int> stored;
        if(ns <= 10) return result;
        
        /*
        using bits, every letter consists of 2 bits:
        A:00, C:01, G:10, T:11
        */
        int testnum = 0;
        for(unsigned int j=0; j<10; j++) {
            testnum = testnum << 2;
            testnum += getn(s[j]);
        }
        tested.insert( testnum );
        for(size_t j=10; j<ns; j++){
            // clear the left most bits.
            testnum &= ~(1 << 18);
            testnum &= ~(1 << 19);
            testnum = testnum << 2;
            testnum += getn(s[j]);
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
