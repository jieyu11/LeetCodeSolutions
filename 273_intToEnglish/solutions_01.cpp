class Solution {
public:
    string numHundred(int num, map<int, string> & itoword){
        int idig = 2;
        string result = "";
        int i0 = num % 10;
        int i2 = num / 100;
        int i1 = num % 100 - i0;
        int i01 = num % 100;
        if(i2>0) result = itoword[i2] + " Hundred";
        // separated cases from 11 to 20! (or 19)
        if(i01>=11&& i01<=20){
            if(result != "") result += " ";
            result += itoword[i01];
        }else{
            if(i1>0){
                if(result != "") result += " ";
                result += itoword[i1];
            }
            if(i0>0){
                if(result != "") result += " ";
                result += itoword[i0];
            }
        }
        return result;
    }
    string numberToWords(int num) {
        //num = 12345;
        if(num==0) return "Zero";
        map<int, string> itoword{
            {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
            {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"},
            {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"},
            {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"},
            {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"},
            {80, "Eighty"}, {90, "Ninety"}
        };
        
        const int thousand = 1000;
        const int million = thousand * thousand;
        const int billion = thousand * million;
        
        int n9 = num / billion;
        num = num % billion;
        int n6 = num / million;
        num = num % million;
        int n3 = num / thousand;
        num = num % thousand;
        string result = "";
        if(n9>=10) return result;
        if(n9 > 0) result = itoword[n9] + " Billion";
        if(n6 > 0){
            if(result != "") result += " ";
            result += numHundred(n6, itoword) + " Million";
        }
        if(n3 > 0){
            if(result != "") result += " ";
            result += numHundred(n3, itoword) + " Thousand";
        }
        if(num > 0){
            if(result != "") result += " ";
            result += numHundred(num, itoword);
        }
        return result;
    }
};
