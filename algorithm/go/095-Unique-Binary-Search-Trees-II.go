/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */
func generateTrees(n int) []*TreeNode {
	res := make([][]*TreeNode, n + 1)
	if n == 0 {
		return []*TreeNode{}
	}
	res[0] = []*TreeNode{ nil }
	for i := 1; i <= n; i++ {
		for j := 1; j <= i; j++ {
			for left := 0; left < len(res[j - 1]); left++ {
				for right := 0; right < len(res[i - j]); right++ {
					res[i] = append(res[i], &TreeNode{j, deepCopyTree(res[j-1][left], 0), deepCopyTree(res[i-j][right], j)})
				}
			}
		}
	}
	return res[n]
}

func deepCopyTree(src *TreeNode, offset int) *TreeNode {
	if src != nil {
		return &TreeNode{src.Val + offset, deepCopyTree(src.Left, offset), deepCopyTree(src.Right, offset)}
	}
	return nil
}
