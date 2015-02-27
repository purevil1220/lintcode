ass Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermuation(vector<int> &nums) {
        // write your code here
        int n=nums.size();
        if(n<=1) return nums;
        
        int cut=n-1;
        while (cut>0 && nums[cut-1]>=nums[cut]) cut--;
        
        if(cut>0) {
            //find last j>=cut st nums[j]>=nums[cut-1]
            int toswap = helper(nums, cut, n-1, nums[cut-1]);
            swap(nums[cut-1], nums[toswap]);
        }
        reverse(nums.begin()+cut, nums.end());
        
        return nums;
         
    }
    
    int helper(vector<int> &nums, int l, int r, int p) {
        while(l<r) {
            int m=l+(r-l)/2;
            if(nums[m]>=p && m==l) {
                if(nums[r]>p) l=r;
                break;
            }
            else if(nums[m]>=p) l=m;
            else r=m-1;
        }
        
        return l;
    }
};
