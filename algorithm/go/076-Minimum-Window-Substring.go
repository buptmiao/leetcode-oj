/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

*/
func minWindow(s string, t string) string {
	left, start, count, minwin := 0, 0, len(t), len(s) + 1
	sb, tb := []byte(s), []byte(t)
	tmap := make([]int, 128)
	for _, c := range tb {
		tmap[c] += 1
	}
	for i, v := range sb {
		if tmap[v] > 0 {
			count -= 1
		}
		tmap[v] -= 1
		for count == 0 {
			if i - left + 1 < minwin {
				minwin = i - left + 1
				start = left
			}
			if tmap[sb[left]] == 0 {
				count += 1
			}
			tmap[sb[left]] += 1
			left += 1
		}

	}
	if minwin == len(s) + 1 {
		return ""
	}
	return string(sb[start:start + minwin])
}
