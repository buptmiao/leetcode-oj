/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i = 0;i<9;i++){  //cols and rows
			map<char,int> cmap1,cmap2;
			for(int j = 0;j<9;j++){
				char c = board[i][j];
				if(c >='1' && c<='9' && cmap1.find(c) == cmap1.end())
					cmap1[c]++;
				else if(c != '.')
					return false;
				c = board[j][i];
				if(c >='1' && c<='9' && cmap2.find(c) == cmap2.end())
					cmap2[c]++;
				else if(c != '.')
					return false;
			}
		}
		for(int i= 0;i<9;i+=3)  //九宫格
			for(int j=0;j<9;j+=3){
				map<char,int> cmap;
				for(int m = i;m < i+3;m++)
					for(int n = j;n < j+3;n++)
					{
						char c = board[m][n];
						if(c >='1' && c<='9' && cmap.find(c) == cmap.end())
							cmap[c]++;
						else if(c != '.')
							return false;
					}
			}
		return true;
    }
};