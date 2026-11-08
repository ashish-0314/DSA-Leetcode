class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ColCnt(n,0);
        vector<int> RowCnt(m,0);

        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col]==1){
                    ColCnt[col]+=1;
                    RowCnt[row]+=1;
                }
            }
        }

        int res = 0 ;

        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col]==1 && (RowCnt[row]>1 || ColCnt[col]>1)) res++;
            }
        }
        return res;
    }
};