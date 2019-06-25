class Solution {
public:
    int NUMBER = 1337;

    int check(int a, vector<int>& b){
        bool isOne = true;
        for(int i=b.size() - 2; i>=0; i--) if(b[i] > 0){isOne = false; break;}
        if(isOne && b[b.size()-1] > 1) isOne = false;
        if(isOne) return a % NUMBER;
        
        // take the half of b!!!
        int remain = 0;
        for(int i=0; i<b.size(); i++){
            int tmp = b[i] % 2;
            b[i] = (remain * 10 + b[i]) / 2;
            remain = tmp;
        }
        int test = check(a, b);
        test %= NUMBER;
        test *= test;
        test %= NUMBER;
        if(remain){ 
            test *= a % NUMBER;
            test %= NUMBER;
        }
        return test;
    }
    int superPow(int a, vector<int>& b) {
        bool allzero = true;
        for(int i : b) if(i){allzero = false; break;}
        if(allzero) return 0;
        
        return check(a, b);
    }
};
