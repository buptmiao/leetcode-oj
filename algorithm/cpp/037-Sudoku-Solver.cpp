/*

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

*/

class Solution{ 
public:
	void solveSudoku(vector<vector<char> > &board){ 
		int blanknum = 0;
		map<int,char> bit2char;
		vector<int> row(9,0x01FF);
		vector<int> col(9,0x01FF);
		vector<int> cell(9,0x01FF);
		vector<pair<int,int> > blank;
		for(char k = '1';k<='9';k++)
			bit2char[1<<(k-'1')] = k;
		for(int m = 0;m < 9;m++)
			for(int n = 0;n<9;n++){ 
				if(board[m][n] != '.'){ 
					int k = 1 << (board[m][n] - '1');
					row[m] &= ~k;
					col[n] &= ~k;
					cell[m/3*3+n/3] &= ~k;
				}
				else
					blank.push_back(pair<int,int>(m,n));
			}
		backtracting(board,blank,0,row,col,cell,bit2char);
	}
	bool backtracting(vector<vector<char> > &board,vector<pair<int,int> > &blank,int num,vector<int> &row,vector<int> &col,vector<int> &cell,map<int,char> &bit2char){ 
		if(num == blank.size())
			return true;
		auto m = blank[num].first;
		auto n = blank[num].second;
		auto index = m/3*3+n/3;
		auto pos = row[m] & col[n] & cell[index];
		while(pos){ 
			int p = pos & (-pos);  // 二进制位的末位
			pos = pos - p;         // 置零末位的1
			board[m][n] = bit2char[p]; //试探的填一个
			row[m] &= ~p;
			col[n] &= ~p;
			cell[index] &= ~p;
			if(backtracting(board,blank,num+1,row,col,cell,bit2char))
				return true;
			row[m] |= p;
			col[n] |= p;
			cell[index]|=p;
		}
		return false;
	}
};