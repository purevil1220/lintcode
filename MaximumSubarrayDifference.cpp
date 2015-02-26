ass Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int n=nums.size();
        if(n<=1) return 0;
        
        vector<int> leftMax(n, 0);
        vector<int> leftMin(n, 0);
        
        int lmax=INT_MIN;
        int lmin=INT_MAX;
        int curMax;
        int curMin;
        for(int i=0; i<n; i++) {
            if(i==0||curMax<=0) curMax=nums[i];
            else curMax+=nums[i];
            lmax=max(lmax, curMax);
            
            if(i==0||curMin>=0) curMin=nums[i];
            else curMin+=nums[i];
            lmin=min(lmin, curMin);
            
            leftMax[i]=lmax;
            leftMin[i]=lmin;
        }
        
        vector<int> rightMax(n, 0);
        vector<int> rightMin(n, 0);
        
        int rmax=INT_MIN;
        int rmin=INT_MAX;
        
        for(int i=n-1; i>=0; i--) {
            if(i==n-1||curMax<=0) curMax=nums[i];
            else curMax+=nums[i];
            rmax=max(rmax, curMax);
            
            if(i==n-1||curMin>=0) curMin=nums[i];
            else curMin+=nums[i];
            rmin=min(rmin, curMin);
            
            rightMax[i]=rmax;
            rightMin[i]=rmin;
        }
        
        int ans=INT_MIN;
        for (int i=0; i<n-1; i++) {
            ans = max(ans, abs(leftMax[i]-rightMin[i+1]));
            ans = max(ans, abs(leftMin[i]-rightMax[i+1]));
        }
        return ans;
        
    }
};
