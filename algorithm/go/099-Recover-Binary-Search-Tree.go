/**
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
 */
func recoverTree(root *TreeNode) {
	var big, little, prev *TreeNode
	findTheBigNode(root, &prev, &big, &little)
	if big != nil && little != nil {
		big.Val, little.Val = little.Val, big.Val
	}
}

func findTheBigNode(root *TreeNode, prev **TreeNode, big, little **TreeNode) {
	if root != nil {
		findTheBigNode(root.Left, prev, big, little)
		if *prev != nil && (*prev).Val > root.Val {
			if *big == nil {
				*big = *prev
			}
			*little = root
		}
		*prev = root
		findTheBigNode(root.Right, prev, big, little)
	}
}


