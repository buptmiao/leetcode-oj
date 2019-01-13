/**
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
 */
func isValidBST(root *TreeNode) bool {
	var prev *TreeNode
	return isValidBSTPartial(root, &prev);
}

func isValidBSTPartial(root *TreeNode, prev **TreeNode) bool {
	if root == nil {
		return true
	}
	if !isValidBSTPartial(root.Left, prev) {
		return false
	}
	if *prev != nil && (*prev).Val >= root.Val {
		return false
	}
	*prev = root
	if !isValidBSTPartial(root.Right, prev) {
		return false
	}
	return true
}
