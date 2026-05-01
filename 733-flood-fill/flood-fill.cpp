class Solution {
public:
    void dfs(int sr , int sc , vector<vector<int>>& image , int color , int og){
        int n = image.size();
        int m = image[0].size();
        image[sr][sc] = color;
        int delrow[]={-1 , 0 , 1 , 0};
        int delcol[]={0 , 1 , 0 , -1};

        for(int i = 0 ; i <4 ; i++){
            int nr = sr + delrow[i];
            int nc = sc + delcol[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc]==og){
                dfs(nr,nc,image,color,og);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int og = image[sr][sc];
        if(og==color) return image;
        dfs(sr,sc,image,color,og);
        return image;
    }
};