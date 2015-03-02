// modified
class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int n=A.size();
        if(n<=1) return 0;
        
        int step=0;
        int s=0;
        int e=0;
        while(s<=e) {
            step++;
            int reach=e;
            for(int i=s; i<=e; i++) {
                if(A[i]+i>=n-1) return step;
                reach = max(reach, A[i]+i);
            }
            s=e+1;
            e=reach;
        }
        
        return -1;
        
    }
};


class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int n=A.size();
        if(n<=1) return 0;
        int step=0;
        
        int start=0;
        int end=0;
        while(true) {
            step++;
            int maxReach=INT_MIN;
            for(int i=start; i<=end; i++)
                maxReach=max(maxReach, i+A[i]);
            if(maxReach>=n-1) return step;
            if(maxReach<=end) return -1;
            start=end+1;
            end=min(maxReach, n-1);
        }
        
    }
};
