/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ret;
		size_t i,minlen = 0xFFFFFFFF,size = strs.size();
		if(size == 0) return ret;
		for(i = size;i>0;i--) //先找到最小长度
		{
			if(strs[i-1].size() < minlen)
				minlen = strs[i-1].size();
		} 
		for(size_t j=0;j<minlen;j++)
		{
			char c = strs[0][j];
			for(i = 1;i < size;i++)
			{
				if(strs[i][j] != c)
					return ret;
			}
			ret.append(1,c);
		}
		return ret;
    }
};