/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> can(n,string(n,'.'));
		backtracting(res,can,n,0);
        return res;
    }
    void backtracting(vector<vector<string> > &res ,vector<string> &can,int n,int row){ 
    	if(row == n)
    		res.push_back(can);
    	else{ 
    		for(int j = 0;j < n;j++){ 
    			int i;
    			for(i = 0;i<row;i++)
    				if(can[i][j] == 'Q' ||  //所在列包含Q
    				(j+i+1 < n && can[row-i-1][j+i+1] == 'Q') ||  //右上斜线上包含Q
    				(j-i-1 >= 0&& can[row-i-1][j-i-1] == 'Q')) //左上斜线上包含Q
    					break;
    				if(i == row){ 
    					can[row][j] = 'Q';
    					backtracting(res,can,n,row+1);
    					can[row][j] = '.';
    				}
    		}
    	}
    }
};