/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 */
func exist(board [][]byte, word string) bool {
	rows := len(board)
	cols := len(board[0])
	wordbytes := []byte(word)
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if (backtrace(board, wordbytes, i, j, rows, cols, 0)) {
				return true
			}
		}
	}
	return false
}

func backtrace(board [][]byte, word []byte, i, j, rows, cols, k int) bool {
	if k == len(word) {
		return true
	}
	if i < 0 || i >= rows || j < 0 || j >= cols {
		return false
	}
	if board[i][j] == word[k] {
		c := board[i][j]
		board[i][j] = 0
		if backtrace(board, word, i + 1, j, rows, cols, k + 1) ||
		backtrace(board, word, i - 1, j, rows, cols, k + 1) ||
		backtrace(board, word, i, j + 1, rows, cols, k + 1) ||
		backtrace(board, word, i, j - 1, rows, cols, k + 1) {
			return true
		}
		board[i][j] = c
	}
	return false
}
