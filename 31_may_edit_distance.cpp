class Solution {
public:
    int minDistance(string w1, string w2) {
        int n1 = w1.size();
        int n2 = w2.size();
        if(n1==0 || n2==0)
            return max(n1,n2);
        
        vector<vector<int>> D(n1,vector<int>(n2,0));
        
        D[0][0] = (w1[0]==w2[0])? 0:1;
        
        for(int i=1;i<n1;i++)
            D[i][0] = (w1[i]==w2[0])? i : D[i-1][0]+1;
        for(int j=1;j<n2;j++)
            D[0][j] = (w1[0]==w2[j])? j : D[0][j-1]+1;
        
        for(int i=1;i<n2;i++)
            cout<< D[0][0]<<" ";
        
        for(int i=1;i<n1;i++){
            for(int j=1;j<n2;j++){
                if(w1[i]==w2[j])
                    D[i][j] = D[i-1][j-1];
                else
                    D[i][j] = min(min(D[i-1][j],D[i][j-1]), D[i-1][j-1])+1;
                // cout<<D[i][j]<<" "<<i<<" "<<j<<" "<<D[i-1][j-1]<<" "<<D[i-1][j]<<" "<<D[i][j-1]<<endl;
            }
            // cout<<endl;
        }
        return D[n1-1][n2-1];
    }
};
