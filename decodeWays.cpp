class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0) return 0;
        
        int n=s.length();
        vector<int> sol(n+1,0);
        sol[0]=1;
        
        for(int i=0; i<s.length(); i++) {
            int cur=s[i]-'0';
            if(cur>0) sol[i+1] += sol[i];
            
            if(i>0) {
                cur+=(s[i-1]-'0')*10;
                if(cur>=10 && cur<=26) sol[i+1]+=sol[i-1];
            } 
        }
        
        return sol[n];
    }
};
