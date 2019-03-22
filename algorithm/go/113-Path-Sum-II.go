/**
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
 */
func dfs(root *TreeNode, sum int, candidate *[]int, res *[][]int) {
	if root == nil {
		return
	}
	*candidate = append(*candidate, root.Val)
	if root.Left == nil && root.Right == nil && root.Val == sum {
		*res = append(*res, append([]int{}, (*candidate)...))
	}
	dfs(root.Left, sum - root.Val, candidate, res)
	dfs(root.Right, sum - root.Val, candidate, res)
	*candidate = (*candidate)[:len(*candidate)-1]
}

func pathSum(root *TreeNode, sum int) [][]int {
	res := make([][]int, 0, 10)
	candidate := make([]int, 0, 10)
	dfs(root, sum, &candidate, &res)
	return res
}
