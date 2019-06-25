class Solution {
public:
    int findMin(vector<int>& nums) {
        //nums = {4, 5, 6, 7, 0, 1, 2};
        int n = nums.size();
        if(n==1) return nums[0];
        int ista = 0, iend = n-1;
        while(ista+1<iend){
            //cout<<ista<<" "<<iend<<endl;
            int imid = (ista + iend)/2;
            if(nums[imid] < nums[iend]){
                iend = imid;
            }else{
                ista = imid;
            }
        }
        if(nums[ista] < nums[iend]) return nums[ista];
        else return nums[iend];
    }
};
