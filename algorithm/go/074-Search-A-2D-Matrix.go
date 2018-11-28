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
	if len(matrix) == 0 {
		return false
	}
	cols := len(matrix[0])
	return findTwo(matrix, target, 0, len(matrix) * cols - 1, cols)
}

func findTwo(matrix [][]int, target, left, right, cols int) bool {
	leftNum := matrix[left / cols][left % cols]
	rightNum := matrix[right / cols][right % cols]
	mid := left + (right - left) >> 1
	midNum := matrix[mid / cols][mid % cols]

	if left + 1 >= right {
		return leftNum == target || rightNum == target
	}
	if target <= midNum {
		return findTwo(matrix, target, left, mid, cols)
	}
	return findTwo(matrix, target, mid + 1, right, cols)
}
