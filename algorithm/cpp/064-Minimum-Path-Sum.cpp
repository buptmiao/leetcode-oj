/**

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*/
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
		int n = grid[0].size();
        vector<vector<int> >  dp(m+1,vector<int>(n+1,INT_MAX));
		dp[m-1][n] = 0;
		for(auto i = m-1;i >= 0;i--)
			for(auto j = n - 1;j>=0;j--)
				dp[i][j] = grid[i][j] + min(dp[i+1][j],dp[i][j+1]);
		return dp[0][0];
    }
};
