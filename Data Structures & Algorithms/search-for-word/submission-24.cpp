class Solution {
public:
    int visited[10][10];
    
    bool dfs(int row, int col, int n, int m, int i, vector<vector<char>>& board, string& word){
        if(row<0 || col<0 || row>n-1 || col>m-1 
        || board[row][col] != word[i] || visited[row][col]) return false;
        if(i == word.size() - 1) return true;
        visited[row][col] = 1;
        bool res =   dfs(row+1,col,n,m,i+1,board,word)
            ||       dfs(row-1,col,n,m,i+1,board,word)
            ||       dfs(row,col+1,n,m,i+1,board,word)
            ||       dfs(row,col-1,n,m,i+1,board,word);
        visited[row][col] = 0;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(dfs(row, col, n, m, 0, board, word)) return true;
            }
        }
        return false;
    }
};
