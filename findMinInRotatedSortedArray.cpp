ass Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int n = num.size();
        int l=0;
        int r=n-1;

        while(l<r) {
            int m=(l+r)/2;
            if(num[m]>num[r]) l=m+1;
            else if(num[m]<num[r]) r=m;
            else {
                if(num[m]<num[l]) r=m;
                else if(num[m]>num[l]) return num[l];
                else l++;
            }
        }
        
        return num[l];
    }
};


