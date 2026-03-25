class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 
        long long tsum = 0 ;
        for(auto &row : grid){
            for(int &x : row) tsum+=x;
        }
        long long t = tsum/2;
        if(tsum%2!=0) return false;
        long long sum = 0;
        for(int i = 0 ; i < m-1 ; i++){
            for(int j = 0 ; j < n ; j++){
                sum +=grid[i][j];
            }
            if(sum==t) return true;
        }
        vector<long long> col(n,0);
        for(int j = 0 ; j < n ; j++){
            for(int i = 0 ; i < m ; i++){
                col[j]+=grid[i][j];
            }
        }
        sum = 0 ;
        for(int i = 0 ; i < n-1 ; i++){
            sum+=col[i];
            if(sum==t) return true;
        }
        return false;
    }
};