class Solution {
private:
    int getNext(string s, int &i) {
        int sol=0;
        int n=s.length();
        
        while(i<n) {
            if(s[i]=='.') break;
            sol=sol*10+(s[i]-'0');
            i++;
        }
        i++;
        return sol;
    }
    
public:
    int compareVersion(string version1, string version2) {
        int i1=0, i2=0;
        int n1=version1.length(), n2=version2.length();
        
        while(i1<n1||i2<n2) {
            int cur1, cur2;
            if(i1<n1) cur1 = getNext(version1, i1);
            else cur1=0;
            
            if(i2<n2) cur2 = getNext(version2, i2);
            else cur2=0; 
            
            if(cur1<cur2) return -1;
            if(cur1>cur2) return 1;
        }
        
        return 0;
    }
};
