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
