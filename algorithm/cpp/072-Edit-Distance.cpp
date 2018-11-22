/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(),len2 = word2.size();
		vector<vector<int> > dp(len1+1,vector<int>(len2+1,0));
		for(int i = len1-1;i>=0;i--)  //初始化
			dp[i][len2] = len1-i;
		for(int j = len2-1;j>=0;j--)  //初始化
			dp[len1][j] = len2-j;
		for(int i = len1-1;i>=0;i--)
			for(int j = len2-1;j>=0;j--){
				if(word1[i] == word2[j]) dp[i][j] = dp[i+1][j+1];
				else{
					int temp = min(dp[i+1][j],dp[i][j+1]);
					dp[i][j] = min(dp[i+1][j+1],temp)+1;
				} 
			}
		return dp[0][0];
    }
};
