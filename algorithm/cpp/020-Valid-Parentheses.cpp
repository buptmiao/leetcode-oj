/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/
class Solution {
public:
    bool isValid(string s) {
        stack<char>  S;
		for(size_t i = 0;i<s.size();i++)
		{
			if(!S.empty() && (s[i] - S.top() == 1 || s[i] - S.top() == 2)) S.pop();
			else S.push(s[i]);
		}
		return S.empty();
    }
};