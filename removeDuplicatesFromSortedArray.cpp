ass Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int n=nums.size();
        if(n<=1) return n;
        
        int p1=1;
        for (int p2=1; p2<n; p2++) {
            if(nums[p2]!=nums[p2-1]) nums[p1++] = nums[p2];
        }
        
        return p1;
    }
};


