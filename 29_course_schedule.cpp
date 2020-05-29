class Solution {
public:
    
    bool cyclePresent(vector<int> graph[], int i, vector<int> &vis){
        if(vis[i]==1)
            return true;
        if(vis[i]==0){
            vis[i] = 1;
            for(auto j: graph[i])
                if(cyclePresent(graph,j,vis))
                    return true;
        }
        vis[i] = 2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& edges) {
        // make adjacency list
        vector<int> graph[numCourses];
        for(auto edge:edges)
            graph[edge[1]].push_back(edge[0]);
        
        // keep track of a node- not visited, visited
        vector<int> vis(numCourses,0);
        
        // start with each edge and see if cycle present or not
        for(int i=0;i<numCourses;i++)
            if(cyclePresent(graph,i,vis))
                return false;
        
        return true;
        
    }
};
