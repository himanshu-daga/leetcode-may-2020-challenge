class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        
        for(int i=1;i<m;i++)
            matrix[i][0] += matrix[i-1][0];
        for(int i=1;i<n;i++)
            matrix[0][i] += matrix[0][i-1];
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
            }
        }
        
        int cnt  = 0;
        int max = (m>n)?n:m;
        int sq_sum = 0;
        int curr_sum = 0;
        
        for(int s=max; s>0;s--){
            sq_sum = s*s;
            for(int i=s-1;i<m;i++){
                for(int j=s-1;j<n;j++){
                    curr_sum = matrix[i][j];
                    if(i-s>=0)
                        curr_sum -= matrix[i-s][j];
                    if(j-s>=0)
                        curr_sum -= matrix[i][j-s];
                    if((i-s>=0)&&(j-s>=0))
                        curr_sum += matrix[i-s][j-s];
                    if(curr_sum == sq_sum)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};
