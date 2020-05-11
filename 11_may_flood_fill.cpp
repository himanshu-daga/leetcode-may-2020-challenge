class Solution {
public:
    
    void update(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor, int R, int C) {
        // printf("%d %d", sr, sc);
        
        if(newColor == oldColor)
            return;
        
        if((sr<R) && (sc<C) && (sr>=0) && (sc>=0) && (image[sr][sc]==oldColor)){
            image[sr][sc] = newColor;
            update(image, sr+1, sc, oldColor, newColor, R, C);
            update(image, sr-1, sc, oldColor, newColor, R, C);
            update(image, sr, sc+1, oldColor, newColor, R, C);
            update(image, sr, sc-1, oldColor, newColor, R, C);
        }
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        int R = image.size();
        int C = image[0].size();
        
        // printf("%d %d", R, C);
        
        
        update(image, sr, sc, oldColor, newColor, R, C);
        
        return image;
    }
};
