class Solution {
public:
    // check from both head and tail of the string s3
    bool check(string & s1, int i1, int j1, 
               string & s2, int i2, int j2, 
               string & s3, int i3, int j3 ){
        
        // end of s3, meaning all checked. True!
        if(i3>j3) return true;
        
        // if s1 is not to the end, check s1, if matches, continue to check
        bool ok = false;
        if(i1<=j1 && s1[i1]==s3[i3] && s1[j1]==s3[j3]) ok = check(s1, i1+1, j1-1, s2, i2, j2, s3, i3+1, j3-1);
        if(ok) return true;
        
        if(i2<=j2 && s2[i2]==s3[i3] && s2[j2]==s3[j3]) ok = check(s1, i1, j1, s2, i2+1, j2-1, s3, i3+1, j3-1);
        if(ok) return true;
        
        if(i1<=j1 && i2<=j2 && s2[i2]==s3[i3] && s1[j1]==s3[j3]) ok = check(s1, i1, j1-1, s2, i2+1, j2, s3, i3+1, j3-1);
        if(ok) return true;
        
        if(i1<=j1 && i2<=j2 && s1[i1]==s3[i3] && s2[j2]==s3[j3]) ok = check(s1, i1+1, j1, s2, i2, j2-1, s3, i3+1, j3-1);
        if(ok) return true;

        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        /*
        s3 is said to be interleaving s1 and s2, if it contains all 
        characters of s1 and s2 and order of all characters in individual 
        strings is preserved.
        */
        
        // test:
        /*
        s1 = "aabcc";
        s2 = "dbbca";
        s3 = "aadbbcbcac"; //  return true.
        s3 = "aadbbbaccc"; // return false.
        */
        // test 2:
        /*
        s1 = "a";
        s2 = "";
        s3 = "a"; //  return true.
        */
        
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if(n3 != n1+n2) return false;
        if(n3 == 0    ) return true;
        
        return check(s1, 0, n1 - 1, s2, 0, n2 - 1, s3, 0, n3 - 1);
    }
};
