/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 */

func numDecodings(s string) int {
	if s == "" || s[0] == 48 {
		return 0
	}
	before, last := 1, 1
	for i := 1; i < len(s); i++ {
		if s[i] == 48 {
			if s[i-1] > 50 || s[i-1] < 49 {
				return 0
			}
			last = before
			before = 0
		}
		cur := last
		// s[i-1] equals '1' or s[i-1 ~ i] equals "2X" (X <= 6)
		if s[i-1] == 49 || s[i-1] == 50 && s[i] <= 54 {
			cur += before
		}
		before = last
		last = cur

	}
	return last
}
