ass Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int n=nums.size();
        if(n<=1) return INT_MIN;
        
        vector<int> helper(n,0);
        int curmax;
        int maxsofar=INT_MIN;
        
        for(int i=0; i<n; i++) {
            if(i==0||curmax<=0) curmax=nums[i];
            else curmax+=nums[i];
            
            maxsofar=max(maxsofar, curmax);
            helper[i]=maxsofar;
        }
        
        maxsofar=INT_MIN;
        int ans=INT_MIN;
        for(int i=n-1; i>0; i--) {
            if(i==n-1||curmax<=0) curmax=nums[i];
            else curmax+=nums[i];
            
            maxsofar=max(maxsofar, curmax);
            ans = max(ans, maxsofar+helper[i-1]);
        }
        
        return ans;
    }
};
