#include "dsa/dsa.hpp"
using namespace std;

class Solution {
   private:
    bool backtrack(vector<vector<char>>& board, string word, int r, int c, int x, int y, int idx) {

        if (idx == word.size()) return true;
        if (x >= r || y >= c || x < 0 || y < 0) return false;
        if (board[x][y] == '#') return false;
        if (word[idx] != board[x][y]) return false;

        char temp = board[x][y];
        board[x][y] = '#';

        bool found = backtrack(board, word, r, c, x + 1, y, idx + 1) ||
                     backtrack(board, word, r, c, x - 1, y, idx + 1) ||
                     backtrack(board, word, r, c, x, y + 1, idx + 1) ||
                     backtrack(board, word, r, c, x, y - 1, idx + 1);

        board[x][y] = temp;

        return found;
    }

   public:
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == word[0] && backtrack(board, word, r, c, i, j, 0)) return true;
            }
        }
        return false;
    }
};

int main() { return 0; }
