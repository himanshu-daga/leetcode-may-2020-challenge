class Solution {
public:
    
    int sameCounts(vector<int> &pchars, vector<int> &schars){
        for(int i=0;i<26;i++)
            if(pchars[i]!=schars[i]){
                return 0;
            }
        return 1;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        int ls = s.length();
        int lp = p.length();
        if(lp>ls) 
            return v;
        vector<int> schars(26,0);
        vector<int> pchars(26,0);
        for(int i=0;i<lp;i++)
            pchars[(p[i]-'a')]++;
        for(int i=0;i<lp;i++)
            schars[(s[i]-'a')]++;
        if(sameCounts(pchars, schars))
            v.push_back(0);
        
        for(int i=1;i<=ls-lp;i++){
            schars[s[i-1]-'a']--;
            schars[s[i-1+lp]-'a']++;
            if(sameCounts(pchars, schars))
                v.push_back(i);
        }
        return v;
    }
    
    // BRUTE FORCE
    /*int check_ana(string s, string p, int i, int l){
        vector<int> v(l,0);
        int found;
        for(int j=0; j<l;j++){
            found = 0;
            for(int k=0;k<l;k++)
                if((p[j]==s[k+i]) && (v[k]!=1)){
                    found = 1;
                    v[k] = 1;
                    break;
                }
            if(found == 0)
                return 0;
        }
        return 1;
    } 
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        int ls = s.length();
        int lp = p.length();
        if(lp>ls) 
            return v; 
        for(int i=0;i<=ls-lp;i++){
            cout<< i<<" ";
            if(check_ana(s,p,i,lp))
                v.push_back(i);
        }
         return v;   
    }*/
};
