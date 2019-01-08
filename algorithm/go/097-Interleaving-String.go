/**
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
 */

func isInterleave(s1 string, s2 string, s3 string) bool {
	if len(s1) + len(s2) != len(s3) {
		return false
	}
	len1, len2 := len(s1), len(s2)
	dp := make([]bool, len2 + 1)
	dp[len2] = true

	for j := len2 - 1; j >= 0; j-- {
		dp[j] = (s2[j] == s3[len1 + j] && dp[j + 1])
	}
	for i := len1 - 1; i >= 0; i-- {
		dp[len2] = (s1[i] == s3[len2 + i] && dp[len2])
		for j := len2 - 1; j >= 0; j-- {
			dp[j] = dp[j] && s1[i] == s3[i + j] || dp[j + 1] && s2[j] == s3[i + j]
		}
	}
	return dp[0]
}
