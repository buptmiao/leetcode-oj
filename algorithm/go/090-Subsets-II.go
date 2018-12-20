/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 */
func subsetsWithDup(nums []int) [][]int {
	res := make([][]int, 0, 10)
	sort.Ints(nums)
	for i := 0; i <= len(nums); i++ {
		candidate := make([]int, i)
		backtrace(&res,nums, &candidate, 0, len(nums), i, 0)
	}
	return res
}

func backtrace(res *[][]int, nums []int, can *[]int, cur int, n int, k int, little int) {

	if cur == k {
		*res = append(*res, append([]int{}, (*can)...))
	} else {
		if little >= n {
			return
		}
		last := nums[little]
		for i := little; i < n; i++ {
			if i > little && nums[i] == last {
				continue
			}
			last = nums[i]
			(*can)[cur] = nums[i]
			backtrace(res, nums, can, cur+1, n, k, i+1)
		}
	}
}
