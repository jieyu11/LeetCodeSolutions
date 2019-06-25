class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(*max_element(nums.begin(), nums.end()) >= s) return 1;
        
        // for 0th
        int sum = 0, iend = -1;
        for(int i=0; i<n; i++){ 
            sum += nums[i]; 
            if( sum >= s){iend = i; break;}
        }
        if(iend < 0) return 0;
        
        int length = iend + 1;
        int minlength = length;
        for(int i=1; i<n; i++){
            //remove the previous number, reduce the length.
            sum -= nums[i-1]; length--;
            //if removing the last number would still have >= s, then remove it.
            while( sum - nums[iend] >= s){sum -= nums[iend]; length--; iend--; }
            //if the current sum is < s, try to enlong the end.
            while( sum < s && iend<n-1){ iend++; sum += nums[iend]; length++; }
            
            if(sum >= s && length < minlength) minlength = length;
        }
        return minlength;
    }
};
