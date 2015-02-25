class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int, int> m;
        int n=nums.size();
        vector<int> ans;
        
        for (int i=0; i<n; i++) {
            if(m.find(nums[i])==m.end()) 
                m[target-nums[i]]=i;
            else{
                ans.push_back(m[nums[i]]+1);
                ans.push_back(i+1);
                return ans;
            } 
        }
        
        return ans;
    }
};


