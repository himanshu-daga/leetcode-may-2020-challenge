class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int la = A.size();
        int lb = B.size();
        
        vector<vector<int>> M(lb+1, vector<int> (la+1,0));
        for(int i=1;i<=lb;i++){
            for(int j=1;j<=la;j++){
                M[i][j] = (A[j-1]==B[i-1])?M[i-1][j-1]+1:max(M[i-1][j],M[i][j-1]);
            }
        }
        
        return M[lb][la];
    }
};
