/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n,vector<int>(n));
		int num = 1;
		for(int i = 0;i < n/2;i++){ //圈数
			for(int j = i;j < n-i-1 ;j++) 
				matrix[i][j] = num++;
			for(int j = i;j < n-i-1 ;j++)
				matrix[j][n-1-i] = num++;
			for(int j = i;j < n-i-1 ;j++)
				matrix[n-1-i][n-1-j]=num++;
			for(int j = i;j < n-i-1 ;j++)
				matrix[n-1-j][i] = num++;
		}
		if(n%2)
			matrix[n/2][n/2] = num;
		return matrix;
    }
};
