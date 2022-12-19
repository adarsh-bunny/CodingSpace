class Solution {
public:
     bool isSafeInBoard(vector<vector<char>>& board,int row,int col,int num)
     {
       int rowFactor= row-(row%3);
       int colFactor= col-(col%3);
       for(int i=0;i<3;i++)
       {
           for(int j=0;j<3;j++)
           {
              if(board[i+rowFactor][j+colFactor]== num+'0')
                return false;
           }
       }
         
         return true;
     }
    
        bool isSafeInCol(vector<vector<char>>& board,int col,int num)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]== num+'0')
                return false;
        }
        return true;
    }
    bool isSafeInRow(vector<vector<char>>& board,int row,int num)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]== num+'0')
                return false;
        }
        return true;
    }
    bool isSafe(vector<vector<char>>& board,int row,int col,int num)
    {
        if(isSafeInRow( board, row, num) && isSafeInCol( board, col, num) &&isSafeInBoard( board, row,col, num))
            return true;
        
        return false;
    }
    bool findEmptyLoc(vector<vector<char>>& board,int &row,int &col)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    row=i;
                    col=j;
                    return true;
                }
            }
        }
        return false;
        
    }
    bool solveSudoku(vector<vector<char>>& board) {
        int row ,col;
        if(!findEmptyLoc(board,row,col))
            return true;
        
        for(int i=1;i<=9;i++)
        {
          if(isSafe(board,row,col,i))
             {
               
                 board[row][col]= i+'0';
                 if(solveSudoku(board))
                     return true;
                 board[row][col]= '.';
                 
             } 
        }  
         return false;
                  
    }
             
};