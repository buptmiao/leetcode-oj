/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false
 */
func isScramble(s1 string, s2 string) bool {
	length := len(s1)
	chars := make([]int, 128)
	for i := 0; i < length; i++ {
		chars[s1[i]]++
		chars[s2[i]]--
	}

	for _, c := range chars {
		if c != 0 {
			return false
		}
	}

	if length <= 3 {
		return true
	}

	for i := 1; i < length; i++ {
		if isScramble(s1[:i], s2[:i]) && isScramble(s1[i:], s2[i:]) {
			return true
		}
		if isScramble(s1[:i], s2[length - i:]) && isScramble(s1[i:], s2[:length - i]) {
			return true
		}
	}
	return false
}
