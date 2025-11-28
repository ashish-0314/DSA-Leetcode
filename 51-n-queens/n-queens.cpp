// class Solution {
// public:
//     bool(int row , int col , int n , vector<strings>& board ){
//         for(int j = 0 ; j< n ; j++) if(board[row][j]=='Q') return false;
//         for(int i = 0 ;i< n ; i++) if(board[i][col]=='Q') return false;
//     }

//     void solve(int row , int n , vector<strings>& board , vector<vector<string>>& ans){
//         if(row==n){ans.push_back(board); return ;}
//         for(int j = 0 ; j<n ; j++){
//             if(isSafe(row,j,n,board)){
//                 board[row][j]='Q';
//                 solve(row+1,n,board,ans);
//                 board[row][j]='.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n,string(n,'.'));
//         solve(0,n,board,ans);
//         return ans;
//     }
// };





// class Solution {
// public:
//     bool isSafe(int row, int col, int n, vector<string>& board) {
//         for (int j = 0; j < n; j++)  if (board[row][j] == 'Q') return false;
//         for (int i = 0; i < n; i++) if (board[i][col] == 'Q') return false;
//         int r = row, c = col;
//         for (int r = row, c = col; r-- >= 0 && c-- >= 0; ) if (board[r][c] == 'Q') return false;
//         for (int r = row, c = col; r-- >= 0 && c++ < n; ) if (board[r][c] == 'Q') return false;
//         return true;
//     }

//     void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans) {
//         if (row == n) {ans.push_back(board); return; }
//         for (int j = 0; j < n; j++) {
//             if (isSafe(row, j, n, board)) {
//                 board[row][j] = 'Q';
//                 solve(row + 1, n, board, ans);
//                 board[row][j] = '.';
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n, string(n, '.'));
//         solve(0, n, board, ans);
//         return ans;
//     }
// };



class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string>& board) {
        for (int j = 0; j < n; j++)
            if (board[row][j] == 'Q') return false;

        for (int i = 0; i < n; i++)
            if (board[i][col] == 'Q') return false;

        int r = row, c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--; c--;
        }

        r = row; c = col;
        while (r >= 0 && c < n) {
            if (board[r][c] == 'Q') return false;
            r--; c++;
        }

        return true;
    }

    void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (isSafe(row, j, n, board)) {
                board[row][j] = 'Q';
                solve(row + 1, n, board, ans);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, n, board, ans);
        return ans;
    }
};
