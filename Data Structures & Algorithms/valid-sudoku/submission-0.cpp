class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int a=0; a<9; a++){
            unordered_set<char> rowCheck;
            unordered_set<char> colCheck;
            unordered_set<char> blockCheck;
            for(int b=0; b<9; b++){
                int r = board[a][b];
                int c = board[b][a];
                int bl = board[3*(a/3) + b/3][3*(a%3) + b%3];
                if(rowCheck.count(r)>0 || colCheck.count(c)>0 || blockCheck.count(bl)>0){
                    return false;
                }
                if(r != '.') rowCheck.insert(r);
                if(c != '.') colCheck.insert(c);
                if(bl!= '.') blockCheck.insert(bl);
            }
        }
        return true;
    }
};
