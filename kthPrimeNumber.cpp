ass Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        if (k<=0) return 1;
        vector<long long> vec;
        vec.push_back(1);
        int p3=0, p5=0, p7=0;
        
        for (int i=0; i<k; i++) {
            long long x=min(vec[p3]*3, min(vec[p5]*5, vec[p7]*7));
            vec.push_back(x);
            
            if(x/3==vec[p3]) p3++;
            if(x/5==vec[p5]) p5++;
            if(x/7==vec[p7]) p7++;
        }
        
        return vec[k];
    }
};
