class Solution {
public:
    vector<int> countBits(int num) {
        /*
        0: 0000
        
        1: 0001
        
        2: 0010 meaning result[0]+1
        3: 0011 meaning result[1]+1
        
        4: 0100 meaning result[0]+1
        5: 0101 meaning result[1]+1
        6: 0110 meaning result[2]+1
        7: 0111 meaning result[3]+1
        
        8: 1000 meaning result[0]+1
        ...
        */
        vector<int> result{0};
        if(num==0) return result;
        result.push_back(1);
        if(num==1) return result;
        int iend = 2, n = 2;
        while(true){
            for(int j=0; j<iend; j++){
                result.push_back( result[j] + 1 );
                if(n==num) return result;
                n++;
            }
            iend *= 2;
        }
    }
};
