/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */

func subsets(nums []int) [][]int {
	subsetNum := int(math.Pow(float64(2), float64(len(nums))))
	res := make([][]int, subsetNum)
	for i, v := range nums {
		for j := 0; j < subsetNum; j++ {
			if j >> uint(i) & 1 == 1 {
				res[j] = append(res[j], v)
			}
		}
	}
	return res
}
