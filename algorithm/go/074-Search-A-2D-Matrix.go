/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
 */

func searchMatrix(matrix [][]int, target int) bool {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return false
	}
	rows, cols := len(matrix), len(matrix[0])
	left, right := 0, rows * cols - 1
	for left + 1 < right {
		mid := left + (right - left) >> 1
		midNum := matrix[mid / cols][mid % cols]
		if target <= midNum {
			right = mid
		} else {
			left = mid + 1
		}
	}
	leftNum := matrix[left / cols][left % cols]
	rightNum := matrix[right / cols][right % cols]
	return leftNum == target || rightNum == target
}
