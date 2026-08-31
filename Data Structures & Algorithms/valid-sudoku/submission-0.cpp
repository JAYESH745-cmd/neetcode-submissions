class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //for rows and columns
        for(int i=0;i<9;i++){
            map<char,int> row;
            map<char,int> col;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.') row[board[i][j]]++;
                if(board[j][i]!='.') col[board[j][i]]++;
            }
            for(auto i:row){
                if(i.second>1) return false;
            }
            for(auto i:col){
                if(i.second>1) return false;
            }
        }
        // for(int i   )
        return true;
        
    }
};
