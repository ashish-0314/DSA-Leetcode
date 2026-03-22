class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> res;
        for(int b = 0 ; b < n ; b++){
            int r = 0 ;
            int c = b ;
            bool cap = false;
            while(r<m && c<n){
                if(grid[r][c] ==1){
                    if(c== n-1 || grid[r][c+1] == -1){
                        cap = true;
                        break;
                    }
                    c++;
                }
                else{
                    if(c==0 || grid[r][c-1] == 1){
                        cap = true;
                        break;
                    }
                    c--;
                }
                r++;
            }
            if(cap==true) res.push_back(-1);
            else res.push_back(c);
        }
        return res;
    }
};