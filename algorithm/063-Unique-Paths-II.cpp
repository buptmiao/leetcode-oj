/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    	int m = obstacleGrid.size();
    	int n = obstacleGrid[0].size();
        vector<vector<int> > dp(m+1,vector<int>(n+1));
        dp[m][n-1] = 1;
        for(int i = m-1;i>=0;i--)
        	for(int j = n-1;j>=0;j--)
        		if(obstacleGrid[i][j] == 0)
        			dp[i][j] = dp[i+1][j]+dp[i][j+1];
        return dp[0][0];
    }
};