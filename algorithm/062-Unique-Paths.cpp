/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        dp[m][n-1] = 1;
        for(int i = m-1;i>=0;i--)
        	for(int j = n-1;j>=0;j--){ 
        		dp[i][j] = dp[i+1][j]+dp[i][j+1];
        	}
        return dp[0][0];
    }
};