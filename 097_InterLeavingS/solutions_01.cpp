class Solution {
public:
    bool check(string & s1, int i1, int n1, 
               string & s2, int i2, int n2, 
               string & s3, int i3, int n3 ){
        
        // end of s3, meaning all checked. True!
        if(i3==n3) return true;
        
        // if s1 is not to the end, check s1, if matches, continue to check
        bool ok_a = true;
        if(i1<n1){
            if(s1[i1]==s3[i3]) ok_a = check(s1, i1+1, n1, s2, i2, n2, s3, i3+1, n3);
            else               ok_a = false;
        }
        
        // if s2 is not to the end, check s2, if matches, continue to check
        bool ok_b = true;
        if(i2<n2){
            if(s2[i2]==s3[i3]) ok_b = check(s1, i1, n1, s2, i2+1, n2, s3, i3+1, n3);
            else               ok_b = false;
        }
        
        // if one of the string, s1 or s2 is already at the end, 
        // status decided by the other string matching
        // if both are not at the end, either matches will be true!
        if     (i1>=n1) return ok_b;
        else if(i2>=n2) return ok_a;
        else            return ok_a || ok_b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        /*
        s3 is said to be interleaving s1 and s2, if it contains all 
        characters of s1 and s2 and order of all characters in individual 
        strings is preserved.
        */
        /*
        // test:
        s1 = "aabcc";
        s2 = "dbbca";
        s3 = "aadbbcbcac"; //  return true.
        s3 = "aadbbbaccc"; // return false.
        */
        
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if(n3 != n1+n2) return false;
        if(n3 == 0    ) return true;
        
        return check(s1, 0, n1, s2, 0, n2, s3, 0, n3);
    }
};
