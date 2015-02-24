ass Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int n=nums.size();
        if(n==1) return nums[0];
        
        int m_index=0;
        int count=1;
        
        for (int i=1; i<n; i++) {
            if(nums[i]==nums[m_index]) count++;
            else count--;
            
            if(count==0) {
                m_index=i;
                count=1;
            }
        }
        
        return nums[m_index];
    }
};
