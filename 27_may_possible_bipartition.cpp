class Solution {
public:
    
    bool colorGraph(vector<vector<int>>& graph, int idx, vector<int> &color, int col){
        color[idx] = col;
        col = (col+1)%2;    
        for(auto x:graph[idx]){
            if(color[x]==color[idx])
                return false;
            if(color[x]==-1 && !colorGraph(graph, x, color, col))
                return false;
        }
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int l = dislikes.size();
        vector<int> color(N+1,-1);
        vector<vector<int>> graph(N+1, vector<int> (0));
        
        for(int i=0;i<l;i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        int col = 0;
        
        for(int i=1;i<=N;i++){
            if(color[i]==-1 && !colorGraph(graph, i, color, col))
                    return false;
            }
        return true;
    }
};
