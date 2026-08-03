class Solution {
private:
    bool checkQueen(int row, int col, vector<string> &board, int n) {
        int tr = row;
        int tc = col;

        // check col
        while (tr >= 0) {
            if (board[tr][tc] == 'Q') return false;
            tr--;
        }

        // check left up diag
        tr = row;
        tc = col;
        while (tr >= 0 && tc >= 0) {
            if (board[tr][tc] == 'Q') return false;
            tr--;
            tc--;
        }

        // check right up diag
        tr = row;
        tc = col;
        while (tr >= 0 && tc < n) {
            if (board[tr][tc] == 'Q') return false;
            tr--;
            tc++;
        }

        return true;

    }
    void backtrack(vector<vector<string>> &res, vector<string> &board, int row, int n) {
        if (row == n) {
            res.emplace_back(board);
            return;
        }
        for (int  i  = 0; i < n; i++) {
            if (!checkQueen(row, i, board, n)) continue;
            board[row][i] = 'Q';
            backtrack(res, board, row + 1, n);
            board[row][i] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n,'.'));
        backtrack(res, board, 0, n);
        return res;
    }
};
