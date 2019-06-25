class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(); // < 10 ^{n1}
        int n2 = num2.size(); // < 10 ^{n2}
        string res(n1+n2+1, '0'); // < 10 ^{n1} * 10 ^{n2} = 10 ^{n1 + n2} --> size <= n1 + n2 + 1
        for(int i1 = 0; i1 < n1; i1++){
            for(int i2 = 0; i2 < n2; i2++){
                int cur = (num1[n1-1-i1] -'0') * (num2[n2-1-i2] - '0'); // from very right
                // put the result from left to right, reverse it in the end
                int ip0 = res[i1+i2] - '0';
                res[i1+i2] = '0' + (cur%10 + ip0) % 10;
                int ip1 = cur/10 + (cur%10 + ip0) / 10;
                int idx = i1+i2+1;
                while(ip1 > 0){
                    int tmp = res[idx] - '0';
                    res[idx] = '0' + (tmp + ip1) % 10;
                    ip1 = (tmp + ip1) / 10;
                    idx++;
                }
            }
        }
        // reverse the result string
        string xres = string(res.rbegin(), res.rend());
        while(xres.size() > 1 && xres[0]=='0'){
            xres.erase(0,1);
        }
        return xres;
    }
};
