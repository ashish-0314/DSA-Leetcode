class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res (m-k+1 , vector<int>(n-k+1));
        for(int i = 0 ; i <= m- k ; i++){
            for(int j = 0 ; j <= n-k ; j++){
                set<int> val ;
                for(int a = i ; a <= i+k-1 ; a++){
                    for(int b = j ; b <= j+k-1 ; b++){
                        val.insert(grid[a][b]);
                    }
                }
                if(val.size()==1){
                    res[i][j]=0;
                    continue;
                }
                int mini = 1e9;
                auto prev = val.begin();
                auto curr = next(prev);
                while(curr != val.end()){
                    mini = min(mini,abs(*curr - *prev));
                    prev= curr;
                    curr++;
                }
                res[i][j] = mini ;
            }
        }
        return res;
    }
};