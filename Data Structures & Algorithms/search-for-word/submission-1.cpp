class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& target, int row, int col, int idx) {
        if(idx == target.size()) return true;

        int totalRow = board.size();
        int totalCol = board[0].size(); 

        if(row > totalRow-1 || col > totalCol-1 || row < 0 || col < 0) return false;
        if(board[row][col] != target[idx]) return false;
        if(board[row][col] == '#') return false;

        char ch = board[row][col];
        board[row][col] = '#';
        
        bool isExist = dfs(board, target, row - 1, col, idx+1) // up
        || dfs(board, target, row + 1, col, idx+1) // down
        || dfs(board, target, row, col - 1, idx+1) // left
        || dfs(board, target, row, col + 1, idx+1); // right
        
        board[row][col] = ch;

        return isExist;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                bool exist = dfs(board, word, i, j, 0);
                if(exist) return true;
            }
        }

        return false;
    }
};