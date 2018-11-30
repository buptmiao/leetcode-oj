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
	left, start, count, minwin := -1, 0, len(t), len(s)
	sb, tb := []byte(s), []byte(t)
	circle, tmap := make([]int, 128), make([]int, 128)
	for _, c := range tb {
		tmap[c] += 1
	}
	for i, v := range sb {
		if tmap[v] == 0 {
			continue
		}
		if left == -1 {
			left, start = i, i
		}
		if tmap[v] > circle[v] {
			count -= 1
		}
		circle[v] += 1
		if count == 0 {
			minwin = i - left + 1
			start = left
			count = -1
		}
		if circle[v] > tmap[v] && v == sb[left] {
			circle[v] -= 1
			for j := left+1; j <= i; j++ {
				u := sb[j]
				if tmap[u] == 0 {
					continue
				}
				if u == v || circle[u] <= tmap[u] {
					left = j
					if count == -1 && i - j + 1 < minwin {
						minwin = i - j + 1
						start = j
					}
					break
				} else {
					circle[u] -= 1
				}
			}
		}
	}
	if count == -1 {
		return string(sb[start:start + minwin])
	}
	return ""
}
