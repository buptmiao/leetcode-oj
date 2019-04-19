/**
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 */
func generate(numRows int) [][]int {
	res := make([][]int, 0, numRows)
	for i := 1; i <= numRows; i++ {
		row := make([]int, i)
		for j := 0; j < i; j++ {
			row[j] = 1
			if j != 0 && j != i-1 {
				row[j] = res[i-2][j-1] + res[i-2][j]
			}
		}
		res = append(res, row)
	}
	return res
}
