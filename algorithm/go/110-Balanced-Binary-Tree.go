/**
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
 */
func isBalanced(root *TreeNode) bool {
	_, balance := maxDeep(root)
	return balance

}

func maxDeep(root *TreeNode) (int, bool) {
	if root == nil {
		return 0, true
	}
	leftDeep, leftBalance := maxDeep(root.Left)
	rightDeep, rightBalance := maxDeep(root.Right)
	return int(math.Max(float64(leftDeep), float64(rightDeep))) + 1, leftBalance && rightBalance && (int(math.Abs(float64(leftDeep - rightDeep))) <= 1)
}
