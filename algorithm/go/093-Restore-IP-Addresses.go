/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
 */
func restoreIpAddresses(s string) []string {
	arr := make([][]string, 0, 10)
	can := make([]string, 4)
	backtrace(&arr, &can, "", 0, 0, s)
	res := make([]string, 0, len(arr))
	for _, v := range arr {
		res = append(res, strings.Join(v, "."))
	}
	return res
}

func toInt(s string) int {
	res, err := strconv.Atoi(s)
	if err != nil {
		return 0
	}
	return res
}

func backtrace(arr *[][]string, can *[]string, cur string, arrIndex, strIndex int, s string) {
	if arrIndex == 4 {
		if strIndex == len(s) {
			*arr = append(*arr, append([]string{}, (*can)...))
		} else {
			return
		}
	} else {
		for i := strIndex; cur != "0" && i < len(s) && toInt(cur + s[i:i + 1]) <= 255; i++ {
			cur += s[i:i + 1]
			(*can)[arrIndex] = cur
			backtrace(arr, can, "", arrIndex + 1, i + 1, s)
		}
	}
}
