/**
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
 */
func getRow(numRows int) []int {
	res := make([]int, numRows + 1)
	for i := 1; i <= numRows + 1; i++ {
		for j := i - 1; j >= 0; j-- {
			if j != 0 && j != i - 1 {
				res[j] = res[j] + res[j - 1]
			} else {
				res[j] = 1
			}
		}
	}
	return res
}
