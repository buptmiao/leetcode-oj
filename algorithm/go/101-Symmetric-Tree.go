/**
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
 */
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return isSymmetricBoth(root.Left, root.Right)
}

func isSymmetricBoth(left, right *TreeNode) bool {
	if left == nil || right == nil {
		return left == right
	}

	return left.Val == right.Val && isSymmetricBoth(left.Left, right.Right) && isSymmetricBoth(left.Right, right.Left)
}
