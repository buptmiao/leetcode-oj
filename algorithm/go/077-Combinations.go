/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

func combine(n int, k int) [][]int {
	res := make([][]int, 0, n)
	can := make([]int, k)
	backtrace(&res, &can, 0, n, k, 1)
	return res
}

func backtrace(res *[][]int, can *[]int, cur int, n, k int, little int) {
	if cur == k {
		*res = append(*res, append([]int {}, (*can)...))
		return
	}
	for i := little; i <= n; i++ {
		(*can)[cur] = i
		backtrace(res, can, cur + 1, n, k, i + 1)
		(*can)[cur] = 0
	}
}
