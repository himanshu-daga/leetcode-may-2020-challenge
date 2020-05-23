class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int la = A.size();
        int lb = B.size();
        vector<vector<int>> ans;
        vector<int> t(2,0);
        int i=0,j=0,ax,ay,bx,by;
        
        while(i<la && j<lb){
            ax = A[i][0];
            ay = A[i][1];
            bx = B[j][0];
            by = B[j][1];
            
            if(ax>=bx && ax<=by){
                t[0] = ax;
                if(ay<=by){
                    t[1] = ay;
                    i++;
                }
                else{
                    t[1] = by;
                    j++;
                }
                ans.push_back(t);
            }
            else if(bx>=ax && bx<=ay){
                t[0] = bx;
                if(ay<=by){
                    t[1] = ay;
                    i++;
                }
                else{
                    t[1] = by;
                    j++;
                }
                ans.push_back(t);
            }
            else if(ay<bx)
                i++;
            else if(by<ax)
                j++;
        }
        return ans;
    }
};
