/*

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int slen = strlen(s);
        int plen = strlen(p);
        vector<vector<bool> > dp(slen+1,vector<bool>(plen+1,false));
        dp[slen][plen] = true;
        for(int j = plen-1;j>=0;j--)
        	if(p[j+1]=='*')
        		dp[slen][j] = dp[slen][j+2];
        for(int j = plen-1;j>=0;j--){ 
        	if(p[j] == '*') continue;
        	for(int i = slen-1;i>=0;i--){ 
        		if(p[j+1] != '*')
        			dp[i][j] = (s[i] == p[j] || p[j] == '.') ? dp[i+1][j+1] : false;
        		else if(dp[i][j+2])
        			dp[i][j] = dp[i][j+2];
        		else
        			dp[i][j] = (s[i] == p[j] || p[j] == '.') ? dp[i+1][j] : false;
        	}
        }
        return dp[0][0];
    }
};