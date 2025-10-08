class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> row(mat.size()) , col(mat[0].size());
        for(int i = 0 ; i< row.size(); i++){
            for(int j = 0 ; j<col.size(); j++){
                if(mat[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int cnt = 0;
        for(int i = 0 ; i< mat.size() ; i++){
            for(int j = 0 ; j< mat[0].size() ; j++){
                if(mat[i][j] && row[i]==1 && col[j]==1) cnt++;
            }
        }
        return cnt;
    }
};