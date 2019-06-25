class Solution {
public:
    void mergeSorted(const vector<int> & s1,const int & n1, const vector<int> & s2, const int & n2, vector<int> & merged){
        merged.clear();
        int i1 = 0, i2 = 0;
        while(i1<n1 && i2<n2){
            if(s1[i1]<s2[i2]){merged.push_back(s1[i1]); i1++;}
            else {merged.push_back(s2[i2]); i2++;}
        }
        while(i1<n1){merged.push_back(s1[i1]); i1++;}
        while(i2<n2){merged.push_back(s2[i2]); i2++;}
    }
    int reversePairsSub(vector<int>& nums, vector<int> & sortednum, int i, int j){
        if(i>j) return 0;
        if(i==j){ sortednum.push_back(nums[i]); return 0;}
        //if(i+1==j){ return long(nums[i]) > 2*long(nums[j]) ? 1 : 0;}
        int m = i + (j-i)/2;
        vector<int> s1, s2;
        int res = reversePairsSub(nums, s1, i, m);
        //cout<<"A "<<i<<" - "<<m<<": "<<res<<endl;
        res += reversePairsSub(nums, s2, m+1, j);
        //cout<<"B "<<m+1<<" - "<<j<<": "<<res<<endl;
        // count the number of pairs across the two sub-array:
        int i1 = 0, n1 = s1.size(), i2 = 0, n2 = s2.size();
        while( i1 < n1 && i2 < n2 ){
            if(long(s1[i1]) > 2 *long(s2[i2]) ){ res += (n1-i1); i2++; }
            else i1++;
        }
        // do the merge sort, update: sortednum
        mergeSorted(s1, n1, s2, n2, sortednum);
        return res;
    }
    int reversePairs(vector<int>& nums) {
        //nums = {2,4,3,5,1};
        int n = nums.size();
        if(n<=1) return 0;
        vector<int> sortednum;
        return reversePairsSub(nums, sortednum, 0, n-1);
    }
};
