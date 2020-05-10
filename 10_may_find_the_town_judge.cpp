class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        vector<vector<int> > army( N , vector<int> (N, 0));
        int l = trust.size();
        
        for(int i=0;i<l;i++){
            int r = trust[i][1]-1;
            int c = trust[i][0]-1;
            army[r][c] = 1;
        }
        // printf("%d,%d,%d,%d,",army[0][0],army[0][1],army[1][0],army[1][1]);
        int j,k,cont;
        for(int i=0; i<N;i++){
            cont =1;
            for(j=0;j<N;j++)
                if((army[i][j]==0)&&(i!=j))
                    {cont=0;break;}
            if((j==N)&&(cont==1))
                for(k=0;k<N;k++)
                    if((army[k][i]==1)&&(i!=k))
                        {cont=0;break;}
            if((k==N)&&(cont==1))
                return i+1;
                    
        }
        
        return -1;
    }
};
