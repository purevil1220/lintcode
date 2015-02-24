ass Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int n=nums.size();
        if(n<=2&&n>0) return nums[0];
        
        int i1=0;
        int c1=0;
        int i2=0;
        int c2=0;
        for(auto n:nums) {
            if(c1!=0 && n==i1) c1++;
            else if(c2!=0 && n==i2) c2++;
            else if(c1==0) {
                i1=n;
                c1++;
            } else if(c2==0) {
                i2=n;
                c2++;
            } else {
                c1--;
                c2--;
            }
        }
        
        c1=0; c2=0;
        for (auto n:nums) {
            if(n==i1)c1++;
            if(n==i2)c2++;
        }
        
        if(c1>c2) return i1;
        else return i2;
        
    }
};
