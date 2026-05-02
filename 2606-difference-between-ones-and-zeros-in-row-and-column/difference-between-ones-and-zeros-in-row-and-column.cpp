class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> orow(n,0), oc(m,0);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]==1){
                    orow[i]++;
                    oc[j]++;
                }
            }
        }
        vector<vector<int>> diff(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                diff[i][j] = 2*orow[i] + 2*oc[j] - n - m;
            }
        }
        return diff;
    }
};