class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> sumx(n, vector<int> (m,0));
        vector<vector<int>> sumy(n, vector<int> (m,0));
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                sumx[i][j] = (grid[i][j]=='X');
                sumy[i][j] = (grid[i][j]=='Y');

                if(i-1>=0){
                    sumx[i][j] += sumx[i-1][j];
                    sumy[i][j] += sumy[i-1][j];
                }

                if(j-1>=0){
                    sumx[i][j] +=sumx[i][j-1];
                    sumy[i][j] +=sumy[i][j-1];
                }

                if(i-1>=0 && j-1>=0){
                sumx[i][j] -=sumx[i-1][j-1];
                sumy[i][j] -=sumy[i-1][j-1];
                }

                if(sumx[i][j]==sumy[i][j] && sumx[i][j]>0) cnt++;

            }
        }
        return cnt;
    }
};