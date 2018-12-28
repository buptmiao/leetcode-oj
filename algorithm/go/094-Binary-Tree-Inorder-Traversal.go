/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
 */

func inorderTraversal(root *TreeNode) []int {
	res := make([]int, 0, 10)
	recursive(&res, root)
	return res
}

func recursive(arr *[]int, root *TreeNode) {
	if root != nil {
		recursive(arr, root.Left)
		*arr = append(*arr, root.Val)
		recursive(arr, root.Right)
	}
}

