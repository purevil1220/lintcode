ass Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        if(nums.empty()) return 0;
        
        int n=nums.size();
        int ret = nums[0];
        int cur = nums[0];
        
        for (int i=1; i<n; i++) {
            if(cur>0) cur=nums[i];
            else cur+=nums[i];
            ret=min(cur, ret);
        }
        
        return ret;
        
    }
};


