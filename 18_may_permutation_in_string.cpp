class Solution {
public:
    
    bool isSame(vector<int> &f1, vector<int> &f2){
        for(int i=0;i<26;i++)
            if(f1[i]!=f2[i])
                return false;
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26,0), f2(26,0);
        int l1 = s1.size();
        int l2 = s2.size();
        if(l1>l2)
            return false;
        for(auto i:s1){
            f1[i-'a']++;
        }
        for(int i=0;i<l1;i++){
            f2[s2[i]-'a']++;
        }
        if(isSame(f1,f2))
            return true;
        for(int i=0;i<l2-l1;i++){
            f2[s2[i]-'a']--;
            f2[s2[i+l1]-'a']++;
            if(isSame(f1,f2))
                return true;
        }
        return false;
    }
};
