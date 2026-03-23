class Solution {
public:
    typedef long long ll;
    int m , n;
    int mod = 1e9+7;
    vector<vector<pair<ll,ll>>> t ;
    pair<ll,ll> solve(int i , int j , vector<vector<int>>& grid){
        if(i==m-1 && j == n-1) return {grid[i][j] , grid[i][j]};
        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;
        if(t[i][j] != make_pair(LLONG_MIN,LLONG_MAX)) return t[i][j];
        if(i+1 <m){
            auto [dmax , dmin] = solve(i+1 , j , grid);
            maxVal = max({maxVal , grid[i][j]*dmax , grid[i][j]*dmin});
            minVal = min({minVal , grid[i][j]*dmax , grid[i][j]*dmin});
        }

        if(j+1<n){
            auto [rmax , rmin] = solve(i,j+1, grid);
            maxVal = max({maxVal , grid[i][j]*rmax , grid[i][j]*rmin});
            minVal = min({minVal , grid[i][j]*rmax , grid[i][j]*rmin});
        }
        return t[i][j] = {maxVal, minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        t = vector<vector<pair<ll,ll>>> (m , vector<pair<ll,ll>> (n , {LLONG_MIN,LLONG_MAX}));
        auto [maxi, mini] = solve(0,0,grid);
        if(maxi<0) return -1;
        else return maxi%mod;

    }
};