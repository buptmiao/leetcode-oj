/*
Given a string, find the length of the longest substring without repeating characters.
 For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
 which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

 class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,size_t> map1;
		size_t i,k, num = 0;
		int j,m = 0;
		for(i = 0,j = 0; i < s.size(); i++)
		{
			if(map1.find(s[i]) != map1.end())
			{
				num = max(num,map1.size());
				k = map1[s[i]]; //找到s[i]上次出现的位置
				for(j = k; j>=m;j--) //上次清除之后的首位置m到本次s[i]出现的位置之间的元素清除
					map1.erase(s[j]);
				m = k+1; //m表示上次清除之后的首位置
			}
			map1[s[i]] = i;
		}
		num = max(num,map1.size());
		return num;
    }
};